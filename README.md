# Ubuntu and ROS installation for beginners

In your Windows, go to Disk Management. Right click the partition in which you want to install Ubuntu. Select Shrink Volume. You'll be asked how much you want to shrink this partition; in other words, how much big you want your Ubuntu size (This size should be atleast 30 GB bigger than what you want your Ubuntu to be). Click OK and then you'll see Unallocated space in the disk. This is where Ubuntu will make all its partitions.

Check your computer's RAM. You'll need it in a few minutes. You can see your computer's RAM by right clicking 'This PC' or 'My Computer' inside Windows and opening Properties.

Download two things now. Ubuntu and a Flashing software. Ubuntu 16.04 can be downloaded from https://releases.ubuntu.com/16.04/ubuntu-16.04.6-desktop-amd64.iso and flashing software (a very good one is [BALENA ETCHER](https://github.com/balena-io/etcher/releases/download/v1.5.101/balenaEtcher-Setup-1.5.101.exe)). Another flashing software is [UNIVERSAL USB INSTALLER](https://www.pendrivelinux.com/universal-usb-installer-easy-as-1-2-3/).

Now pick a Flashdrive (Pendrive) and connect it to your PC. Format it with FAT32 option. Aviod Quick Format. When the format is complete, install the software Balena Etcher in your PC (or the one which you downloaded). Open it and Flash your Flashdrive with Ubuntu you downloaded (it's actually called Ubuntu image).
When the installation is complete, restart your PC and go to BIOS menu by pressing some function key repeatedly. Almost all the times, the screen will show you which function key will take you to BIOS menu, but you can look up on the Internet for your Laptop's BIOS menu key (this function key depends on which company made the laptop, HP laptops have F10, DELL has F12). Firstly, see if you can turn on Legacy Mode/CSM Mode by turnung off Secure Boot or not. If yes, then fine, if not, then also fine. But keep a note of it if your computer can boot into Legacy mode or not (you'll be needing this information in a few minutes). Once in BIOS menu, click on the option to boot (start) from your Flashdrive. You'll be prompted with 4 options, two of them being Try Ubuntu and Install Ubuntu. You can click any option, in Try Ubuntu, you'll most probably have to open the Ubuntu installer (this installer is right on your screen). 

If you're asked to choose from 'Erase Disk and Install Ubuntu' and 'Something else' along with a couple of more options, go for 'Something else'. This way you can manually make partitions in the Unallocated space yourself. 'Erase Disk and Install Ubuntu' is something I'm neither familiar with nor I think it as a safe option as it MAY delete your data outside the Unallocated space.


During Ubuntu installation, click "Continue with UEFI" (or a similar prompt, if prompted). Free space partitions must be done as follows:

Select 'Free space' partition and hit '+' sign to make new partitions out of it. Partitions of free space are done as follows.

1. Swap: Most guides I know of recommend to use double the size of your RAM for your SWAP partition and at least the same amount of memory as your RAM. Technically, you can do without SWAP at all, but it doesn’t hurt to have some SWAP in case your RAM is not that big. Most systems nowadays have at least 8 GB of RAM.

The more RAM you have, the less likely you need the SWAP memory. On this computer, I have 8 GB of RAM. Therefore, I use 4 GB for this installation. That should be enough. Choose “Logical” for the partition type and select “swap area” from the drop down menu. Then click “OK”

Now select the left over free space


2. Root: You need the so called “root” partition which hosts all your system files necessary by Ubuntu to function. By default, this partition will also contain your personal files, but here we will create a separate partition only for your personal files, such as your “Downloads” folder or “Music” folder. This is why we need to create two more partitions.

Both partitions will be about 16 GB in size. For the “root” partition, select the “Primary” option for the partition type as this partition needs to be bootable. Then, in the drop down menu, select “Ext4 journaling file system” which is still the default file system for Linux. The mount point must be “/” which stands for the “root” partition.
Again select the leftover free space.

*3. EFI file system: Select Primary. This is only applicable for systems in which the legacy BIOS isn't supported and only UEFI is supported. Size should be atleast 2 GB, but to be secured of booting problems, I've made this 5 GB.*

Again select the leftover free space.

4. Home: Select Logical. This is the partition in which you make all your directories and files. You can use all the remaining space for this partition. Size differs from user to user. Make it big enough so that your directories and files fit without any problems. I've made it 167 GB.

5. Loading the GRUB bootloader for getting the option window in the starting which asks you to boot in either Windows or Ubuntu: [This one](https://medium.com/@mugglestudies/common-problems-with-ubuntu-and-windows-dual-boot-installations-the-official-muggle-studies-guide-653fa37116b2#:~:text=The%20solution%20to%20the%20problem,h%20off%20and%20press%20enter) is a very nice tutorial, but do explore more.

This partition configuration worked for me inside a DELL laptop (yes I know, your condolences are with me) and thus should also work on your system too.

ROS distributions can be installed successfully from the ROS Wiki webpage. For instance, ROS Kinetic, which is supported by Ubuntu 16.04, can be installed from [here](http://wiki.ros.org/kinetic/Installation/Ubuntu). Follow the procedure by heart and don't just copy-paste the terminal commands, **READ** what the command is doing and whether you'll be needing it or not.

Cheers!
