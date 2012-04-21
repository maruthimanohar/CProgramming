#include<stdio.h>
#include<string.h>
int isgreater(int *a, int* b) {
	int i = 0;
	for(i = 0; i< 256 ; i++) {
		if(a[i] < b[i])
			return 0;
	}
	return 1;
}
void smallest_window(char *str1, char *str2) {
	int count_arr1[256] = {0} , count_arr2[256] = {0};
	int i, j, contains = 0;
	int minstart =0, minend=strlen(str1);
	int curstart;
	if(strlen(str2) == 0) {
		printf("string2 is empty.\n");
	}
	for (i =0; i<strlen(str2); i++) {
		count_arr2[*(str2+i)]++;
	}

	for(i=0; i<strlen(str1) ; i++) {
		if(count_arr2[*(str2+i)] > 0 ) {
			curstart = i;
			break ;
		}
	}

	for(j=i; j <strlen(str1) ; j++) {
		count_arr1[*(str1+j)]++;
		if(isgreater(count_arr1, count_arr2) ) {
			contains = 1;	
			if(*(str1+j) == *(str1+curstart)) {
				while(count_arr1[*(str1 + curstart)] > count_arr2[*(str1 + curstart)]) {
					count_arr1[*(str1+curstart)]--;
					curstart++;
				}
			}
			
			if((j - curstart) < (minend - minstart)) {
				minend = j;
				minstart = curstart;
			}
		} 
		
	}
	if(contains == 0) {
		printf("The string1 does not contain all the chars of string2\n");
	} else {
		for(i = minstart ; i<= minend ;i++) {
			printf("%c",str1[i]);
		}
		printf("\n");
	}

}
void main() {
	char str1[] = "this is a test string";
	char str2[] = "";
	printf("%s\n",str1);
	printf("len:%d\n",strlen(str1));
	smallest_window(str1, str2);
}
