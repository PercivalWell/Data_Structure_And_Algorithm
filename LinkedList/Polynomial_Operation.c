#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 100
typedef struct Polynomial{
    int exp;
    int coe;
    struct Polynomial *next;
}Polynomial;

static Polynomial *Poly[MAXSIZE];

void PolynomialCreat(){
    int n;
    int j = 0;
    int i;
    int temp;
    Polynomial *p = (Polynomial *)malloc( sizeof(Polynomial) );
    p->next = NULL;
    Polynomial *t = p;
    printf("Input the number of the polynomial.\n");
    scanf("%d", &i);
    Poly[i] = p;
    printf("Input the number of the terms.\n");
    scanf("%d", &n);
    p->coe = n;
    while (j < n){
        printf("Input the coefficient of the No.%d term.\n", j);
        scanf("%d", &temp);
        if (temp){
            t->next = (Polynomial *)malloc( sizeof(Polynomial) );
            t = t->next;
            t->next = NULL;
            t->coe = temp;
        }
        else{
            j++;
            continue;
        }
        printf("Input the exponential of the NO.%d term.\n", j);
        scanf("%d", &t->exp);
        j++;
    }
}

void PolynomialPutOut(Polynomial *p){
    Polynomial *s = p->next;
    printf("The polynomial is ");
    while (s){
        if (s->coe > 0 && p->next != s)    printf("+ %d", s->coe);
        else if (s->coe < 0 && p->next != s)    printf("- %d", 0 - s->coe);
        else if (s == p->next)             printf("%d", s->coe);

        if (s->exp == 0)                        printf(" ");
        if (s->exp > 0)                         printf("*x^%d ", s->exp);
        if (s->exp < 0)                         printf("*x^(%d) ", s->exp);
        s = s->next;
    }
    printf("\n");
}

void PolynomialReverse(Polynomial *p){
    Polynomial *t = p->next;
    Polynomial *q;
    if (!t){
        return ;
    }
    q = t;
    t = t->next;
    q->next = NULL;
    while (t){
        q = t;
        t = t->next;
        q->next = p->next;
        p->next = q;
    }
}

double PolynomialWorkout(Polynomial *p){
    if (p->next->exp > p->next->next->exp) //如果多项式按降序排列,则逆置;
        PolynomialReverse(p);
    Polynomial *t = p->next;
    int n = p->coe;
    int pro_exp;
    double multiply;
    double x;
    double sum = 0;
    printf("Input the value of the unknown: ");
    scanf("%lf", &x);
    multiply = pow(x, t->exp);
    pro_exp = t->exp;
    while (t){
        while (t->exp - pro_exp){
            multiply *= x;
            pro_exp++;
        }
        sum += t->coe * multiply;
        t = t->next;
        n--;
    }
    return sum;
}

Polynomial *PolynomialSum(Polynomial *p1, Polynomial *p2){
    if (p1->next->exp > p1->next->next->exp)                    //如果多项式按降序排列,则逆置;
        PolynomialReverse(p1);
    if (p2->next->exp > p2->next->next->exp)
        PolynomialReverse(p2);

    Polynomial *a = p1->next, *b = p2->next, *c1;
    Polynomial *c = (Polynomial *)malloc( sizeof(Polynomial) );
    c1 = c;
    while (a && b){
        c1->next = (Polynomial *)malloc( sizeof(Polynomial) );
        c1 = c1->next;
        if (a->exp < b->exp){
            c1->coe = a->coe;
            c1->exp = a->exp;
            a = a->next;
        }
        else if (a->exp == b->exp){
            c1->coe = a->coe + b->coe;
            c1->exp = a->exp;
            a = a->next;
            b = b->next;
        }
        else{
            c1->coe = b->coe;
            c1->exp = b->exp;
            b = b->next;
        }
        c1->next = NULL;
    }
    if (a){
        c1->next = a;
    }
    if (b){
        c1->next = b;
    }

    return c;
}

void DeleteTheSameElement(Polynomial *p1, Polynomial *p2, Polynomial *p3){
    if (p1->next->exp > p1->next->next->exp) //如果多项式按降序排列,则逆置;
        PolynomialReverse(p1);
    if (p2->next->exp > p2->next->next->exp)
        PolynomialReverse(p2);
    if (p3->next->exp > p3->next->next->exp)
        PolynomialReverse(p3);
    Polynomial *a = p1->next, *a1 = p1, *b = p2->next, *c = p3->next, *temp;




}

void DrawMenu(){
    printf("-------------------------MENU-------------------------\n");
    printf("| 1.Input the polynomial by ascending order.         |\n");
    printf("| 2.Out put the polynomial.                          |\n");
    printf("| 3.Reverse the polynomial.                          |\n");
    printf("| 4.Workout the polynomial at a sercain value.       |\n");
    printf("| 5.Add the two polynomials.                         |\n");
    printf("| 6.Delete the same element.                         |\n");
    printf("| 7.Quit.                                            |\n");
    printf("|----------------------------------------------------|\n");
}

void Menu(){
    int choise;
    int l, m, n;
    int flag = 1;
    double outcome;

    while (flag != 100){
        DrawMenu();
        scanf("%d", &choise);
        switch(choise){
            case 1:
                PolynomialCreat();
                break;
            case 2:
                printf("Select the polynomial you want to putout. The number begins at 0.\n");
                scanf("%d", &n);
                Polynomial *temp2 = Poly[n];
                PolynomialPutOut(temp2);
                break;
            case 3:
                printf("Select the polynomial you want to reverse. The number begins at 0.\n");
                scanf("%d", &n);
                Polynomial *temp3 = Poly[n];
                PolynomialReverse(temp3);
                break;
            case 4:
                printf("Select the polynomial you want to workout. The number begins at 0.\n");
                scanf("%d", &n);
                Polynomial *temp4 = Poly[n];
                outcome = PolynomialWorkout(temp4);
                printf("The result is %lf.\n", outcome);
                break;
            case 5:
                printf("Select the two polynomials you want to add up. The number begins at 0.\n");
                scanf("%d%d", &m, &n);
                Polynomial *temp51 = Poly[m], *temp52 = Poly[n], *temp53 = NULL;
                temp53 = PolynomialSum(temp51, temp52);
                PolynomialPutOut(temp53);
                break;
            case 6:
                printf("Select the polynomial you want delete some elements. The number begins at 0.\n");
                scanf("%d", &l);
                Polynomial *temp61 = Poly[l];
                printf("Select the two polynomials where the elements are from. The number begins at 0.\n"); //Terrible Chglish.
                scanf("%d%d", &m, &n);
                Polynomial *temp62 = Poly[m], *temp63 = Poly[n];
                DeleteTheSameElement(temp61, temp62, temp63);
                PolynomialPutOut(temp61);
                break;
            case 7:
                flag = 100;
                break;
        }
    }
}
int main()
{
    Menu();
    return 0;
}
