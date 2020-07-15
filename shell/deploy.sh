#!/bin/sh
rm -rf /tmp/topautocambodia.tar.gz
tar cvfz /tmp/topautocambodia.tar.gz  config/  db/  lib/  plugin/  public/  sql/ shell/
tar zxvf /tmp/topautocambodia.tar.gz -C /var/www/topautocambodia.com
