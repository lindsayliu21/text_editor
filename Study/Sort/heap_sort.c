#include <stdio.h>

void sift(int *x,int n,int s){
    int t,k,j;
    t=*(x+s);
    k=s;
    j=2*k+1;
    while(j<n){
        if(j<n-1&&*(x+j)<*(x+j+1)){
            j++;
        }
        if(t<*(x+j)){
            *(x+k)=*(x+j);
            k=j;
            j=2*k+1;
        }
        else{
            break;
        }
    }
    *(x+k)=t;
}

void heap_sort(int *x,int n){
    int i,j,t;
    for(i=n/2-1;i>=0;i--){
        sift(x,n,i);
    }
    for(j=n-1;j>=0;j--){
        t=*(x+0);
        *(x+0)=*(x+j);
        *(x+j)=t;
        sift(x,j,0);
    }
}

int main(){
    int myNum[]={87,14,65,64,23,46,34,43,35,66};
    int len=sizeof(myNum)/sizeof(myNum[0]);
    heap_sort(myNum,len);
    for(int i=0;i<len;i++){
        printf("%d ",*(myNum+i));
    }
    printf("\n");
    return 0;
}