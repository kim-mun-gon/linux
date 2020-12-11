#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(void)
{
	int filedes, fdnew1, fdnew2;
	ssize_t nread;
	off_t newpos;

	char buffer[1024];
	char content[] = "Hello my friend!!\n";

	filedes = open("data.txt", O_RDWR);

	nread = read(filedes, buffer, 1024);
	printf("%s", buffer);

	printf("length of content: %d\n", (int)strlen(content));
	write(filedes, content, strlen(content));

	newpos = lseek(filedes, (off_t)0, SEEK_SET);
	nread = read(filedes, buffer, 1024);
	printf("%s", buffer);

	close(filedes);
	
	return 0;
}
