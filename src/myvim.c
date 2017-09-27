#include "myvim.h"
//引入结构体 struct entrepot{}Entr;

int counter = 0;//用于计数def个数
int counter1 = 0;//用于记录set个数
int offset = 0;//记录遍历到的位置
jmp_buf jmp_env;//长跳转
void spaceToken(char** cmd)
{
	char ** start = cmd;
	char * end = *start+strlen(*cmd);
	while(*(*start) == ' ') (*start)++;
	cmd = start;
	while(*end-- == ' ');
	*(end + 1) = '\0';
}

void do_line(char* cmd)
{
	//调用空格处理
	spaceToken(&cmd);
	char* spliptr = "";
	char* cc = strtok(cmd,spliptr);//利用空格为分割符分割cmd
	char* sc = strtok(NULL,spliptr);
	if(!strcmp(cc,"exit")){
		exit(0);
	}
	//实现pwm
	char buffer3[1024];
	//write(STDOUT_FILENO,"a",1);
	if(!strcmp(cc,"pwd")){
		memset(buffer3,0,sizeof(buffer3));
		getcwd(buffer3,1024);
		write(STDOUT_FILENO,buffer3,strlen(buffer3));
	}
	//write(STDOUT_FILENO,"a",1);
	//实现myvi 
	/*
	   def 定义，变量在未定义前不能使用
	   set i 10 ,赋值操作
	   add 加法
	   sub 减法
	   print 打印
	   undef 取消定义
	   */

	if(!strcmp(cc,"myvim")){
		//打印提示
		char* ts = "进入myvim ,规则def set add sub print exit";
		write(STDOUT_FILENO,ts,strlen(ts));
		//传入标准输入的值
		while(1){
			myvim( );
		}

	}
	//write(STDOUT_FILENO,"a",1);
	return ;
}
void myvim()
{
	int t;
	int len;//记录字符串长度
	int ss = 0;//记录输入的字符串个数
	char cm[1024];
	memset(cm,0,sizeof(cm));
	char array[1024];
	//获取输入的字符
	read(STDIN_FILENO,cm,1024);
	char* cd = cm; 
	//空格处理
	spaceToken(&cd);
	char *space = " ";
	char *c = strtok(cd,space);
	//记录输入的数组
	char buffer1[1024][1024] = {'\0'};
	//数组清空
	for(offset = 0;offset < 1024;offset++){
		memset(buffer1[offset],0,1024);
	}
	strcpy(buffer1[0],c);
	char buffer2[1024];
	memset(buffer2,0,sizeof(buffer2));

	//字符处理存放到buffer1
	offset = 0;
	while((c = strtok(NULL,space))){
		offset = offset + 1;
		strcpy(buffer1[offset],c);
		//printf("offset = %d,buffer1[offset] = %s\n",offset,buffer1[offset]);
		len = strlen(buffer1[offset]);
		//printf("len = %d\n",len);
		ss = offset + 1;
	}
	buffer1[offset][len - 1] = '\0';
	//printf("ss = %d\n",ss);

	//检测数组部分
/*	for(offset = 0;offset < ss; offset++)
	{
		printf("offset = %d,buffer1[offset] = %s\n",offset,buffer1[offset]);

	}
*/
	//检测定义
	if(strstr(buffer1[0],"def")){
		for (offset = 1;offset < ss;offset++){
			if(buffer1[offset][0] == '\0'){
				continue;
			}else{
 				strcpy(Entr_def[counter].para,buffer1[offset]);
				printf("counter = %d,Entr_def[counter].para = %s\n",counter,Entr_def[counter].para);
				counter++;
				t = t+1;
			}
		}
//		printf("t = %d\n",t);
	}
	//赋值函数
	if(strstr(buffer1[0],"set")){
		int set = 0;
		for(offset = 1;offset < ss;offset++){
			if(buffer1[offset] == '\0'){
				continue;
			}else{
 				for(set = 0;set < t+1;set++){

 					//printf("set = %d,counter = %d,Entr_set[counter].para = %s\n",set,counter,Entr_set[counter].para);
					//printf("set = %d , Entr_def[set].para = %s\n",set,Entr_def[set].para);
					//printf("offset1 = %d,buffer[offset1] = %s\n",offset,buffer1[offset]);	
					//printf("s = %d\n",strcmp(buffer1[offset],Entr_def[set].para));
					if(!strcmp(buffer1[offset],Entr_def[set].para)){
						//如果已经定义
						strcpy(Entr_set[counter1].para,Entr_def[set].para);//记录参数内容 
						//write(STDOUT_FILENO,Entr_set[counter].para,strlen(Entr_set[counter].para));
						//printf("set = %d , Entr_def[set].para = %s\n",set,Entr_def[set].para);
						for(offset = offset+1;offset < ss+1;offset++)
						{
							if(buffer1[offset] == '\0'){
								continue;
							}else{ 
								// 赋值操作
								Entr_set[counter1].data = atoi(buffer1[offset]);
								//printf("offset = %d\n",offset);
								printf("counter1 = %d\n",counter1);
								printf("Entr_set[counter1].para = %s\n",Entr_set[counter1].para);
								printf("Entr_set[counter1].data = %d\n",Entr_set[counter1].data);
								counter1++;						
								break;
							}
 						}
					}else{
						if(set == t+1)
							printf("未定义\n");	
					}
				}
			}
		}
	}
	//add 
	if(strstr(buffer1[0],"add")){
		int se = 0;
		int add = 0;
		//write(STDOUT_FILENO,"add",3);
		for(offset = 1;offset < ss; offset++){
			if(buffer1[offset] == '\0'){
				continue;
			}else{
				//判断是否赋值过
				for(se = 0;se < t+1; se++){
					if(!strcmp(buffer1[offset],Entr_set[se].para)){
						//已经赋值
						add = Entr_set[se].data + add;
						//printf("add = %d\n",add);
						break;
					}else{
						//未定义
					}
				}
			}
		}
		printf("add end = %d\n",add);
	}
	if(strstr(buffer1[0],"sub")){
		int se = 0;
		int sub = 0;
		//write(STDOUT_FILENO,"sub",3);
		for(offset = 1;offset < ss; offset++){
			if(buffer1[offset] == '\0'){
				continue;
			}else{
				//判断是否赋值过
				for(se = 0;se < t+1; se++){
					if(!strcmp(buffer1[offset],Entr_set[se].para)){
						//已经赋值
						sub = (0 - Entr_set[se].data) - sub;
						//printf("sub = %d\n",sub);
						break;
					}else{
						//未定义
					}
				}
			}
		}
		printf("sub end = %d\n",sub);
	}
	//print
	if(strstr(buffer1[0],"print")){
		int sa = 0;
		for(offset = 1;offset < ss;offset++){
			if(buffer1[offset] == '\0'){
				continue;
			}else{
			//判断定义
				for(sa = 0;sa < t+1;sa++){
					if(!strcmp(buffer1[offset],Entr_def[sa].para)){
						//已定义
						printf("para = %s\n",Entr_def[sa].para);//输出参数
						//判断参数是否有值
						for(sa = 0;sa < t+1;sa++){
							if(!strcmp(buffer1[offset],Entr_set[sa].para)){
								//存在值
								printf("data = %d\n",Entr_set[sa].data);
							}else{
								//参数没有值
							}
						}
					}else{
					//未定义
					}
				}
			}
		}
	}
	if(strstr(buffer1[0],"exit")){
		counter = 0;
		counter1 = 0;
		t = 0;
		ss = 0;
		longjmp(jmp_env,1);//跳到main函数
	}
}
