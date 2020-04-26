#ifndef __DFS_H__
#define __DFS_H__

#include "dfs_shared.h"

void DfsModuleInit();
void DfsInvalidate();

//Non-inode Functions (not sure about arguments yet)
int DfsOpenFilesSystem();
int DfsCloseFileSystem();
uint32 DfsAllocateBlock();
int DfsFreeBlock();
int DfsReadBlock();
int DfsWriteBlock();

//Inode Functions (not sure about arguments yet)
uint32 DfsInodeFilenameExists();
uint32 DfsInodeOpen();
int DfsInodeDelete();
int DfsInodeReadBytes();
int DfsInodeWriteBytes();
uint32 DfsInodeFilesize();
uint32 DfsInodeAllocateVirtualBlock();
uint32 DfsInodeTranslateVirtualToFilesys();


#endif
