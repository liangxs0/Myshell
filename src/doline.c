/*************************************************************************
    > File Name: src/doline.c
    > Author: L-Rmos
    > do_line 实现文件
    > Created Time: 2017年09月28日 星期四 19时08分48秒
 ************************************************************************/

#include "doline.h"
 jmp_buf env;
Program* prog;
//空格处理函数,处理前后空格
void spaceTokn(char** cmd)
{
	char ** start = cmd;
	char* end = (*start) + strlen(*cmd);
	while(*(*start) ==' ') (*start)++;
	cmd = start;
	while(*end-- == ' ');
	*(end + 1) = '\0';
}
//行处理函数
void do_line(char* cmd)
{
	//open 1K
	prog = malloc(2048);
	prog->cmd = malloc(1024);
	if(prog == NULL){
		fprintf(stderr,"malloc falie %s\n",strerror(errno));
	}
	//前后空格处理
	spaceTokn(&cmd);

	char* space = " ";
	char* cc = strtok(cmd,space);
	//第一次返回，地址下标0.
	prog->cmd[0] = cc;
	//printf("---%s\n",prog->cmd[0]);
	int i = 0;
	//地址从下标1-----》
	
	while((prog->cmd[++i] = strtok(NULL,space)));
	
	if(!strcmp(prog->cmd[0],"myvim")){
		//进入myvim
		printf("进入myvim]\n");
		while(1){
			myvim();
		}
	}else{
		exec_program(prog);
	}
	return;
}
void exec_program(Program* prog)
{
	pid_t pid;
	pid = fork();
	if(pid < 0){
		fprintf(stderr,"fork Error %s\n",strerror(errno));
	}else if(pid == 0)
	{
		//进程替换
		if(execvp(prog->cmd[0],prog->cmd) < 0)
		{
			fprintf(stderr,"exec Error %s\n",strerror(errno));
		}
		exit(0);
	}else{
		//父进程等待
		wait(0);
	}
}

