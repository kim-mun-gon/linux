#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>   //for open
#include <unistd.h>  //for close

int main(void)
{
	int filedes1, filedes2;
	char *pathname1 = "data1.txt";
	char *pathname2 = "data2.txt";

	filedes1 = open(pathname1, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	//파일열기(파일이 없으면 파일 생성하여 열기
	//O_TRUNC = 기존의 파일의 내용이 있으면 지움
	filedes2 = creat(pathname2, 0644);
	//파일 생성하여 열기

	printf("file descriptor: %d\n", filedes1);
	printf("file descriptor: %d\n", filedes2);

	close(filedes1);
	close(filedes2);

	return 0;
}
