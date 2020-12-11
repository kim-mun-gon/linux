#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	long lSize;
	char *buffer;
	size_t result;

	fp = fopen("data.txt", "r");
	if(fp == NULL)
		perror("Error opening file");

	fseek(fp, 0, SEEK_END); // 읽기/쓰기 포인터(오프셋)를 EOF로 이동
	lSize = ftell(fp); // 파일 내의 데이터 크기(byte 단위) 확인
	rewind(fp);

	buffer = (char *)malloc(sizeof(char)*lSize); //파일 내의 데이터 크기만큼 데이터 할당
	if(buffer == NULL)
		perror("Memory allocation error");

	result = fread(buffer, sizeof(char), lSize, fp);
	if(result != lSize)
		fprintf(stderr, "Reading error"); //표준에러로 사용자 정의 오류 메시지 출력
	else //stderr는 stdio.h에 정의되어 있는 표준에러의 FILE 포인터
		printf("%s", buffer);

	fclose(fp);
	free(buffer); //할당된 메모리 해제

	return 0;
}
