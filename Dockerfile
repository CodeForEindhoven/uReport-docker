FROM ubuntu:trusty
MAINTAINER Milo van der Linden <milo@dogodigi.net>

# Install base packages
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get -yq install \
        curl \
        git \
        apache2 \
        libapache2-mod-php5 \
        php5-mysql \
        php5-mcrypt \
        php5-gd \
        php5-curl \
        php-pear \
        php-apc && \
    rm -rf /var/lib/apt/lists/* && \
RUN /usr/sbin/php5enmod mcrypt
RUN echo "ServerName localhost" >> /etc/apache2/apache2.conf && \
    sed -i "s/variables_order.*/variables_order = \"EGPCS\"/g" /etc/php5/apache2/php.ini

#Defaults, modify with environment variable to change
ENV ALLOW_OVERRIDE **False**
ENV MYSQL_DATABASE ureport

# Add image configuration and scripts
ADD run.sh /run.sh
RUN chmod 755 /*.sh

# Configure /webdir folder with sample app
RUN mkdir -p /webdir && rm -fr /var/www/html && ln -s /webdir /var/www/html
git clone https://github.com/City-of-Bloomington/uReport.git /webdir

EXPOSE 80
WORKDIR /webdir

CMD ["/run.sh"]
