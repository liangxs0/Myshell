/*************************************************************************
    > File Name: include/do_line.h
    > Author: L-Rmos
    > do_line()头文件，用于行解析字符串
    > Created Time: 2017年09月28日 星期四 19时02分06秒
 ************************************************************************/
#ifndef _DOLINE_H_
#define _DOLINE_H_

#include "common.h"
#include "myvim.h"
typedef struct {
	//进程ID
	pid_t pid;
	char** cmd;
}Program;
void do_lien(char*);
void exec_program(Program*);

#endif
