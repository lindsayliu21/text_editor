#include <stdio.h>
#include <string.h>
int main(int argc,char *argv[]){
    if(argc!=2){
        printf("Usage: %s <string>\n",argv[0]);
        return 1;
    }
    if(strcmp(argv[1],"--help")==0){
        printf("一些命令...\n");
    }
    return 0;
}