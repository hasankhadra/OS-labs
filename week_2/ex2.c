#include <stdio.h>

const int MX = 1009;

int main(int argc, char const *argv[]){
    char s[MX];
    scanf("%s", &s);

	for(int i=0;i<strlen(s) / 2;i++){
		char tmp = s[strlen(s) - i - 1];
		s[strlen(s) - i - 1] = s[i];
		s[i] = tmp;
	}

    printf("%s\n", s);

	return 0;
}
