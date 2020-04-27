#ifndef __FDISK_H__
#define __FDISK_H__

typedef unsigned int uint32;

#include "dfs_shared.h" // This gets us structures and #define's from main filesystem driver

#define FDISK_INODE_BLOCK_START 1 // Starts after super block (which is in file system block 0, physical block 1)
#define FDISK_INODE_NUM_BLOCKS 16 // Number of file system blocks to use for inodes
#define FDISK_NUM_INODES 192 //STUDENT: define this
#define FDISK_FBV_BLOCK_START 17 //STUDENT: define this
#define FDISK_BOOT_FILESYSTEM_BLOCKNUM 0 // Where the boot record and superblock reside in the filesystem

#ifndef NULL
#define NULL (void *)0x0
#endif

//STUDENT: define additional parameters here, if any
#define FDISK_FBV_NUM_BLOCKS 2 //lab doc says free block vector is blocks 17 and 18 so this is 2 i think


#endif
