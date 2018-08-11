#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct{
    char *top;
    char *bottom;
    int stacksize;
}Sqstack;

int Initstack(Sqstack *s){
    s->bottom = ( char * )malloc( STACK_INIT_SIZE * sizeof(char) );
    if (! s->bottom)
        exit(-1);
    s->top = s->bottom;
    return 1;
}

int Push(Sqstack *s, char e){
    if (s->top - s->bottom >= s->stacksize){
        s->bottom = ( char * )realloc( s->bottom, (s->stacksize + STACKINCREMENT) * sizeof(char) );
        if ( ! s->bottom )
            exit(-2);
        s->top = s->bottom + s->stacksize;
        s->stacksize += STACKINCREMENT;
    }
    *s->top++ = e;
    return 1;
}

int Pop(Sqstack *s, char *e){
    if (s->top == s->bottom){
        return -1;
    }
    *e = * --s->top;
    return 1;
}

int StaticEmpty(Sqstack *s){
    if (s->top == s->bottom)
        return 1;
    else
        return 0;
}

int main()
{
    Sqstack s;
    int temp;
    char c = ' ';
    char d = ' ';
    Initstack(&s);
    while (c != 'e'){
        scanf("%c", &c);
        if (c == '{' || c == '[' || c == '(')
            temp = Push(&s, c);
        if (c == ')' || c == ']' || c == '}')
            temp = Pop(&s, &d);
    }
    if ( s.bottom == s.top ){
        printf("OK\n");
    }
    else
        printf("Error.\n");

    return 0;
}
