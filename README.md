# santoka_qt
Santoka display configuration and app creation

# Configuration
- connect usb to PC 
- open TeraTerm
- connect to COM port
- go on the terminal and type
```sh
ls
root

bootselect alternative
reboot

cd /mnt/**/
./fng_install.sh

bootselect regular 
reboot

ls
root

# deactivate demo
update-rc.d -f qt-guf-demo remove 

cd /media/sda1/
# the app must be compiled with Release
./myapp     # app design must be in the same folder

# source
source /opt/guf/GUF-Yocto-jethro-11.0-r8139-0-sdk/environment-setup-imx6guf-guf-linux-gnueabi

#password
root
root

#copy
rm /applicat/huracanXsantoka                                    
cp /media/sda1/huracanXsantoka /applicat/
```


