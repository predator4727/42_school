FROM alpine:3.16

ARG DB_NAME \
    DB_USER \
    DB_PASS \
    DB_ROOT \
    MARIADB_PORT

RUN apk update && apk add --no-cache mariadb mariadb-client

# Creates a configuration file /etc/my.cnf.d/docker.cnf with specific options for MariaDB
RUN mkdir /var/run/mysqld; \
    chmod 777 /var/run/mysqld;
RUN { echo '[mysqld]'; echo 'skip-host-cache'; echo 'skip-name-resolve'; echo 'bind-address=0.0.0.0'; } | tee  /etc/my.cnf.d/docker.cnf;
    
# Enables network connections to the MariaDB server
RUN sed -i "s|skip-networking|skip-networking=0|g" /etc/my.cnf.d/mariadb-server.cnf

RUN mysql_install_db --user=mysql --datadir=/var/lib/mysql

EXPOSE ${MARIADB_PORT}

COPY requirements/mariadb/conf/create_db.sh .
RUN sh create_db.sh && rm create_db.sh
USER mysql
CMD ["/usr/bin/mysqld", "--skip-log-error"]