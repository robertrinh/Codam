# Debian bookworm is the latest stable version (Debian 12)
FROM debian:bookworm

# Install & Update MariaDB packages
RUN apt-get update -y && \
	apt-get install -y --no-install-recommends \
	mariadb-server \
	mariadb-client \
	curl \
	&& rm -rf /var/lib/apt/lists/* \
	&& apt-get clean

# Copy configuration files to proper locations
COPY ./conf/db-config.conf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY ./tools/db-script.sh /db-script.sh

# Make script executable
RUN chmod +x /db-script.sh

# Expose MariaDB port (internal container communication)
EXPOSE 3306

# ENTRYPOINT handles init database (always runs)
ENTRYPOINT ["sh", "/db-script.sh"]

# CMD provides default command after init (only runs if no command is provided)
CMD ["mysqld", "--user=mysql", "--console"]

