#include<stdio.h>

int myatoi(char *str) {
	int x = 0;
	while(*str) {
		if(*str >= '0' && *str <= '9')
			x = x*10 + (*str -48);
		else
			break;
		str++;
	}
	return x;
}
main() {
	char str[10] = "1874m";
	int a = myatoi(str);
	printf("a:%d\n",a);
}
