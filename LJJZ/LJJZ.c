#include<stdio.h>
#include"stdlib.h"
typedef char elemtype;
#define MAXSIZE 100
//创建邻接表的结构体
typedef struct
{
	elemtype vex[MAXSIZE];//顶点表
	int data[MAXSIZE];//顶点数组 
	int arc[MAXSIZE][MAXSIZE];//邻接矩阵 
	int vexnum, edgenum;//当前的定点数和边数 
}MGraph;
//void creategraph(MGraph* p) 
//{
//    int i, j, k;
//    elemtype v1, v2;
//    printf("请输入顶点数和边数：\n");
//    printf("顶点数n="); scanf("%d", &p->vexnum);
//    printf("边  数e="); scanf("%d", &p->edgenum);
//    printf("请输入图的顶点信息：\n");
//    getchar();
//    for (i = 0; i <= p->vexnum; i++)
//        scanf("%c", &p->data[i]);
//    for (i = 0; i < p->vexnum; i++)
//        for (j = 0; j < p->vexnum; j++)
//            p->arc[i][j] = 0;//初始化邻接矩阵
//    printf("请输入图的边的信息：\n");
//    for (k = 0; k < p->edgenum; k++)
//    {
//        printf("请输入第%d条边的两个端点：", k + 1);
//        scanf("%c%c", &v1, &v2);
//        fflush(stdin);//清空输入缓冲区
//        i = locatevex(*p, v1); j = locatevex(*p, v2);
//        if (i >= 0 && j >= 0) {
//            p->arc[i][j] = 1;
//            p->arc[j][i] = 1;//无向网矩阵对称
//        }
//    }
//在图中查找顶点v,存在返回其在顶点数组中的下标，不存在返回-1
//int locatevex(MGraph p, elemtype v)
//{
//	int i;
//    for (i = 0; i < p.vexnum; i++)if (p.vex[i] == v)return i;
//    return -1;
//}
void CreateMgrapg(MGraph* p)//无向图
{
	int i, j, k, w;
	printf("输入定点数和边数\n");
	scanf("%d%d", &p->vexnum, &p->edgenum);
	getchar();
	for (i = 0; i < p->vexnum; i++)
	{
		printf("输入第%d个顶点的信息\n", i + 1);
		scanf("%d", &p->data[i]);
	}
	for (i = 0; i < p->vexnum; i++)
	{
		for (k = 0; k < p->vexnum; k++)
		{
			p->arc[i][k] = 0;
		}
	}
	for (k = 0; k < p->edgenum; k++)
	{
		printf("输入有关系的两个顶点\n");
		scanf("%d%d%d", &i, &j, &w);
		//fflush(stdin);//清空输入缓冲区
		//i= locatevex(*p,&i);j= locatevex(*p, &j);
		p->arc[i-1][j-1] = w;
		p->arc[j-1][i-1] = w;
	}
}
//打印信息
    void print(MGraph p)
{
	int i, j;
	for (i = 0; i < p.vexnum; i++)
	{
		for (j = 0; j < p.vexnum; j++)
		{
			printf("%-10d", p.arc[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	MGraph p;
	CreateMgrapg(&p);
	print(p);
}