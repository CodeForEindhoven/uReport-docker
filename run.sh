#!/bin/bash
if [ "$ALLOW_OVERRIDE" = "**False**" ]; then
    unset ALLOW_OVERRIDE
else
    sed -i "s/AllowOverride None/AllowOverride All/g" /etc/apache2/apache2.conf
    a2enmod rewrite
fi
chown www-data:www-data /webdir -R
cp default /etc/apache2/sites-available/
ln -s /etc/apache2/sites-enabled/000-default /etc/apache2/sites-available/default
git submodule update -i



source /etc/apache2/envvars
tail -F /var/log/apache2/* &
exec apache2 -D FOREGROUND
