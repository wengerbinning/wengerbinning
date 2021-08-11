#include <stdio.h>
#include <windows.h>

int main() 
{	
    DWORD PID;
	PID  = GetCurrentProcessId();
	printf("ID:%d\n",PID);
	STARTUPINFO si = {sizeof(si)}; //记录结构体有多大，必须要参数
	PROCESS_INFORMATION pi;    //进程id，进程句柄，线程id，线程句柄存在于这个结构体
	char lpPath[] = "E:/c/bin/helloword.exe";	//这是用于新进程执行的文件（当前目录下的嗷用的是想对路径）
	boolean status = CreateProcess(NULL,lpPath,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi);
	if (status) printf("子进程ID：%d\n",pi.dwProcessId); 
    else
        printf("create fail!\n");
    scanf("%d", &PID);
    return 0;
}