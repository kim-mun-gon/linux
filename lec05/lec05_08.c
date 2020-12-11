#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE *fp;
	char *s1 = "Hello, world!";

	fp = fopen("hello.txt", "w");

	if(fp == NULL)  //파일이 정상적으로 열렸는지 확인(null 포인터인지 확인)
		perror("Error opening file");
	else
	{
		fwrite(s1, sizeof(char), strlen(s1), fp); //파일에 문자열 쓰기
		fclose(fp);
	}
	
	return 0;
}
