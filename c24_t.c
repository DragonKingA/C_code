#include <stdio.h>
int *p;
void f(int *p){
    switch(*p/10){
            case 10:
            case 9:
                printf("A\n");
                break;
            case 8:
                printf("B\n");
                break;
            case 7:
                printf("C\n");
                break;
            case 6:
                printf("D\n");
                break;
            default:
                printf("E\n");
                break;
        }
}
int main(){
    int x;
    while(scanf("%d",&x) != EOF){//死循环内scanf读入的必写语句，防止scanf直接读取缓存区原值，而不经过用户输入
        
        p = &x;
        if(!(*p >= 0 && *p <= 100)){
            printf("Score is error!\n");
            continue;
        }
        f(p);
    }
    return 0;
}
