#ifndef CSHELL_H
#define CSHELL_H

#define CSHELL_CMDLINE_MAX_BUFFER_SIZE 128
#define CSHELL_USERNAME_MAX_BUFFER_SIZE 32
#define CSHELL_CURDIR_MAX_BUFFER_SIZE 4096
#define CSHELL_CMD_MAX_NUM 1024

// 初始化csh
void cshell_initialize();
// 启动csh
void cshell_start();

#endif
