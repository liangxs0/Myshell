#include "myvim.h"

const char* prompt = "User&";
extern jmp_buf jmp_env;
int main(int argc,char** argv)
{
	char buffer[1024];
	int jmp = setjmp(jmp_env);
	if(setjmp(jmp_env) < 0){
		fprintf(stderr,"flag error %s\n",strerror(errno));
		return -1;	
	}else if(jmp = 0){
	
	}else{
		printf("setjmp %d\n",jmp);	
	}
	while (1){
		//打印 User & 到标准输出
		write(STDOUT_FILENO,prompt,strlen(prompt));
		memset(buffer,0,sizeof(buffer));
		//读取buffer内容到标准输入
		read(STDIN_FILENO,buffer,strlen(buffer));
		//对最后的回车的处理
		int len = strlen(buffer);
		buffer[len - 1] = '\0';
		write(STDOUT_FILENO,"b",1);
		do_line(buffer);
	}
	return 0;
}
