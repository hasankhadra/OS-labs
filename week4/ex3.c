#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char command[20];
int main(){


    printf("Session@admin: ");
    fgets(command, sizeof(command),stdin);
    if(strcmp("exit\n", command) == 0) return 0;

    do{
        fork();
        system(command);
        printf("Session@admin: ");
        fgets(command, sizeof(command),stdin);
    }while(strcmp("exit\n", command) != 0);
}