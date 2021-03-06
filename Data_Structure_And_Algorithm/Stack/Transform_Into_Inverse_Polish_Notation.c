#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct Stack_list{
    char list[MAXSIZE];
    int top;
} Stack_list;

int JudgePriority(char ch1, char ch2){   // ch1 <= ch2 ? 0 : 1;
    if      ( (ch1 == '+' || ch1 == '-') && (ch2 == '*' || ch2 == '/') ) return 1;
    else if ( (ch1 == '+' || ch1 == '-') && (ch2 == '+' || ch2 == '-') ) return 0;
    else if ( (ch1 == '*' || ch1 == '/') && (ch2 == '+' || ch2 == '-') ) return 0;
    else if ( (ch1 == '*' || ch1 == '/') && (ch2 == '*' || ch2 == '/') ) return 0;
}


int main()
{
   Stack_list s;
   s.top = 0;
   char ch;
   char list[MAXSIZE];
   int i = 0;
   int j = 0;
   while ((ch = getchar()) != '@'){
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')'){
            if (ch == '('){
                s.list[s.top] = ch;
                s.top++;
            }
            else if (ch == ')'){
                while (s.list[--s.top] != '('){  //s.top Ö¸ÏòÕ»¶¥ÉÏÃæÒ»¸ö¿Õ¼ä
                    list[i] = s.list[s.top];
                    i++;
                }
            }
            else if (s.top == 0){
                s.list[s.top] = ch;
                s.top++;
            }
            else if ( JudgePriority(s.list[s.top-1], ch) ){
                s.list[s.top] = ch;
                s.top++;
            }
            else if ( !JudgePriority(s.list[s.top-1], ch) ){
                while (s.top--){
                    list[i] = s.list[s.top];
                    i++;
                }
            }
        }
        else {
            list[i] = ch;
            i++;
        }
   }
    while (s.top){
        s.top--;
        list[i] = s.list[s.top];
        i++;
    }

    for (j = 0; j < i; j++){
        printf("%c", list[j]);
    }
    return 0;
}


/*学会使用函数: 将(稍微)复杂的判断优先级拿出来作为独立的函数,可以简化思维过程.*/
/*2018年3月28日23:36:12*/
