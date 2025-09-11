#!/bin/bash

echo "Starting WordPress setup..."

# Create necessary directories and set permissions
mkdir -p /var/www/html
mkdir -p /run/php
chown -R www-data:www-data /var/www/html
chmod -R 755 /var/www/html

# Install WP-CLI if not already present
if [ ! -f /usr/local/bin/wp ]; then
    echo "Installing WordPress CLI..."
    wget -O wp-cli.phar https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x wp-cli.phar
    mv wp-cli.phar /usr/local/bin/wp
    echo "WordPress CLI installed."
else
    echo "WordPress CLI already installed."
fi

# Check if WordPress is already configured
if [ ! -f /var/www/html/wp-config.php ]; then
    echo "WordPress not configured, starting setup..."
    
    # Download WordPress core files
    echo "Downloading WordPress core files..."
    wp core download --path=/var/www/html --allow-root
    echo "WordPress downloaded."
    
    # Wait for MariaDB to be ready
    echo "Waiting for MariaDB to be ready..."
    until mysqladmin -h"${DB_HOST}" -u"${DB_USER}" -p"${DB_PASSWORD}" ping --silent; do
        echo "MariaDB is unavailable - waiting.."
        sleep 2
    done
    
    # Create wp-config.php
    echo "Creating WordPress configuration..."
    wp config create \
        --path=/var/www/html \
        --dbhost="${DB_HOST}" \
        --dbname="${DB_NAME}" \
        --dbuser="${DB_USER}" \
        --dbpass="${DB_PASSWORD}" \
        --allow-root
	echo "Wordpress configuration created!"
    
    # Install WordPress
    echo "Installing WordPress..."
    wp core install \
        --path=/var/www/html \
        --url="https://${DOMAIN_NAME}/" \
        --title="Inception, we must go deeper" \
        --admin_user="${WP_ADMIN}" \
        --admin_password="${WP_ADMIN_PASSWORD}" \
        --admin_email="${WP_ADMIN_EMAIL}" \
        --skip-email \
        --allow-root
	echo "Wordpress admin user created!"

   # Ensure HTTPS configuration is set
    echo "Configuring HTTPS settings..."
    wp config set FORCE_SSL_ADMIN true --path=/var/www/html --allow-root
    wp option update home "https://${DOMAIN_NAME}" --path=/var/www/html --allow-root
    wp option update siteurl "https://${DOMAIN_NAME}" --path=/var/www/html --allow-root
    echo "HTTPS configuration completed!"

    # Create additional WordPress user
    echo "Creating additional WordPress user..."
    wp user create "${WP_USER}" "${WP_USER_EMAIL}" \
        --path=/var/www/html \
        --user_pass="${WP_USER_PASSWORD}" \
        --role="editor" \
        --allow-root
	echo "Wordpress user created!"
    
    echo "WordPress setup complete!"
else
    echo "WordPress is already configured."
fi

# Ensure HTTPS is configured even for existing installations
echo "Ensuring HTTPS configuration..."
wp config set FORCE_SSL_ADMIN true --path=/var/www/html --allow-root
wp option update home "https://${DOMAIN_NAME}" --path=/var/www/html --allow-root
wp option update siteurl "https://${DOMAIN_NAME}" --path=/var/www/html --allow-root
echo "HTTPS configuration verified!"

# Set final permissions
chown -R www-data:www-data /var/www/html
chmod -R 755 /var/www/html

# Configure PHP-FPM to listen on TCP port 9000
sed -i 's/listen = \/run\/php\/php8.2-fpm.sock/listen = 9000/' /etc/php/8.2/fpm/pool.d/www.conf

# Start PHP-FPM
exec /usr/sbin/php-fpm8.2 -F
