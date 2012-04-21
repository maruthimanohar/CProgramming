#include<stdio.h>

struct position{
	int a;
	int b;
};

int max(int a, int b) {
	return a>b?a:b;
}
void print(struct position *pos_array, int n) {
	int i=0;
	for(i = 0 ; i<=n ; i++) {
		printf("(%d,%d) ", pos_array[i].a, pos_array[i].b);
	}
	printf("\n");
}

void print_paths_util(int cur_m, int cur_n, int m, int n, struct position *pos_array, int cur) {
	/*push(cur_m,cur_n)(*/
	pos_array[cur].a = cur_m;
	pos_array[cur].b = cur_n;
	if(cur_m == m && cur_n == n) {
		print(pos_array, cur);
		return ;
	}
	if(cur_m != m) {
		print_paths_util(cur_m+1, cur_n, m, n, pos_array, cur+1);
	}
	if(cur_n != n) {
		print_paths_util(cur_m, cur_n+1, m, n, pos_array, cur+1);
	}
}

void print_paths(int m , int n) {
	struct position pos_array[m+n];
	int cur = 0;
	print_paths_util(0, 0, m-1, n-1 , pos_array, cur);
}

main() {
	print_paths(3,2);
}
