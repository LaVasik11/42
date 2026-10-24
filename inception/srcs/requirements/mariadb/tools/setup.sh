#!/bin/bash

set -e

mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld
chown -R mysql:mysql /var/lib/mysql

DB_PASSWORD=$(cat /run/secrets/db_password)
DB_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)
MYSQL_DATABASE=$(sed -n 's/^MYSQL_DATABASE=//p' /run/secrets/db_credentials)
MYSQL_USER=$(sed -n 's/^MYSQL_USER=//p' /run/secrets/db_credentials)

if [ -z "$DB_PASSWORD" ] || [ -z "$DB_ROOT_PASSWORD" ] || [ -z "$MYSQL_DATABASE" ] || [ -z "$MYSQL_USER" ]; then
    echo "Error: required database secrets are missing"
    exit 1
fi


if [ ! -d "/var/lib/mysql/mysql" ]; then
    mysqld --initialize-insecure --user=mysql --datadir=/var/lib/mysql

    mysqld --user=mysql --datadir=/var/lib/mysql --skip-networking &
    pid="$!"

    until mysqladmin ping --silent; do
        if ! kill -0 "$pid" 2>/dev/null; then
            echo "Error: MariaDB failed to start"
            exit 1
        fi
        sleep 1
    done

    mysql -u root <<EOF
ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;
EOF

    mysqladmin -u root -p"${DB_ROOT_PASSWORD}" shutdown

    wait "$pid" || true
fi

exec mysqld --user=mysql --bind-address=0.0.0.0 --datadir=/var/lib/mysql
