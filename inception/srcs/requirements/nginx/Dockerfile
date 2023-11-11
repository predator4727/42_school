FROM alpine:3.16

ARG CERT_PATH \
    KEY_PATH \
    CERT \
    KEY \
    DOMAIN_NAME \
    NGINX_PORT \
    WORDPRESS_PORT

RUN apk update && apk upgrade && apk add --no-cache nginx gettext

# Copy Nginx configuration file
COPY ./requirements/nginx/conf/nginx.conf /etc/nginx/http.d/nginx.template.conf

# Update package repositories and install necessary utilities
RUN apk update && apk add --no-cache wget curl openssl

WORKDIR /etc/nginx/ssl

# Generate SSL key and certificate
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout ${KEY} -out ${CERT} \
    -subj "/C=US/ST=State/L=City/O=Organization/OU=Department/CN=example.com"

# Substitute environment variables in the Nginx configuration template
RUN envsubst '$$CERT_PATH $$KEY_PATH $$DOMAIN_NAME $$NGINX_PORT $$WORDPRESS_PORT' < /etc/nginx/http.d/nginx.template.conf > /etc/nginx/http.d/nginx.conf

# Remove the Nginx configuration template
RUN rm /etc/nginx/http.d/nginx.template.conf

WORKDIR /

# Set file permissions to readable
RUN chmod 644 /etc/nginx/http.d/nginx.conf

# Set file permissions for SSL keys
RUN chmod 600 ${CERT_PATH}
RUN chmod 600 ${KEY_PATH}

# Set ownership to the Nginx user and group
RUN chown -R nginx:nginx /etc/nginx/http.d /etc/nginx/ssl

EXPOSE ${NGINX_PORT}

# Start NGINX in the foreground when the container starts
CMD ["nginx", "-g", "daemon off;"]