#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void __gen_params(char *str, int n, int curpos, int l , int r) {
	if(curpos == 2*n) {
		str[curpos] = '\0';
		printf("%s\n",str);
		return;
	}
	if(l < n) {
		str[curpos] = '(';
		__gen_params(str, n , curpos+1, l+1, r);
	}
	if(r < l) {
		str[curpos] = ')';
		__gen_params(str, n , curpos+1, l, r+1);
	}
}
void gen_params(char *str, int n){
	__gen_params(str, n , 0, 0, 0 );
}
main() {
	int n = 4;
	char *str = (char *)malloc(sizeof(char)*(2*n+1));
	memset(str, 0X00, 2*n +1);
	gen_params(str,n);
}
