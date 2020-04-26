#ifndef __DFS_SHARED__
#define __DFS_SHARED__

typedef struct dfs_superblock {
  // STUDENT: put superblock internals here
  int isvalid;
  uint32 fsBlockSize;
  uint32 numFsBlocks;
  uint32 inodeStartBlock;
  uint32 numInodes;
  uint32 fbvStartBlock;

} dfs_superblock;

#define DFS_BLOCKSIZE 1024  // Must be an integer multiple of the disk blocksize

typedef struct dfs_block {
  char data[DFS_BLOCKSIZE];
  
} dfs_block;

#define DFS_INODE_FILENAME_MAX 96
#define DFS_INODE_NUM_DIRECT_ADDRESSED_BLOCKS 10
#define DFS_INODE_NUM_INDIRECT_ADDRESSED_BLOCKS
#define DFS_INODE_MAX_VIRTUAL_BLOCKS
#define DFS_INODE_MAX_NUM 192

typedef struct dfs_inode {
  // STUDENT: put inode structure internals here
  // IMPORTANT: sizeof(dfs_inode) MUST return 128 in order to fit in enough
  // inodes in the filesystem (and to make your life easier).  To do this, 
  // adjust the maximumm length of the filename until the size of the overall inode 
  // is 128 bytes.
  int inuse;
  uint32 fileSize;
  char filename[DFS_INODE_FILENAME_MAX];
  uint32 directAddr[DFS_INODE_NUM_DIRECT_ADDRESSED_BLOCKS];
  uint32 indirectAddr;

} dfs_inode;

#define DFS_MAX_FILESYSTEM_SIZE 0x1000000  // 16MB
#define DFS_MAX_NUM_BLOCKS 16384

#define DFS_BITS_PER_BYTE

#define DFS_FBV_BITS_PER_ENTRY
#define DFS_FBV_MAX_NUM_WORDS ((DFS_MAX_FILESYSTEM_SIZE / DFS_BLOCKSIZE) / 32)  //num indexes for fbv array

#define DFS_SUPER_BLOCK_PHY_BLOPCK_NUM

#define DFS_FAIL -1
#define DFS_SUCCESS 1



#endif
