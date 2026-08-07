# USER_DOC.md

# User Documentation

## Overview

This project provides a complete WordPress infrastructure running inside Docker containers.

The stack contains the following services:

| Service             | Description                        |
| ------------------- | ---------------------------------- |
| NGINX               | HTTPS web server and reverse proxy |
| WordPress + PHP-FPM | Website application                |
| MariaDB             | Database server                    |

NGINX is the only service exposed to the outside world through HTTPS (port 443).

---

# Starting the Project

From the root of the repository:

```bash
make
```

The first launch may take a few minutes because the images must be built.

---

# Stopping the Project

Stop all containers:

```bash
make down
```

---

# Accessing the Website

Open a browser and navigate to:

```text
https://<login>.42.fr
```

Because a self-signed certificate is used, the browser may display a security warning. Accept the warning and continue to the website.

---

# Accessing the Administration Panel

Open:

```text
https://<login>.42.fr/wp-admin
```

Login using the administrator credentials defined in the `.env` file.

---

# Credentials Management

Project credentials are stored inside:

```text
srcs/.env
```

The file contains:

* Database credentials
* WordPress administrator credentials
* WordPress user credentials
* Domain configuration

Only authorized administrators should modify these values.

After changing credentials, rebuild the infrastructure:

```bash
docker compose -f srcs/docker-compose.yml down
docker compose -f srcs/docker-compose.yml up --build -d
```

---

# Checking Service Status

Display running containers:

```bash
docker ps
```

Expected containers:

```text
mariadb
wordpress
nginx
```

---

# Viewing Logs

NGINX:

```bash
docker logs nginx
```

WordPress:

```bash
docker logs wordpress
```

MariaDB:

```bash
docker logs mariadb
```

---

# Verifying HTTPS

Check the TLS connection:

```bash
openssl s_client -connect localhost:443
```

The output should indicate TLSv1.2 or TLSv1.3.

---

# Restarting Services

Restart all services:

```bash
docker compose -f srcs/docker-compose.yml restart
```

Restart a specific service:

```bash
docker restart nginx
docker restart wordpress
docker restart mariadb
```
