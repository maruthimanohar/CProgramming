#include<stdio.h>

int setcount(int a) {
	int count = 0;
	while(a) {
		a = a & (a-1);
		count++;
	}
	return count;
}
main() {
	int a = 7;
	printf("%d\n",setcount(a));
}
