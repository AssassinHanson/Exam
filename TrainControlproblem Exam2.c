#include <stdio.h>
#include <stdlib.h>

typedef int SElemType;
typedef int Status;
long total = 0;
int N ;

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
    *s->top++=e;
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

void process(SqStack *temp, SqStack *output, SElemType n){
    if(n <= N){
        Push(temp, n);
        process(temp, output, n+1);
        Pop(temp);
    }
    if(!Empty(temp)){
        Push(output, Pop(temp));
        process(temp, output, n);
        Push(temp, Pop(output));
    }
    else if(n > N){
        total++;
        Print(output);
    }
}


int main()
{
    SqStack temp, output;
    Init(&temp);
    Init(&output);

    printf("please input max number of train:");
    scanf("%d",&N);
    printf("\nthe result is:\n\n");

    process(&temp, &output, 1);

}









