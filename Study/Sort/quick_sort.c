#include <stdio.h>
void quick_sort(int *x,int low,int high){
    int i,j,t;
    if(low<high){
        i=low;
        j=high;
        t=*(x+i);
        while(i<j){
            while(i<j&&*(x+j)>t){
                j--;
            }
            if(i<j){
                *(x+i)=*(x+j);
                i++;
            }
            while(i<j&&*(x+i)<=t){
                i++;
            }
            if(i<j){
                *(x+j)=*(x+i);
                j--;
            }
        }
        if(i==j){
            *(x+i)=t;
        }
        quick_sort(x,low,i-1);
        quick_sort(x,i+1,high);
    }

}

int main(){
    int myNum[]={87,14,65,64,23,46,34,43,35,66};
    int len=sizeof(myNum)/sizeof(myNum[0]);
    quick_sort(myNum,0,len-1);
    for(int i=0;i<len;i++){
        printf("%d ",*(myNum+i));
    }
    printf("\n");
    return 0;
}