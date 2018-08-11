#include <stdio.h>
#include <stdlib.h>
typedef struct LinkedList{
    int data;
    struct LinkedList *next;
}LNode;

LNode *DeleteTheSameElement(LNode *p1, LNode *p2, LNode *p3){
    LNode *t = NULL, *t1 = NULL,*a = p1->next, *a1 = p1, *b = p2->next, *c = p3->next, *temp;
    t = (LNode *)malloc( sizeof(LNode) );
    t->next = NULL;
    t1 = t;
    while (b && c){
        if (b->data == c->data){
            t1->next = (LNode *)malloc( sizeof(LNode) );
            t1 = t1->next;
            t1->next = NULL;
            t1->data = b->data;
            b = b->next;
            c = c->next;
        }
        else if (b->data < c->data){
            b = b->next;
        }
        else if (b->data > c->data){
            c = c->next;
        }
    }
    t1 = t->next;
    while (a && t1){
        if (a->data == t1->data){
            temp = a;
            a = a->next;
            a1->next = a;
            free(temp);
        }
        else if (a->data < t1->data){
            a = a->next;
            a1 = a1->next;
        }
        else if (a->data > t1->data)
            t1 = t1->next;
    }

    return p1;
}
int main()
{
    int l1, l2, l3;
    LNode *test1, *test2, *test3;
    test1 = (LNode *)malloc( sizeof(LNode) );
    test1->next = NULL;
    test2 = (LNode *)malloc( sizeof(LNode) );
    test2->next = NULL;
    test3 = (LNode *)malloc( sizeof(LNode) );
    test3->next = NULL;

    LNode *a = test1, *b = test2, *c = test3;
    printf("Length.\n");
    scanf("%d%d%d", &l1, &l2, &l3);
    while (l1){
        a->next = (LNode *)malloc( sizeof(LNode) );
        a = a->next;
        a->next = NULL;
        scanf("%d", &a->data);
        l1--;
    }
    printf("Over.\n");
    while (l2){
        b->next = (LNode *)malloc( sizeof(LNode) );
        b = b->next;
        b->next = NULL;
        scanf("%d", &b->data);
        l2--;
    }
    printf("Over.\n");
    while (l3){
        c->next = (LNode *)malloc( sizeof(LNode) );
        c = c->next;
        c->next = NULL;
        scanf("%d", &c->data);
        l3--;
    }
    printf("Over.\n");
    test1 = DeleteTheSameElement(test1, test2, test3);
    a = test1->next;
    while (a){
        printf("%d ", a->data);
        a = a->next;
    }
    return 0;
}
