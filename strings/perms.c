#include<stdio.h>
void swap(char *x, char *y) {
	char tmp = *x;
	*x = *y;
	*y = tmp;
}
void perm(char *str, int i , int n) {
	if(i == n ) {
		printf("%s\n",str);
	}
	int j=0;
	for ( j = i; j <= n; j++) {
		swap((str+i),(str+j));
		perm(str, i+1 , n);
		swap((str+i), (str+j));
	}
}
void main() {
	char a[]="ABC";
	perm(a,0,2);
}
