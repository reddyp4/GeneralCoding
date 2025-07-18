For some reason, it is surprisingly hard to create a bootable Windows USB using macOS. These are my steps for doing so, which have worked for me in macOS Monterey (12.6.1) for Windows 10 and 11. After following these steps, you should have a bootable Windows USB drive.

### 1. Download a Windows disc image (i.e. ISO file)

You can download [Windows 10](https://www.microsoft.com/en-us/software-download/windows10ISO) or [Windows 11](https://www.microsoft.com/en-us/software-download/windows11) directly from Microsoft.

### 2. Identify your USB drive

After plugging the drive to your machine, identify the name of the USB device using `diskutil list`, which should return an output like the one below. In my case, the correct disk name is `disk2`.

```text
/dev/disk0 (internal, physical):
   #:                       TYPE NAME                    SIZE       IDENTIFIER
   0:      GUID_partition_scheme                        *500.3 GB   disk0
   1:                        EFI EFI                     314.6 MB   disk0s1
   2:                 Apple_APFS Container disk1         500.0 GB   disk0s2

/dev/disk1 (synthesized):
   #:                       TYPE NAME                    SIZE       IDENTIFIER
   0:      APFS Container Scheme -                      +500.0 GB   disk1
                                 Physical Store disk0s2
   1:                APFS Volume MacHDD - Data           180.3 GB   disk1s1
   2:                APFS Volume MacHDD                  15.4 GB    disk1s2
   3:              APFS Snapshot com.apple.os.update-... 15.4 GB    disk1s2s1
   4:                APFS Volume Preboot                 481.8 MB   disk1s3
   5:                APFS Volume Recovery                1.1 GB     disk1s4
   6:                APFS Volume VM                      1.1 GB     disk1s5

/dev/disk2 (external, physical):
   #:                       TYPE NAME                    SIZE       IDENTIFIER
   0:     FDisk_partition_scheme                        *15.5 GB    disk2
   1:                 DOS_FAT_32 WINDOWS10               15.5 GB    disk2s1
 ```
 
 ### 3. Format USB drive
 
 Format the drive with the following command, substituting `disk2` with whatever is the one that corresponds in your machine.
 ```zsh
 diskutil eraseDisk MS-DOS "WINDOWS10" MBR disk2
 ```
 
 ### 4. Mount the Windows ISO and check its size
 
Mount the ISO file in your system (usually by simply double-clicking it), and verify it's listed in `/Volumes`—the disk name usually starts with `CCCOMA_`. With the disk mounted, check the size of the `sources/install.wim` file with the following command:
```zsh
ls -lh /Volumes/CCCOMA_X64FRE_EN-US_DV9/sources/install.wim
 ```
 
 ### 5. Copy (almost) all files to USB drive
 
**If `sources/install.wim` is less than 4GB in size**, you can copy all the files from the mounted disk image onto the USB drive with the following command (notice the trailing slash in the first path!):
```zsh
rsync -avh --progress /Volumes/CCCOMA_X64FRE_EN-US_DV9/ /Volumes/WINDOWS10
```

**If `sources/install.wim` is more than 4GB**, then we'll need to split the file before copying it. In the meantime, we can copy all the other files from the mounted image onto the USB drive with the following command (again, notice the trailing slash in the first path!):
```zsh
rsync -avh --progress --exclude=sources/install.wim /Volumes/CCCOMA_X64FRE_EN-US_DV9/ /Volumes/WINDOWS10
```

### 6. Use `wimlib` to split and copy `sources/install.wim`

If `sources/install.wim` is more than 4GB, it is too large to copy onto a FAT32-formatted drive. Microsoft's [official solution](https://learn.microsoft.com/en-us/windows-hardware/manufacture/desktop/install-windows-from-a-usb-flash-drive?view=windows-11) is to split the file, and there is a free utility available in macOS and Linux to do so—`wimlib`. The tool can be installed with [Homebrew](https://brew.sh/):
```zsh
brew install wimlib
```

After installing `wimlib`, split and copy `sources/install.wim` using the following command:
```zsh
wimlib-imagex split /Volumes/CCCOMA_X64FRE_EN-US_DV9/sources/install.wim /Volumes/WINDOWS10/sources/install.swm 3800
```
Here, `3800` means that the file should be split in 3,800MB chunks.

Reference: https://gist.github.com/acarril/8c15f600cf0397dd61161a470f50f669