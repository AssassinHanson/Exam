#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int weight;
   	char ch;
    int parent,lchild,rchild;
}HTNode,*HuffmanTree;


typedef char **HuffmanCode;

HuffmanTree HT;
int n=0;
HuffmanCode HC;
int *w;
char *ch;
char *pFile;
char **CodeFile;
int l=0;
char *TextFile;


void welcome();
void select(HuffmanTree HT,int j,int &s1,int &s2);
void Init();
void Encoding();
void Decoding();
void Tree_printing();
void Print();
void HuffmanCoding(HuffmanTree&HT,HuffmanCode &HC,int *w,int n,char *ch);
void Free();

void welcome()
{
	printf("**************************************\n");
	printf("*          请选择如下操作            *\n");
	printf("*            I.初始化                *\n");
	printf("*            E.编码                  *\n");
	printf("*            D.译码                  *\n");
	printf("*            P.印代码文件            *\n");
	printf("*            T.打印哈夫曼树          *\n");
	printf("*            Q.退出                  *\n");
	printf("**************************************\n");
}


void Init()
{
	int i;
	printf("请输入字符个数:\n");
	scanf("%d",&n);
	while(n<2){
		printf("输入的数据有误，请重新输入:\n");
		scanf("%d",&n);
	}
	ch=(char *)malloc(n*sizeof(char));
	printf("请输入所有字符:\n");
	getchar();
	for(i=0;i<n;++i)
		scanf("%c",&ch[i]);
	w=(int *)malloc(n*sizeof(int));
	printf("请输入这些字符的权值:\n");
	for(i=0;i<n;++i)
		scanf("%d",&w[i]);
	HuffmanCoding(HT,HC,w,n,ch);

	/*n=5;
	int i;
	char c[5+1]="abcde";
	int b[5]={1,2,3,4,5};
	HuffmanCoding(HT,HC,b,n,c);

	printf("编码结果如下:\n");
	for(i=1;i<=n;++i)
		printf("%c:%s\n",HT[i].ch,HC[i]);*///测试用

	printf("初始化成功\n");
}

void select(HuffmanTree HT,int j,int &s1,int &s2)
{
	int i;
	for(i=1;i<=j;i++)
		if(HT[i].parent==0){s1=i;break;}
	for (;i<=j;i++)
   		if ((HT[i].parent==0)&&(HT[i].weight<HT[s1].weight))
    		s1=i;
  	HT[s1].parent=1;
	for(i=1;i<=j;i++)
   		if(HT[i].parent==0){s2=i;break;}
	for(;i<=j;i++)
   		if((HT[i].parent==0)&&(i!=s1)&&(HT[i].weight<HT[s2].weight))
    		s2=i;
}


void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n,char *ch)
{
	int m;
	m=2*n-1;
	int s1,s2;
	HT=(HTNode *)malloc((m+1)*sizeof(HTNode));
	HTNode *p;
	int i;
	for(p=HT+1,i=1;i<=n;++p,++i,++w,++ch){
		p->ch=*ch;
		p->weight=*w;
		p->parent=p->lchild=p->rchild=0;
	}
	for(;i<=m;++i,++p){
		p->ch=0;
		p->weight=0;
		p->parent=p->lchild=p->rchild=0;
	}
	for(i=n+1;i<=m;++i){
		select(HT,i-1,s1,s2);
		HT[s1].parent=i;HT[s2].parent=i;
		HT[i].lchild=s1;HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
	}
	HC=(char**)malloc((n+1)*sizeof(char*));
	char *cd;
	cd=(char *)malloc(n*sizeof(char));
	cd[n-1]='\0';
	int start,c,f;
	for(i=1;i<=n;++i){
		start=n-1;
		for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent){
			if(HT[f].lchild==c) cd[--start]='0';
			else cd[--start]='1';
		}
		HC[i]=(char *)malloc((n-start)*sizeof(char));
		strcpy(HC[i],&cd[start]);
	}
	free(cd);
}

void Encoding()
{
	int i, j;

    printf("请输入字符个数:\n");
	scanf("%d",&l);
	while(l<2){
		printf("输入的数据有误，请重新输入:\n");
		scanf("%d",&l);
	}
	pFile=(char *)malloc(l*sizeof(char));
	printf("请输入所有字符:\n");
	getchar();
	for(i=0;i<l;++i)
		scanf("%c",&pFile[i]);

    /*l=6;
    pFile=(char *)malloc(l*sizeof(char));
    strcpy(pFile,"abcdea");*///测试用

    CodeFile = (char **)malloc((l) * sizeof(char *));
    for(i = 0; i <l; i++){
        for(j = 1; pFile[i] != HT[j].ch; j++);
        CodeFile[i]=(char *)malloc(sizeof(HC[j]));
        strcpy(CodeFile[i], HC[j]);
    }

    /*for(i=0;i<l;i++){
        printf("%c:%s\n",pFile[i],CodeFile[i]);
    }*///测试用

    printf("编码成功\n");
}

void Decoding()
{
	int i, j;

    TextFile=(char *)malloc(l*sizeof(char));
    for(i = 0; i < l; i++){
        for(j=1; strcmp(CodeFile[i], HC[j]); j++);
        TextFile[i] = HT[j].ch;
    }

    /*for(i=0;i<l;i++){
        printf("%c",TextFile[i]);
    }*///测试用

    printf("\n译码成功\n");
}


void Print()
{
	int i,j;
	int maxsize = 10;
    char *temp;
    temp = (char *)malloc(maxsize * sizeof(char));
    CodePrin = (char **)malloc(sizeof(char*));

    strcpy(temp,CodeFile[0]);
    for(i = 1; i < l; i++){
        if(maxsize <= (sizeof(temp) + sizeof(CodeFile[i]))){
            temp = (char *)realloc(temp, maxsize * sizeof(char) + sizeof(CodeFile[i]));
            maxsize += sizeof(CodeFile[i]);
        }
        strcat(temp, CodeFile[i]);
    }

    int m = 50;
    printf("代码为：\n");
    for(i = 0, j = 0; temp[i] != '\0'; i++){
        if(i%m == 0){
            printf("\n");
            j++;
        }
        printf("%c", temp[i]);
    }
    printf("\n");
}

void Tree_printing()
{
	int i;
	printf("ch weight  parent  lchild  rchild\n");
	for(i=1;i<2*n;i++){
		printf("%c%8d%8d%8d%8d\n",HT[i].ch,HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
	}
}

void Free()
{
	free(HT);
	free(HC);
	free(w);
	free(ch);
}



int main()
{
	char choice;
	while(1)
	{
	   welcome();
	   scanf("%c",&choice);
	   switch(choice)
	   {
		case 'i':
		case 'I':Init();break;
		case 'e':
		case 'E':Encoding();break;
		case 'd':
		case 'D':Decoding();break;
		case 'p':
		case 'P':Print();break;
		case 't':
		case 'T':Tree_printing();break;
		case 'q':
		case 'Q':Free();exit(1);
		default :printf("Input error!\n");
	   }
		getchar();
	}
return 0;
}














