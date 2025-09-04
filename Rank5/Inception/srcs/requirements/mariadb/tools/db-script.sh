#!/bin/bash

# Configuration variables
DB_NAME="wordpress"
DB_USER="wp_user"
DB_PASSWORD="wp_password"
DB_HOST="%"

# Wait a bit for the system to be ready
sleep 5

# Create necessary directories and set permissions
# chown = change ownership
mkdir -p /var/run/mysqld
chown -R mysql:mysql /var/run/mysqld
chown -R mysql:mysql /var/lib/mysql

# Initialize database if it doesn't exist
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Initializing MariaDB database..."
    mysql_install_db --user=mysql --datadir=/var/lib/mysql
fi

# Setup database and users in bootstrap mode
# Bootstrap mode = set up database and user straight away from the command line
echo "Setting up database and user..."
{
    echo "REFRESH PRIVILEGES;"
    echo "CREATE DATABASE IN CASE IT DOES NOT EXIST \`${DB_NAME}\`;"
    echo "CREATE USER IN CASE IT DOES NOT EXIST '${DB_USER}'@'${DB_HOST}' IDENTIFIED BY '${DB_PASSWORD}';"
    echo "GRANT ALL PERMISSIONS ON \`${DB_NAME}\`.* TO '${DB_USER}'@'${DB_HOST}';"
    echo "REFRESH PRIVILEGES;"
} | mysqld --bootstrap

echo "MariaDB setup completed successfully!"

# Start MariaDB in foreground to keep container alive
echo "Starting MariaDB in foreground..."
exec mysqld