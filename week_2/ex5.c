#include <stdio.h>

void draw_right_triangle(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
            printf("*");
		}
		puts("");
	}
}

void draw_half_triangles(int n){

    // First half
    for(int i=1;i<=n/2;i++){
		for(int j=1;j<=i;j++){
            printf("*");
		}
		puts("");
	}

	// Second half
    for(int i=(n - n/2);i>=1;i--){
		for(int j=1;j<=i;j++){
            printf("*");
		}
		puts("");
	}
}

void draw_square(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("*");
        }
        puts("");
    }
}

void draw_shape(int n, int t){
    if(t == 1){ // Figure 1
        draw_right_triangle(n);
    }
    else if(t == 2){ // Figure 2
        draw_half_triangles(n);
    }
    else if(t == 3){ // Figure 3
        draw_square(n);
    }
}

int n, type;

int main(int argc, char const *argv[]){
    puts("Enter the number of lines and the type of the drawing:");
	scanf("%d %d", &n, &type);
	draw_shape(n, type);
	return 0;
}
