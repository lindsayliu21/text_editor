#include <stdio.h>

void shell_sort(int *x,int n){
    int i,j,t,h;
    for(h=n/2;h>0;h=h/2){
        for(i=h;i<n;i++){
            t=*(x+i);
            for(j=i-h;j>=0&&t<*(x+j);j-=h){
                *(x+j+h)=*(x+j);
            }
            *(x+j+h)=t;
        }
    }
}
int main(){
    int myNum[]={87,14,65,64,23,46,34,43,35,66};
    int len=sizeof(myNum)/sizeof(myNum[0]);
    shell_sort(myNum,len);
    for(int i=0;i<len;i++){
        printf("%d ",*(myNum+i));
    }
    printf("\n");
    return 0;
}