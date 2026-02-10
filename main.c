#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termio.h>
#include <errno.h>

struct termios original_termios; 
//错误处理机制
void die(const char *msg){
    perror(msg);
    exit(1);
}

void disableRawMode(void){
    if(tcsetattr(STDIN_FILENO,TCSANOW,&original_termios)==-1){
        die("tcsetattr");
    }
}
void enableRawMode(void){
    if(tcgetattr(STDIN_FILENO,&original_termios)==-1){
        die("tcgetattr");
    }
    atexit(disableRawMode);
    struct termios raw=original_termios;
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    raw.c_oflag &= ~(OPOST);
    raw.c_cc[VMIN] = 0;   // 最少读取0个字符就返回
    raw.c_cc[VTIME] = 10;
    if(tcsetattr(STDIN_FILENO,TCSANOW,&raw)==-1){
        die("tcsetattr");
    }
}


int main(){
    //Level 1:终端原始模式
    enableRawMode();
    while(1){
        char c='\0';
        if(read(STDIN_FILENO,&c,1)==-1&&errno!=EAGAIN){
            die("read");
        }
        if(c=='q'){
            printf("\n检测到 'q'，退出程序...\n");
            break;
        }
        if(c!='\0'){
            // 判断是否为控制字符（ASCII 0-31 和 127）
            if (c <= 31 || c == 127) {
                // 控制字符的特殊显示
                if (c == 10) {  // 回车/换行
                    printf("按键: [回车/换行] ASCII: %d (0x%02x)\n", c, c);
                } else if (c == 27) {  // ESC
                    printf("按键: [ESC] ASCII: %d \n", c);
                } else if (c == 127) {  // 删除/退格
                    printf("按键: [删除/退格] ASCII: %d \n", c);
                } else if (c == 9) {  // Tab
                    printf("按键: [Tab] ASCII: %d \n", c);
                } else if (c == 4) {  // Ctrl+D (文件结束)
                    printf("按键: [Ctrl+D] ASCII: %d \n",c);
                } else if (c == 3) {  // Ctrl+C (中断)
                    printf("按键: [Ctrl+C] ASCII: %d \n", c);
                } else if (c == 26) {  // Ctrl+Z (挂起)
                    printf("按键: [Ctrl+Z] ASCII: %d \n", c);
                }else{
                    // 其他控制字符，显示为 ^ + 字母
                    printf("按键: [Ctrl+%c] ASCII: %d \n", c + 64, c);
                }
        }else{
            // 可打印字符
            printf("按键: '%c' ASCII: %d \n", c, c);
        }
    }
}
printf("程序正常结束。\n");
return 0;
}