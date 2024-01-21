#include <cshell.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
void
cshell_initialize()
{
    // 进行csh的初始化工作
}

// 把命令行参数分割成一个一个的字符串，函数返回字符串数组，数组的元素个数保存在n里
char **
cshell_parse_cmdline(char * cmdline, int *n)
{
    char ** args = (char **)malloc(sizeof(char *) * CSHELL_CMD_MAX_NUM);

    return args;
}

int
cshell_execute(char ** args,int n)
{
    if (strcmp(args[0], "exit") == 0)
        return 0;
    else{
        pid_t pid;
        int status;
        return 1;
    }
}

void
cshell_start()
{
    char buf[CSHELL_CMDLINE_MAX_BUFFER_SIZE] = { 0 };
    char ** args;
    int ret;
    int n;
    char cur_dir[CSHELL_USERNAME_MAX_BUFFER_SIZE] = { 0 };
    char username[CSHELL_CURDIR_MAX_BUFFER_SIZE] = { 0 };

    // 获取当前用户名
    if(getlogin() == NULL) { // 如果是其他方式启动，可能会获取不到用户名
        strcpy(username, "unknown user");
    }else{
        strcpy(username, getlogin());
    }

    // 获取当前目录
    if (getcwd(cur_dir, CSHELL_CURDIR_MAX_BUFFER_SIZE) == NULL) {
        printf("getcwd error: current directory is too long!\n");
        exit(EXIT_FAILURE);
    }
    
    // 开始REPL
    do {
        // 打印提示符
        printf("\033[35m#\033[0m \033[32m%s\033[0m in \033[34m%s\033[0m\n",
               username,
               cur_dir);
        printf("\033[33m$\033[0m ");

        // 读取一行信息
        if (fgets(buf, CSHELL_CMDLINE_MAX_BUFFER_SIZE, stdin) != NULL) {
            // 解析命令行
            args = cshell_parse_cmdline(buf,&n);
            // 运行命令
            ret = cshell_execute(args,n);
        }
        memset(buf, 0, CSHELL_CMDLINE_MAX_BUFFER_SIZE);
    } while (ret);
}
