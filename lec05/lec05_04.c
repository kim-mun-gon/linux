#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	int filedes;
	off_t newpos;

	filedes = open("data.txt", O_RDONLY);

	/* 읽기/쓰기 포인터를 EOF로 이동한다.*/
	newpos = lseek(filedes, (off_t)0, SEEK_END); //newpos은 17이 됨

	printf("file size : %d\n", (int)newpos); //newpos은 파일 크기(byte 단위)와 같음
}
