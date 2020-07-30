#!/bin/sh
rm -rf /tmp/topautocam.tar.gz
tar cvfz /tmp/topautocam.tar.gz  ../config/  ../db/  ../lib/ ../plugin/  ../public/  ../sql/ ../shell/
tar zxvf /tmp/topautocam.tar.gz -C /var/www/topautocam
