#include<stdio.h>

int main() {
	char line[100];
	printf("please input a string:\n");
	fgets(line, (sizeof line / sizeof(line[0])), stdin);
	puts(line);
	return 0;
}
