# Ubuntu-and-ROS
Ubuntu and ROS installation for beginners

Newer PCs' hardware quit supporting legacy BIOS boot option and only support UEFI.Thus traditional EXT file system installation for Ubuntu may not work or if it does, Ubuntu may not boot.
----------------------------------------------------------------------------------

In your Windows, go to Disk Management. Right click the partition in which you want to install Ubuntu. Select Shrink Volume. You'll be asked how much you want to shrink this partition; in other words, how much big you want your Ubuntu size (This size should be atleast 30 GB bigger than what you want your Ubuntu to be). Click OK and then you'll see Unallocated space in the disk. This is where Ubuntu will make all its partitions.

Download two things now. Ubuntu and Flashing software. Ubuntu 16.04 can be downloaded from https://releases.ubuntu.com/16.04/ubuntu-16.04.6-desktop-amd64.iso and flashing software (a very good one is Balena Etcher) can be downloaded from https://github.com/balena-io/etcher/releases/download/v1.5.101/balenaEtcher-Setup-1.5.101.exe. 
----------------------------------------------------------------------------------
Now pick a Flashdrive (Pendrive) and connect it to your PC. Format it with FAT32 option. Aviod Quick Format. When the format is complete, install the software Balena Etcher (or the one which you downloaded). Open it and Flash your Flashdrive with Ubuntu you downloaded (it's actually called Ubuntu image).
When the installation is complete, restart your PC and go to BIOS menu by pressing some function key repeatedly. Almost all the times, the screen will show you which function key will take you to BIOS menu, but you can look up on the Internet for your Laptop's BIOS menu key (this function key depends on which company made the laptop, HP laptops have F10, DELL has F12). Once in BIOS menu, click on the optios to boot (start) from your Flashdrive. You'll be prompted with 4 options, two of them being Try Ubuntu and Install Ubuntu. You can click any option, in Try Ubuntu, you'll most probably have to open the Ubuntu installer manually (this installer is right on your screen). 

During Ubuntu installation, click "Continue with UEFI" (or a similar prompt, if prompted). Free space partitions must be done as follows:

Select 'Free space'. Partitions of free space are done as follows.

1. Swap: Select Primary. Size should be atleast the double of the computer RAM.

Now select the left over free space.

2. Root: Select Logical. Size should be atleast 20 GB. Although this size is not official, but is recommemded to keep it this large so your ROS/Gazebo/PointClouds/bag files/Anaconda/VSCode and other softwares work fine and have enough space for their installation (This is the partitions in which you INSTALL your software and not SAVE or RUN them. Don't make it so much big so that you're not left with any space for Home partition, where you SAVE or RUN your softwares' directories or files). 

Again select the leftover free space.

*3. EFI file system: Select Primary. This is only applicable for systems in which the legacy BIOS isn't supported and only UEFI is supported. Size should be atleast 2 GB, but to be secured of booting problems, I've made this 5 GB.*

Again select the leftover free space.

4. Home: Select Logical. This is the partition in which you make all your directories and files. You can use all the remaining space for this partition. Size differs from user to user. Make it big enough so that your directories and files fit without any problems. I've made it 167 GB.
----------------------------------------------------------------------------------
This partition configuration worked for me inside a DELL laptop (such a crap) and thus should also work on your system too.
----------------------------------------------------------------------------------
ROS distributions can be installed successfully from the ROS Wiki webpage. For instance, ROS Kinetic, which is supported by Ubuntu 16.04, can be installed from http://wiki.ros.org/kinetic/Installation/Ubuntu. Follow the procedure by heart and don't just copy-paste the terminal commands, READ what's the command doing and whether you'll be needing it or not.
