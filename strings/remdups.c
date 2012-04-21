#include<stdio.h>
void removedups(char *str) {
	int i=0;
	char *curptr;
	int count[256] = {0};
	curptr = str;
	for(i=0; *(str+i) ; i++ ){
		if(count[*(str+i)] == 0) {
			*curptr++ = *(str+i);
		}
		count[*(str+i)]++;
	}
	*curptr = '\0';
}
void main() {
	char str[] = "geeksforgeeks";
	printf("%s\n",str);
	removedups(str);
	printf("%s\n",str);
}
