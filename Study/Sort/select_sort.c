#include <stdio.h>

void select_sort(int *x,int n){
    int i,min,j,t;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(*(x+j)<*(x+min)) min=j;
        }
        if(min!=i){
            t=*(x+i);
            *(x+i)=*(x+min);
            *(x+min)=t;
        }
    }
}

int main(){
    int myNum[]={87,14,65,64,23,46,34,43,35,66};
    int len=sizeof(myNum)/sizeof(myNum[0]);
    select_sort(myNum,len);
    for(int i=0;i<len;i++){
        printf("%d ",*(myNum+i));
    }
    printf("\n");
    return 0;
}