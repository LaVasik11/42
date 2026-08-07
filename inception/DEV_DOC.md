# DEV_DOC.md

# Developer Documentation

## Project Overview

This project implements a Docker-based infrastructure composed of three services:

* NGINX
* WordPress + PHP-FPM
* MariaDB

Docker Compose is used to orchestrate the containers and their network.

---

# Prerequisites

The following software must be installed:

* Docker
* Docker Compose
* GNU Make

Verify the installation:

```bash
docker --version
docker compose version
make --version
```

---

# Environment Configuration

Edit the file:

```text
srcs/.env
```

---

# Host Configuration

Create persistent storage directories:

```bash
mkdir -p /home/gkankia/data/mariadb
mkdir -p /home/gkankia/data/wordpress
```

Add the domain to `/etc/hosts`:

```text
127.0.0.1 gkankia.42.fr
```

Replace `gkankia` with the actual login used by the project.

---

# Building the Project

Build and start:

```bash
make
```

Equivalent Docker Compose command:

```bash
docker compose -f srcs/docker-compose.yml up --build -d
```

---

# Stopping the Project

```bash
make down
```

---

# Rebuilding the Infrastructure

```bash
docker compose -f srcs/docker-compose.yml down
docker compose -f srcs/docker-compose.yml up --build -d
```

---

# Container Management

Display running containers:

```bash
docker ps
```

Open a shell inside a container:

```bash
docker exec -it nginx bash
docker exec -it wordpress bash
docker exec -it mariadb bash
```

Inspect container details:

```bash
docker inspect nginx
docker inspect wordpress
docker inspect mariadb
```

---

# Volume Management

List volumes:

```bash
docker volume ls
```

Inspect volumes:

```bash
docker volume inspect srcs_mariadb
docker volume inspect srcs_wordpress
```

Remove volumes:

```bash
docker compose -f srcs/docker-compose.yml down -v
```

---

# Data Persistence

MariaDB data:

```text
/home/gkankia/data/mariadb
```

WordPress files:

```text
/home/gkankia/data/wordpress
```

These directories are mounted into Docker named volumes and remain available after container restarts or recreation.

---

# Network Management

List networks:

```bash
docker network ls
```

Inspect the project network:

```bash
docker network inspect inception
```

The network allows communication between:

```text
nginx
wordpress
mariadb
```

without exposing internal services externally.

---

# Debugging

Container logs:

```bash
docker logs nginx
docker logs wordpress
docker logs mariadb
```

Check processes:

```bash
docker exec nginx ps aux
docker exec wordpress ps aux
docker exec mariadb ps aux
```

Check open ports:

```bash
docker exec wordpress ss -lntp
docker exec mariadb ss -lntp
docker exec nginx ss -lntp
```

---

# Useful Commands

Show container status:

```bash
docker ps
```

Restart a service:

```bash
docker restart nginx
```

Remove unused resources:

```bash
docker system prune
```

Show Docker disk usage:

```bash
docker system df
```
