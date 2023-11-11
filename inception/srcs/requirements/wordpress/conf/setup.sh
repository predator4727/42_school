#!/bin/sh
​
# installs the WordPress core files in the specified directory
wp --allow-root --path=/var/www core install \
  --url="$DOMAIN_NAME" \
  --title="Inception WP" \
  --admin_user="$WPADUSER" \
  --admin_password="$WPADPASS" \
  --admin_email="$WPADADDR"

wp user create "$WPUSER1" "$WPUSER1ADDR" \
  --role=author \
  --user_pass="$WPUSER1PASS" \
  --allow-root
​
wp --allow-root --path=/var/www option update blogname "Inception Project"
wp --allow-root --path=/var/www option update blogdescription "Inception WP"
# option to set the WordPress site to private mode (0 means private, 1 means public)
wp --allow-root --path=/var/www option update blog_public 0

wp theme install twentytwentyone --activate --allow-root

wp plugin update --all --allow-root

# starts the PHP-FPM (PHP process manager used to handle PHP scripts in a server environment)
/usr/sbin/php-fpm8 -F