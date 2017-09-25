#include "myvim.h"
//引入结构体 struct entrepot{}Entr;

int counter = 0;//用于计数参数的个数
int offset = 0;//记录遍历到的位置
int t = 0;
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
	char* spliptr = " ";
	char* cc = strtok(cmd,spliptr);//利用空格为分割符分割cmd
	char* sc = strtok(NULL,spliptr);
	if(!strcmp(cc,"exit")){
		exit(0);
	}
	//实现pwm
	char buffer3[1024];
	write(STDOUT_FILENO,"a",1);
	if(!strcmp(cc,"pwd")){
		memset(buffer3,0,sizeof(buffer3));
		getcwd(buffer3,1024);
		write(STDOUT_FILENO,buffer3,strlen(buffer3));
	}
	write(STDOUT_FILENO,"a",1);
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
		char* ts = "进入myvim ,规则def set add sub print undef";
		write(STDOUT_FILENO,ts,strlen(ts));
		//传入标准输入的值
		while(1){
			myvim( );
		}

	}
	write(STDOUT_FILENO,"a",1);
	return ;
}
void myvim()
{
	char cm[1024];
	char array[1024];
	read(STDIN_FILENO,cm,1024);
	char *space = " ";
	char *c = strtok(cm,space);
	char* s = strtok(NULL,space);
	char buffer1[1024];
	char buffer2[1024];
	strcpy(buffer1,c);
	//检测定义 进入编辑器后循环，exit退chu
	if(strstr("def",buffer1)){
		write(STDOUT_FILENO,buffer1,1);
		
	}
}
