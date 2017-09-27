#ifndef _MYVIM_H_
#define _MYVIM_H_

#include "common.h"
#define LEN 100
struct entrepot{
	char para[1024];//参数
	int  data;//参数的值
};
struct entrepot Entr[LEN]; 
struct entrepot Entr_def[LEN];
struct entrepot Entr_set[LEN];
void myvim();
void do_line(char*);
#endif
