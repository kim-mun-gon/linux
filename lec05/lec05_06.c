#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(void)
{
	FILE *fp1, *fp2;
	char *fn1 = "data.txt";
	char *fn2 = "nonexistent.txt";

	//data.txt가 존재하는 경우
	fp1 = fopen(fn1, "r");
	printf("fopen of %s, error number = %d, error string = %s\n", fn1, errno, strerror(errno));

	if(fp1)
	{
		fclose(fp1);
		printf("fclose of %s, error number = %d, error string = %s\n", fn1, errno, strerror(errno));
	}

	//nonexistent.txt가 존재하지 않은 경우
	fp2 = fopen(fn2, "r");
	printf("fopen of %s, error number = %d, error string = %s\n", fn2, errno, strerror(errno));

	if(fp2)
	{
		fclose(fp2);
		printf("flose of %s, error number = %d, error string = %s\n", fn2, errno, strerror(errno));
	}
	return 0;
}
