#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>       // for open()
#include <unistd.h>      // for close()

int main(void)
{
	int filedes;
	char *pathname = "temp.txt";

	filedes = open(pathname, O_CREAT | O_RDWR, 0644); //파일 열기(파일이 없으면 파일생성하여 열기)
	// O_CREAT = 파일이 없을 경우 파일을 생성, O_RDWR = 읽기/쓰기 모두 가능
	//0644 = 0400 + 0200 + 040 + 04, 소유자에 대한 읽기와 쓰기, 그룹과 기타사용자는 읽기 권한
	//0400 = 소유자의 읽기 권한, 0200 = 소유자의 쓰기 권한, 0100 = 소유자의 실행권한
	//040 = 그룹에 대한 읽기 권한, 020 = 그룹에 대한 쓰기 권한, 010 = 그룹에 대한 실행권한
	//04 = 기타 사용자에 대한 읽기 권한, 02 = 기타 사용자에 대한 쓰기 권한, 01 = 실행권한
 // filedes = open(pathname, O_CREAR | O_RDWR | O_EXCL, 644);
	// 하면 이미 파일이 만들어져 있기 때문에 -1값이 나온다
	// O_EXCL = 파일이 있을 경우에 에러를 발생시킴

	printf("file descriptor: %d\n", filedes); // 파일 스크립터 화면 출력

	if(filedes == -1)
		printf("file open error!\n"); // 파일 열기 실패
	else if(filedes > 0)
		printf("file open: %s\n", pathname); //파일  열기 성공

	close(filedes); // 파일 닫기
	return 0;
}
