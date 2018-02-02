#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

#include<string.h>
#include<errno.h>

void error(int status) {
	if (status == -1) {
		printf("%d: %s\n", errno, strerror(errno));
	}
}

int main() {
	int fd = open("pic.ppm", O_CREAT | O_WRONLY, 0644);
	error(fd);
	
	char buf[512];
	int width = 500, height = 500;
	
	//write setup lines
	sprintf(buf, "P3\n%d %d\n255\n", width, height);
	error(write(fd, buf, strlen(buf)));
	
	//stuff!
	int x, y;
	for (x = 0; x < width; x++) {
		for (y = 0; y < height; y++) {
			sprintf(buf, "%d %d %d ", x%256, x%256, y%256);
			error(write(fd, buf, strlen(buf)));
		}
		error(write(fd, "\n", 1));
	}
	
	
	return 0;
}
