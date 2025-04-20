Ubuntu 18.04.6 LTS
3.2GB, Disk~1TB
AMD A6-9225 Radeon r4, 5 compute cores 2c+3g*2
Issue: After install No Wifi adapter found
Install: Ubuntu startup usb + phone blue-tooth internet to update

Commands:
lspci -nnk | grep -iA3 net > working

sudo apt-get update > not working, err: couldnt resolve 'security.ubuntu.com' and others
    > add nameserver 8.8.8.8 to /etc/resovl.conf > didnt work
    > 