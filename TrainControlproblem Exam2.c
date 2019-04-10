#include <stdio.h>
#include <stdlib.h>

typedef int SElemType;
typedef int Status;
long total = 0;
int N = 5;

typedef struct{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

void Init(SqStack *s){
    s->base=(SElemType *)malloc(N * sizeof(SElemType));
    if(!s->base) exit(0);

    s->top=s->base;
    s->stacksize=N;
}

Status Push(SqStack *s, SElemType e){
    if(s->top - s->base >= s->stacksize){
        s->base = (SElemType *)realloc(s->base, (s->stacksize + N) * sizeof(SElemType));
        if(!s->base) exit(0);
        s->top = s->base + s->stacksize;
        s->stacksize += N;
    }
    *s->top=e;
    s->top++;
}

SElemType Pop(SqStack *s){
    if(s->top==s->base) return 0;

    return *--s->top;
}

Status Empty(SqStack *s){
    if(s->top==s->base) return 1;
    else return 0;
}


void Print(SqStack *s){
    SElemType *p;
    p=s->base;

    printf("%5ld: ", total);
    while(p!=s->top){
        printf("%3d", *p++);
    }
    printf("\n");
}

void process(SqStack *temp, SqStack *output, SElemType n, SElemType m){
    if(n <= m){
        Push(temp, n);
        process(temp, output, n+1, m);
        Pop(temp);
    }
    if(!Empty(temp)){
        Push(output, Pop(temp));
        process(temp, output, n, m);
        Push(temp, Pop(output));
    }
    else if(n > m){
        total++;
        Print(output);
    }
}


int main()
{   int m;
    SqStack temp, output;
    Init(&temp);
    Init(&output);

    printf("please input max number of train:");
    scanf("%d",&m);
    printf("\nthe result is:\n\n");

    process(&temp, &output, 1, m);

}









