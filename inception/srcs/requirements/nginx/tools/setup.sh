#!/bin/bash

set -e

mkdir -p /etc/nginx/ssl

if [ -z "$DOMAIN_NAME" ]; then
    echo "Error: DOMAIN_NAME is not set"
    exit 1
fi

openssl req -x509 \
    -nodes \
    -days 365 \
    -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/inception.key \
    -out /etc/nginx/ssl/inception.crt \
    -subj "/C=GE/ST=Tbilisi/L=Tbilisi/O=42/OU=42/CN=${DOMAIN_NAME}" \
    -addext "subjectAltName=DNS:${DOMAIN_NAME}"

envsubst '${DOMAIN_NAME}' \
    < /etc/nginx/templates/default.conf.template \
    > /etc/nginx/conf.d/default.conf

nginx -t

exec nginx -g "daemon off;"

