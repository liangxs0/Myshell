/*************************************************************************
    > File Name: src/main.c
    > Author: L-Rmos
    > mian 函数
    > Created Time: 2017年09月28日 星期四 18时42分47秒
 ************************************************************************/

#include "common.h"
#include "doline.h"
extern  jmp_buf env;
extern Program* prog;
void ad()
{
	int fd = open("./doc/ad.txt",O_RDONLY);
		if(fd < 0){
			fprintf(stderr,"Open ad.txt error%s\n",strerror(errno));
		}
	char buf[4096] = {'\0'};
	ssize_t l = 0;
	while((l = read(fd,buf,4096)) > 0){
		write(STDOUT_FILENO,buf,l);
		memset(buf,0,sizeof(buf));
	}
}
int main(int argc,char* argv)
{
	//广告打印
	ad();
	//打印用户名
	char *prompt = "L-Rmoas>>";
	//设置长跳转点
	int ret = setjmp(env);
	if(ret < 0){
		//跳转失败
		fprintf(stderr,"jmp Error %s\n",strerror(errno));
	}else if(ret == 0){
		//成功跳转
		write(STDOUT_FILENO," return main ",12);
		printf("\n");
	}else{
		//
	}
	char buffer[1024] = {'\0'};
	while(1){
		//打印用户名
		write(STDOUT_FILENO,prompt,strlen(prompt));
		//读取标准输入到buffer
		memset(buffer,0,sizeof(buffer));
		read(STDIN_FILENO,buffer,1024);
		//处理回车
		buffer[strlen(buffer) - 1] = '\0';
		//行处理函数
		do_line(buffer);
		free(prog->cmd);
		free(prog);
	}
}


