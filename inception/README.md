# *This project has been created as part of the 42 curriculum by gkankia.*

# Inception

## Description

Inception is a system administration and containerization project. The objective is to build a small infrastructure composed of multiple services running in isolated Docker containers and orchestrated with Docker Compose.

The infrastructure includes:

* NGINX configured with TLSv1.2/TLSv1.3 as the single entry point.
* WordPress running with PHP-FPM.
* MariaDB as the database server.
* Persistent storage using Docker volumes.
* A dedicated Docker network for inter-container communication.

The goal of the project is to understand containerization concepts, service isolation, networking, persistent storage, and secure deployment practices.

---

## Project Architecture

The infrastructure is composed of three containers:

### NGINX

* Acts as the only public entry point.
* Exposes port 443.
* Handles HTTPS connections using TLS.
* Forwards PHP requests to the WordPress container.

### WordPress + PHP-FPM

* Hosts the WordPress application.
* Runs PHP-FPM on port 9000.
* Connects to MariaDB through the Docker network.

### MariaDB

* Stores WordPress data.
* Creates the WordPress database and user during initialization.
* Uses persistent storage to preserve data across container restarts.

### Volumes

Two Docker volumes are used:

* MariaDB data volume
* WordPress files volume

The data is stored on the host machine inside:

```text
/home/gkankia/data/mariadb
/home/gkankia/data/wordpress
```

### Network

A dedicated Docker bridge network is used to allow secure communication between:

```text
nginx <-> wordpress <-> mariadb
```

No host networking, links, or legacy networking mechanisms are used.

---


## Instructions

### Requirements

* Linux environment (Debian recommended)
* Docker
* Docker Compose


### Configure the environment

Edit the `.env` file:

```bash
nano srcs/.env
```

### Configure the domain

Add the following line to `/etc/hosts`:

```text
127.0.0.1 gkankia.42.fr
```

### Build and start the infrastructure

```bash
make
```

### Stop the infrastructure

```bash
make down
```

### Remove containers and volumes

```bash
make clean
```

---

## Design Choices

### Why Docker?

Docker provides lightweight isolated environments that package an application together with its dependencies.

Advantages:

* Reproducible environments
* Fast deployment
* Resource efficiency
* Service isolation

---

## Virtual Machines vs Docker

### Virtual Machines

* Include a complete guest operating system.
* Require more CPU, RAM, and disk space.
* Slower startup time.
* Stronger isolation.

### Docker Containers

* Share the host kernel.
* Lightweight.
* Start almost instantly.
* Consume fewer resources.

For this project Docker is preferred because it allows multiple services to run efficiently while remaining isolated.

---

## Secrets vs Environment Variables

### Environment Variables

Advantages:

* Easy to configure.
* Convenient for development.
* Supported directly by Docker Compose.

Disadvantages:

* Visible through container inspection.
* Less secure for sensitive credentials.

### Docker Secrets

Advantages:

* Better security.
* Credentials are not exposed as environment variables.

Disadvantages:

* Slightly more complex setup.

---

## Docker Network vs Host Network

### Host Network

Advantages:

* Direct access to host networking.

Disadvantages:

* Reduced isolation.
* Potential port conflicts.
* Less secure.

### Docker Network

Advantages:

* Service isolation.
* Built-in DNS resolution.
* Better security.
* Easier container communication.

A dedicated Docker bridge network is used in this project.

---

## Docker Volumes vs Bind Mounts

### Bind Mounts

Advantages:

* Direct access to host files.

Disadvantages:

* Strong dependency on host filesystem layout.
* More difficult to manage portability.

### Docker Volumes

Advantages:

* Managed by Docker.
* Easier backups and migration.
* Better integration with containers.

The project uses Docker named volumes to satisfy the subject requirements.

---

## Security Considerations

* Only HTTPS traffic is allowed.
* TLSv1.2 and TLSv1.3 are enabled.
* NGINX is the only exposed service.
* MariaDB is not accessible from outside the Docker network.
* WordPress communicates with MariaDB only through the internal Docker network.

---


## Resources

### Official Documentation

* Docker Documentation — https://docs.docker.com/
* Docker Compose Documentation — https://docs.docker.com/compose/
* NGINX Documentation — https://nginx.org/en/docs/
* MariaDB Documentation — https://mariadb.com/kb/en/documentation/
* WordPress Documentation — https://wordpress.org/documentation/
* PHP-FPM Documentation — https://www.php.net/manual/en/install.fpm.php

### Tutorials and References

* Docker Getting Started Guide
* NGINX Beginner's Guide
* MariaDB Server Documentation
* WordPress Developer Resources
* 42 Inception Subject

---

## AI Usage

Artificial Intelligence tools were used as learning and documentation assistants during the development of this project.

AI was used for:

* Understanding Docker concepts.
* Learning Docker Compose syntax.
* Researching PHP-FPM and NGINX configuration.
* Understanding MariaDB initialization procedures.
* Reviewing scripts and configuration files.
* Improving documentation quality.


---

## Author

gkankiya

42 School

