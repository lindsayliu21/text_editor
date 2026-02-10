# include<stdio.h>
void bubble_sort(int *x,int n){
    int i,j,t;
    for(i=1;i<n;i++){
        for(j=0;j<n-i;j++){
            if(*(x+j)>*(x+j+1)){
                t=*(x+j);
                *(x+j)=*(x+j+1);
                *(x+j+1)=t;
            }
        }
    }
}
int main(){
    int myNum[]={87,14,65,64,23,46,34,43,35,66};
    int len=sizeof(myNum)/sizeof(myNum[0]);
    bubble_sort(myNum,len);
    for(int i=0;i<len;i++){
        printf("%d ",*(myNum+i));
    }
    printf("\n");
    return 0;
}