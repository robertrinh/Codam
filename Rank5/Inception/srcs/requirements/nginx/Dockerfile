# Debian bookworm is the latest stable version (Debian 12)
FROM debian:bookworm

# Set environment variables
ENV DOMAIN_NAME=${DOMAIN_NAME}

# Install & update NGINX packages
RUN apt-get update -y && \
	apt-get install -y --no-install-recommends \
	nginx \
	openssl \
	curl \
	&& rm -rf /var/lib/apt/lists/* \
	&& apt-get clean

# Create SSL directory and generate self-signed certificate
RUN mkdir -p /etc/nginx/ssl && \
	openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-keyout /etc/nginx/ssl/inception.key \
	-out /etc/nginx/ssl/inception.crt \
	-subj "/C=NL/ST=Holland/L=Amsterdam/O=CODAM/CN=qtrinh" && \
	chmod 600 /etc/nginx/ssl/inception.key && \
	chmod 644 /etc/nginx/ssl/inception.crt

# Create necessary directories (WordPress will populate the content)
RUN mkdir -p /var/www/html

# TEST: Create necessary directories and test file
# RUN mkdir -p /var/www/html && \
#     echo '<!DOCTYPE html>' > /var/www/html/index.html && \
#     echo '<html>' >> /var/www/html/index.html && \
#     echo '<head>' >> /var/www/html/index.html && \
#     echo '    <title>Nginx Test Page</title>' >> /var/www/html/index.html && \
#     echo '</head>' >> /var/www/html/index.html && \
#     echo '<body>' >> /var/www/html/index.html && \
#     echo '    <h1>🎉 Nginx is working!</h1>' >> /var/www/html/index.html && \
#     echo '    <p>SSL connection successful</p>' >> /var/www/html/index.html && \
#     echo '    <p>Container: nginx</p>' >> /var/www/html/index.html && \
#     echo '    <p>Time: $(date)</p>' >> /var/www/html/index.html && \
#     echo '</body>' >> /var/www/html/index.html && \
#     echo '</html>' >> /var/www/html/index.html

# Copy configuration files to proper locations
COPY ./conf/config-nginx.conf /etc/nginx/nginx.conf

# Expose NGINX port for HTTPS
EXPOSE 443

# Start NGINX directly
# -g = global configuration
# daemon off = keeps NGINX running in foreground
CMD ["nginx", "-g", "daemon off;"]