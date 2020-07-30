#!/bin/sh
rm -rf /tmp/topautocam.tar.gz
tar cvfz /tmp/topautocam.tar.gz  config/  db/  lib/  plugin/  public/  sql/ shell/
scp -i "ahlev-key-pair.pem" /tmp/topautocam.tar.gz ubuntu@ec2-18-218-101-36.us-east-2.compute.amazonaws.com:/home/ubuntu
rm -rf /tmp/topautocam.tar.gz
