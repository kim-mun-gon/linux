#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int fdin, fdout;
	ssize_t nread, nwrite;
	//ssize_t = 사이즈를 반환하기 위한 함수
	char buffer[1024];

	fdin = open("fdin.txt", O_RDONLY);
	//읽기 전용 파일 열기
	fdout = open("fdout.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	//쓰기 전용 파일 열기

	printf("file descriptor: %d\n", fdin); //파일 디스크립터 화면 출력
	printf("file descriptor: %d\n", fdout); //파일 디스크립터 화면 출력

	//정상적으로 읽어 들인 내용이 1바이트 이상인 동안 반복문 수행
	while((nread = read(fdin, buffer, 1024)) > 0) //최대 1024바이트의 데이터를 읽음
	{
		printf("actually read data size (byte): %d\n", (int)nread); //실제로 읽은 데이터 크기
		
		// 쓸 데이터 크기 nread와 쓴 데이트 크기 nwrite가 다를 경우 write 실패
		if((nwrite = write(fdout, buffer, nread)) != nread)
			printf("file write error!\n");
	}

	//프로그램이 정상적으로 수행되었다.
	close(fdin);
	close(fdout);

	return 0;
}
