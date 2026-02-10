#include <stdio.h>
#include <string.h>
enum FilePermissions{
    READ=1<<0,
    WRITE=1<<1,
    EXECUTE=1<<2
};

void CheckPermissions(int Permissions){
    if(Permissions&READ){
        printf("Read permission is set.\n");
    }
    if(Permissions&WRITE){
        printf("Write permission is set.\n");
    }
    if(Permissions&EXECUTE){
        printf("Execute permission is set.\n");
    }
}

int main(int argc,char *argv[]){
    int permissions=0;
    if(argc!=2){
        printf("Usage: %s <string>\n",argv[0]);
        printf("Supported permissions: r (read), w (read+write), e (execute)\n");
        return 1;
    }
    if(strcmp(argv[1],"r")==0){
        permissions=READ;
    }
    else if(strcmp(argv[1],"w")==0){
        permissions=READ|WRITE;
    }
    else if(strcmp(argv[1],"e")==0){
        permissions=EXECUTE;
    }
    CheckPermissions(permissions);
    return 0;
    
}