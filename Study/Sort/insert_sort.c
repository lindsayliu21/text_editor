#include <stdio.h>

void insert_sort(int *x,int n){
int i,j,t;
for(i=1;i<n;i++){
    t=*(x+i);
    for(j=i-1;j>=0&&t<*(x+j);j--){
        *(x+j+1)=*(x+j);
    }
    *(x+j+1)=t;
}
}
int main(){
    int myNum[]={87,14,65,64,23,46,34,43,35,66};
    int len=sizeof(myNum)/sizeof(myNum[0]);
    insert_sort(myNum,len);
    for(int i=0;i<len;i++){
        printf("%d ",*(myNum+i));
    }
    printf("\n");
    return 0;
}