#include<stdio.h>
#include<string.h>

void reverse(char *begin, char *end) {
	char tmp;
	while(begin < end) {
		tmp = *begin;
		*begin++ = *end;
		*end-- = tmp;
	}
}


void reverse_words(char *str) {
	char *begin = NULL;
	char *tmp = str;
	while(*tmp) {
		printf("considering %c\n",*tmp);
		if(begin == NULL && *tmp != ' ') {
			begin = tmp;
		}
		if(begin && (*(tmp+1) == '\0' || *(tmp+1) == ' ')) {
			reverse(begin, tmp);
			begin = NULL;
		}
		tmp++;
	}

	reverse(str, tmp-1);
}

void main() {
	char str[] = " string not is a coena   af  ";
	printf("str:%s\n",str);
	reverse_words(str);
	printf("str:%s\n",str);
}
