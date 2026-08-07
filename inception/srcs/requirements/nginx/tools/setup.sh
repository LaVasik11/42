#!/bin/bash

mkdir -p /etc/nginx/ssl

openssl req -x509 \
	-nodes \
	-days 365 \
	-newkey rsa:2048 \
	-keyout /etc/nginx/ssl/inception.key \
	-out /etc/nginx/ssl/inception.crt \
	-subj "/C=GE/ST=Tbilisi/L=Tbilisi/O=42/OU=42/CN=gkankia.42.fr"

exec nginx -g "daemon off;"
