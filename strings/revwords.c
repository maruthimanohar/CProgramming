#include<stdio.h>
void reverse(char *a, char *b) {
	while( b > a ) {
		char tmp = *a;
		*a = *b;
		*b = tmp;
		a++;
		b--;
	}
}
void reverse_words(char *tmp) {
	char *start=NULL;
	//char *tmp = str;
	while(*tmp) {
		if(start == NULL && *tmp !=' ' && *tmp != '!') {
			start = tmp;
			printf("%c\n",*start);
		}
		if(start && (!*(tmp+1) || (*(tmp+1) &&  (*(tmp+1)=='!' || *(tmp+1)==' ') ) ) ) {
			reverse(start, tmp);
			start = NULL;
		}
		tmp++;
	}
}
main() {
	char str[20]= "Hello World! maruthi";
	printf(":%s:\n",str);
	reverse_words(str);
	printf(":%s:\n",str);
}
