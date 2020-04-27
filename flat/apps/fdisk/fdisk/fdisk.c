#include "usertraps.h"
#include "misc.h"

#include "fdisk.h"

dfs_superblock sb;
dfs_inode inodes[DFS_INODE_MAX_NUM];
uint32 fbv[DFS_FBV_MAX_NUM_WORDS];

int diskblocksize = 0; // These are global in order to speed things up
int disksize = 0;      // (i.e. fewer traps to OS to get the same number)

int FdiskWriteBlock(uint32 blocknum, dfs_block *b); //You can use your own function. This function 
//calls disk_write_block() to write physical blocks to disk

void main (int argc, char *argv[])
{
	// STUDENT: put your code here. Follow the guidelines below. They are just the main steps. 
	// You need to think of the finer details. You can use bzero() to zero out bytes in memory

  //Initializations and argc check
  dfs_block dfsBlock;
  uint32 dfsInodeStartBlock;
  uint32 dfsFbvStartBlock;
  uint32 numFsBlocks;
  char* currPos;
  int i; //general index

  if (argc != 1) {
    Printf("Incorrect number of arguments for fdisk\n");
  }

  // Need to invalidate filesystem before writing to it to make sure that the OS
  // doesn't wipe out what we do here with the old version in memory
  // You can use dfs_invalidate(); but it will be implemented in Problem 2. You can just do 
  sb.isvalid = 0; //change to dfs_invalidate(); for Problem 2?


  disksize = disk_size(); 
  diskblocksize = disk_blocksize();
  numFsBlocks = DFS_MAX_NUM_BLOCKS;
  dfsInodeStartBlock = FDISK_INODE_BLOCK_START;
  dfsFbvStartBlock = FDISK_FBV_BLOCK_START;


  // Make sure the disk exists before doing anything else
  disk_create();

  // Write all inodes as not in use and empty (all zeros)
  bzero(dfsBlock.data, sb.fsBlockSize);
  // Next, setup free block vector (fbv) and write free block vector to the disk
  // Finally, setup superblock as valid filesystem and write superblock and boot record to disk: 
  // boot record is all zeros in the first physical block, and superblock structure goes into the second physical block
  
  //loop through inode blocks
  //less than or equal to because inode index starts at one and there are 16 inode blocks
  for (i = FDISK_INODE_BLOCK_START; i <= FDISK_INODE_NUM_BLOCKS; i++) {
    FdiskWriteBlock(i, &dfsBlock);
  }

  //set up fbv and write fbv to disk
  for (i = 0; i < FDISK_FBV_NUM_BLOCKS; i++) {
    fbv[i] = 0;
  }

  //mark blocks corresponding to FS info and boot record as inuse


  //write fbv to disk


  //set up superblock as valid


  //write superblock and boot record to disk



  Printf("fdisk (%d): Formatted DFS disk for %d bytes.\n", getpid(), disksize);
}

int FdiskWriteBlock(uint32 blocknum, dfs_block *b) {
  // STUDENT: put your code here
}
