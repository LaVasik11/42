FROM debian:12

RUN apt update && \
    apt install -y nginx openssl && \
    apt clean

COPY conf/nginx.conf /etc/nginx/nginx.conf

COPY tools/setup.sh /setup.sh

RUN chmod +x /setup.sh

ENTRYPOINT ["/setup.sh"]
