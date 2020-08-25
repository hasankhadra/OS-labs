#include <stdio.h>

void draw_triangle(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<=(n + i - 1);j++){
			if(j < n - i - 1){ // Left empty
				printf(" ");
				continue;
			}

			// Part of the triangle
            printf("*");
		}

		// A new line
		puts("");
	}
}

int n;

int main(int argc, char const *argv[]){
	scanf("%d", &n);
	draw_triangle(n);
	return 0;
}
