#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(void)
{
	FILE* fp;
	char buffer[20] = {0, };

	fp = fopen("data.txt", "w");

	//파일이 정상적으로 열렸는지 확인 (null포인터인지 확인)

	if(fp == NULL)
		perror("Error opening file");
	else
	{
		fread(buffer, sizeof(char), 20, fp); //쓰기 전용 data.txt에 읽기를 수행하여 오류를 발생시킴
		if(ferror(fp))
		{
			perror("Error Writing to data.txt\n"); //표준에러로 인자인 사용자 정의 오류 메시지와 시스템 오류 메시지를 출력
			printf("fclose of data.txt, error number = %d, error string = %s\n", errno, strerror(errno)); //표준 출력으로 errno과 strerror함수를 통해 시스템 오류 메시지 출력
		}
		fclose(fp);
	}
	return 0;
}
