#!/bin/bash

# checks if the directory "/home/${USER}/data" does not exist
if [ ! -d "/home/${USER}/data" ]; then
        mkdir ~/data
        mkdir ~/data/mariadb
        mkdir ~/data/wordpress
fi