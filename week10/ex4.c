#include <errno.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

typedef struct{
    ino_t inode;
    char names[128];
    nlink_t links;
}fileEntry;

unsigned int cnt = 0;
int found = 0;
fileEntry Enn[128];
struct stat es;
struct dirent *de;

int main(){
    DIR *dir=opendir("tmp");
    while((de=readdir(dir))!=0){
        char fileName[32];
        strcpy(fileName, "tmp/");
        strcat(fileName, de->d_name);
        if(stat(fileName, &es)!=0)return ENOENT;
        found=0;
        for(int i=0;i<cnt;i++){
            if(Enn[i].inode==es.st_ino){
                found=1;
                strcat(strcat(Enn[i].names, ", "), de->d_name);
                Enn[i].links++;
                break;
            }
        }
        if(found)continue;
        fileEntry x;
        x.links=1;
        x.inode=es.st_ino;
        strcpy(x.names, de->d_name);
        Enn[cnt++]=x;
    }
    closedir(dir);
    for(int j=0;j<cnt;j++) if(Enn[j].links>1) printf("The files %s have the inode: %llu\n", Enn[j].names, Enn[j].inode);
    return 0;
}


