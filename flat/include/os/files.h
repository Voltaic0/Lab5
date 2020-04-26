#ifndef __FILES_H__
#define __FILES_H__

#include "dfs.h"
#include "files_shared.h"

#define FILE_MAX_OPEN_FILES 15
#define FILE_MODE_R 1
#define FILE_MODE_W 2
#define FILE_MODE_RW 3

void FileModuleInit();
uint32 FileOpen(char* filename, int mode);
int FileClose(); //File functions need arguments still
int FileRead(); 
int FileWrite();
int FileSeek();
int FileDelete();
uint32 FileDescFilenameExists(char* filename);



#endif
