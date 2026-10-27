#!/bin/bash

set -e

DB_PASSWORD=$(cat /run/secrets/db_password)
MYSQL_DATABASE=$(sed -n 's/^MYSQL_DATABASE=//p' /run/secrets/db_credentials)
MYSQL_USER=$(sed -n 's/^MYSQL_USER=//p' /run/secrets/db_credentials)

WP_ADMIN_USER=$(sed -n 's/^WP_ADMIN_USER=//p' /run/secrets/credentials)
WP_ADMIN_PASSWORD=$(sed -n 's/^WP_ADMIN_PASSWORD=//p' /run/secrets/credentials)
WP_ADMIN_EMAIL=$(sed -n 's/^WP_ADMIN_EMAIL=//p' /run/secrets/credentials)
WP_USER=$(sed -n 's/^WP_USER=//p' /run/secrets/credentials)
WP_USER_PASSWORD=$(sed -n 's/^WP_USER_PASSWORD=//p' /run/secrets/credentials)
WP_USER_EMAIL=$(sed -n 's/^WP_USER_EMAIL=//p' /run/secrets/credentials)

if [ -z "$DB_PASSWORD" ] || [ -z "$MYSQL_DATABASE" ] || [ -z "$MYSQL_USER" ] || [ -z "$WP_ADMIN_USER" ] || [ -z "$WP_ADMIN_PASSWORD" ] || [ -z "$WP_ADMIN_EMAIL" ] || [ -z "$WP_USER" ] || [ -z "$WP_USER_PASSWORD" ] || [ -z "$WP_USER_EMAIL" ] || [ -z "$DOMAIN_NAME" ] || [ -z "$WP_TITLE" ]; then
    echo "Error: required configuration or secrets are missing"
    exit 1
fi

until mysql \
    -hmariadb \
    -u"$MYSQL_USER" \
    -p"$DB_PASSWORD" \
    -e "SELECT 1" >/dev/null 2>&1
do
    sleep 1
done

mkdir -p /var/www/html

cd /var/www/html

if [ ! -f wp-config.php ]; then
    wp core download --allow-root

    wp config create \
        --dbname="$MYSQL_DATABASE" \
        --dbuser="$MYSQL_USER" \
        --dbpass="$DB_PASSWORD" \
        --dbhost="mariadb:3306" \
        --allow-root

    wp core install \
        --url="$DOMAIN_NAME" \
        --title="$WP_TITLE" \
        --admin_user="$WP_ADMIN_USER" \
        --admin_password="$WP_ADMIN_PASSWORD" \
        --admin_email="$WP_ADMIN_EMAIL" \
        --skip-email \
        --allow-root

    wp user create \
        "$WP_USER" \
        "$WP_USER_EMAIL" \
        --user_pass="$WP_USER_PASSWORD" \
        --role=author \
        --allow-root
fi

if wp user get "$WP_ADMIN_USER" --field=ID --allow-root >/dev/null 2>&1; then
    wp user update "$WP_ADMIN_USER" \
        --user_pass="$WP_ADMIN_PASSWORD" \
        --user_email="$WP_ADMIN_EMAIL" \
        --role=administrator \
        --allow-root
else
    wp user create "$WP_ADMIN_USER" "$WP_ADMIN_EMAIL" \
        --user_pass="$WP_ADMIN_PASSWORD" \
        --role=administrator \
        --allow-root
fi

exec php-fpm8.2 -F
