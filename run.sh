#!/bin/bash
if [ "$ALLOW_OVERRIDE" = "**False**" ]; then
    unset ALLOW_OVERRIDE
else
    sed -i "s/AllowOverride None/AllowOverride All/g" /etc/apache2/apache2.conf
    a2enmod rewrite
fi

sed -i "s/__APPLICATION_NAME__/$APPLICATION_NAME/g" /webdir/crm/data/site_config.inc
sed -i "s/__LOCATION_NAME__/$LOCATION_NAME/g" /webdir/crm/data/site_config.inc
sed -i "s^__BASE_URL__^$BASE_URL^g" /webdir/crm/data/site_config.inc
sed -i "s^__BASE_URI__^$BASE_URI^g" /webdir/crm/data/site_config.inc
sed -i "s/__ADMINISTRATOR_NAME__/$ADMINISTRATOR_NAME/g" /webdir/crm/data/site_config.inc
sed -i "s/__ADMINISTRATOR_EMAIL__/$ADMINISTRATOR_EMAIL/g" /webdir/crm/data/site_config.inc
sed -i "s^__DB_HOST__^$DB_HOST^g" /webdir/crm/data/site_config.inc
sed -i "s/__DB_NAME__/$DB_NAME/g" /webdir/crm/data/site_config.inc
sed -i "s/__DB_USER__/$DB_USER/g" /webdir/crm/data/site_config.inc
sed -i "s/__DB_PASS__/$DB_PASS/g" /webdir/crm/data/site_config.inc
sed -i "s^__DATE_FORMAT__^$DATE_FORMAT^g" /webdir/crm/data/site_config.inc
sed -i "s/__NOTIFICATIONS_ENABLED__/$NOTIFICATIONS_ENABLED/g" /webdir/crm/data/site_config.inc
sed -i "s/__SOLR_SERVER_HOSTNAME__/$SOLR_SERVER_HOSTNAME/g" /webdir/crm/data/site_config.inc
sed -i "s/__SOLR_SERVER_PORT__/$SOLR_SERVER_PORT/g" /webdir/crm/data/site_config.inc
sed -i "s^__SOLR_SERVER_PATH__^$SOLR_SERVER_PATH^g" /webdir/crm/data/site_config.inc
sed -i "s/__DEFAULT_CITY__/$DEFAULT_CITY/g" /webdir/crm/data/site_config.inc
sed -i "s/__DEFAULT_STATE__/$DEFAULT_STATE/g" /webdir/crm/data/site_config.inc
sed -i "s/__OPEN311_JURISDICTION__/$OPEN311_JURISDICTION/g" /webdir/crm/data/site_config.inc
sed -i "s^__OPEN311_KEY_SERVICE__^$OPEN311_KEY_SERVICE^g" /webdir/crm/data/site_config.inc
sed -i "s/__THUMBNAIL_SIZE__/$THUMBNAIL_SIZE/g" /webdir/crm/data/site_config.inc
sed -i "s/__CLOSING_COMMENT_REQUIRED_LENGTH__/$CLOSING_COMMENT_REQUIRED_LENGTH/g" /webdir/crm/data/site_config.inc
sed -i "s/__AUTO_CLOSE_COMMENT__/$AUTO_CLOSE_COMMENT/g" /webdir/crm/data/site_config.inc
sed -i "s/__LOCALE__/$LOCALE/g" /webdir/crm/data/site_config.inc

chown www-data:www-data /webdir/crm -R
rm /etc/apache2/sites-enabled/000-default.conf
ln -s /etc/apache2/sites-available/default /etc/apache2/sites-enabled/000-default.conf
source /etc/apache2/envvars
a2enmod rewrite
tail -F /var/log/apache2/* &
exec apache2 -D FOREGROUND
