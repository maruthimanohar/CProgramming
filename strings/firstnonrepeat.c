#include<stdio.h>
#include<string.h>
int firstnonrepeat(char *str) {
	/*first build the count array*/
	int arr[256] = {0};
	int i;
	for( i =0; i< strlen(str) ; i++) {
		arr[*(str+i)]++;
	}
	
	for(i=0; i< strlen(str); i++) {
		if(arr[*(str+i)] == 1) {
			return i;
		}
	}
	return -1;
	
}
void main() {
	char str[] = "stringstring";
	int index = firstnonrepeat(str);
	if(index == -1) {
		printf("All characters are repeating.\n");
	} else {
		printf(":%c:\n",str[index]);
	}
	
}
