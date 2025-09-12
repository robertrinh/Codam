# Debian bookworm is the penultimate version (Debian 12)
FROM debian:bookworm

# update and install package manager
RUN apt-get update -y && \
	apt-get install -y --no-install-recommends \
	apt-utils \
	php8.2 \
	php-fpm \
	php-mysql \
	mariadb-client \
	wget \
	curl \
	ca-certificates \
	&& rm -rf /var/lib/apt/lists/* \
	&& apt-get clean

# Create directory for wordpress
RUN mkdir -p /run/php

# Copy configuration files to proper locations
COPY ./tools/script-wp.sh /script-wp.sh

# Make script executable
RUN chmod +x /script-wp.sh

# Expost PHP-FPM port
EXPOSE 9000

# Start PHP-FPM directly
CMD ["/script-wp.sh"]