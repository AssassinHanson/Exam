#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    int num;
    struct LNode *next;
}LNode,*LinkList;



int main()
{
    char c;
    int n,m,i,j;
    LinkList L,p,pt,qt;
    while(1)
    {
        printf("请输入人数：");
        scanf("%d",&n);
        if(n>0) break;
    }
    printf("\n");
    p=(LinkList)malloc(sizeof(LNode));
    p->next=NULL;
    L=p;
    pt=L;
    qt=L;
    while(1)
    {
        printf("请输入初始报数上限：");
        scanf("%d",&m);
        if(m>0) break;
    }
    printf("\n");
    p->num=1;
    while(1)
    {
        printf("请输入第1个人的密码：");
        scanf("%d",&pt->data);
        if(pt->data>0)  break;
    }
    for(i=1;i<n;i++)
    {
        p=(LinkList)malloc(sizeof(LNode));
        p->next=pt->next;
        pt->next=p;
        pt=p;
        p->num=i+1;
        while(1)
        {
            printf("请输入第%d个人的密码：",i+1);
            scanf("%d",&pt->data);
            if(pt->data>0)  break;
        }
    }
    pt->next=L;
    printf("\n以下是按顺序输出的序号：\n");
    while(pt!=pt->next)
    {
    for(i=1;i<m;i++)
    {
        pt=pt->next;
    }
    p=pt->next;
    pt->next=pt->next->next;
    printf("%d->",p->num);
    m=p->data;
    free(p);
    }
    printf("%d",pt->num);
    free(pt);
}




















