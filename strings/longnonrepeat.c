#include<stdio.h>
#include<string.h>
void longestnonrepeat(char *str) {
	int curstart = -1, maxstart = -1;
	int curlen = -1, maxlen = -1;
	int index[256] = {-1};
	int i, len = strlen(str);
	int prev;
	for(i=0;i<len;i++) {
		prev = index[*(str+i)];
		if(prev >= curstart) {
			if(maxlen < curlen ) {
				maxlen = curlen;
				maxstart = curstart;
			}
			curstart = i;
		} else {
			curlen = (i - curstart) +1;
		}
		index[*(str+i)] = i;
	}
	if(maxlen > -1) {
		printf("maxlen :%d\n",maxlen);
		for(i=0; i<maxlen; i++) {
			printf("%c",*(str+maxstart+i));
		}
		printf("\n");
	} else {
		printf("no such string\n");
	}
	
}
void main() {
	char str[] = "geeksforgeeks";
	longestnonrepeat(str);
}
