#include <stdio.h>
int main() {
  enum 
  {  
    R=2,G,B
  }  rgb;  
  rgb=B;
  printf("%d\n",rgb);
  return 0;
}