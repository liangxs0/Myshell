/*************************************************************************
    > File Name: include/myvim.h
    > Author: L-Rmos
    > .....
    > Created Time: 2017年09月29日 星期五 10时18分50秒
 ************************************************************************/

#ifndef _MYVIM_H_
#define _MYVIM_H_
#include "common.h"
#define LEN 100
struct entrepot{
	char para[1024];//参数
	int data;//参数值
};
struct entrepot Entr[LEN];
struct entrepot Entr_def[LEN];
struct entrepot Entr_set[LEN];

#endif

