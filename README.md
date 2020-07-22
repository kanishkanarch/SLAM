# Ubuntu-and-ROS
Ubuntu and ROS installation for beginners

Newer PCs' hardware quit supporting legacy BIOS boot option and only support UEFI.Thus traditional EXT file system installation for Ubuntu may not work or if it does, Ubuntu may not boot.
--------------------------------------------------------------------------
During Ubuntu installation, click "Continue with UEFI" (or a similar prompt). Free space partitions must be done as follows:
1. Swap: Select Primary. Size should be atleast the double of the computer RAM.

2. Root: Select Logical. Size should be atleast 20 GB. Although this size is not official, but is recommemded to keep it this large so your ROS/Gazebo/PointClouds/bag files/Anaconda/VSCode and other softwares work fine and have enough space for their installation (This is the partitions in which you INSTALL your software and not SAVE or RUN them. Don't make it so much big so that you're not left with any space for Home partition, where you SAVE or RUN your softwares' directories or files). 

*3. EFI file system: Select Primary. This is only applicable for systems in which the legacy BIOS isn't supported and only UEFI is supported. Size should be atleast 2 GB, but to be secured of booting problems, I've made this 5 GB.*

4. Home: Select Logical. This is the partition in which you make all your directories and files. Size differs from user to user. Make it big enough so that your directories and files fit without any problems. I've made it 167 GB.
----------------------------------------------------------------------------------
This partition configuration worked for me inside a DELL laptop (such a crap) and thus should also work on your system too.
