#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MaxV 20
//创建邻接表的结构体
typedef struct ArcNode {//边结点
	int adjvex;//该边所指向的顶点在数组中的位置
	struct ArcNode* nextarc;//指向下一条边的指针
}ArcNode;

typedef struct VNode {//顶点信息（顶点作为每个单链表的表头结点）
	int data;
	ArcNode* firstarc;//指向第一条依附该顶点的边的指针
}AdjList[MaxV];
typedef struct {
	AdjList vertices;
	int vexnum, arcnum;//图的当前顶点数和边数
	int kind;//分成无向图和有向图
}ALGraph;
void InitALGraph(ALGraph* G, int vexnum, int arcnum) {//顶点个数和边数
	G->vexnum = vexnum;
	G->arcnum = arcnum;
	for (int i = 0; i < G->vexnum; i++) {//给顶点赋值，建立表头结点
		scanf("%d", &G->vertices[i].data);
		G->vertices[i].firstarc = NULL;
	}
	for (int k = 0; k < G->arcnum; k++) {
		int v1 = 0;//每条边关联两个顶点
		int v2 = 0;
		scanf("%d%d", &v1, &v2);
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);//(i,j)即为对应顶点在vertices数组中的位置
		ArcNode* newNode1 = (ArcNode*)malloc(sizeof(ArcNode));
		newNode1->adjvex = j;
		newNode1->nextarc = G->vertices[i].firstarc;//头插法
		G->vertices[i].firstarc = newNode1;
		//对称
		if (G->kind == 0) {//无向图
			ArcNode* newNode2 = (ArcNode*)malloc(sizeof(ArcNode));
			newNode2->adjvex = i;
			newNode2->nextarc = G->vertices[j].firstarc;//头插法
			G->vertices[j].firstarc = newNode2;
		}
	}
}
int LocateVex(ALGraph* G, int u)
{
	/* 初始条件: 图G存在,u和G中顶点有相同特征*/
	/* 操作结果: 若G中存在顶点u,则返回该顶点在图中位置;否则返回-1 */
	for (int i = 0; i < G->vexnum; ++i) {
		if (u == G->vertices[i].data) {
			return i;
		}
	}
	return -1;
}
void printALGraph(ALGraph* G) {
	int v = 0;
	for (v = 0; v < G->vexnum; v++) {//遍历所有的顶点，分别遍历每个顶点的单链表
		printf("%d ", G->vertices[v].data);
		ArcNode* p;
		for (p = G->vertices[v].firstarc; p; p = p->nextarc) {
			printf("%d ", G->vertices[p->adjvex].data);
		}
		printf("\n");
	}
}
int main() {
	int vexnum;
	int arcnum;
	ALGraph* G = (ALGraph*)malloc(sizeof(ALGraph));
	scanf("%d%d", &vexnum, &arcnum);
	int kind = 0;
	scanf("%d", &kind);
	G->kind = kind;
	InitALGraph(G, vexnum, arcnum);
	printf("===========\n");
	printALGraph(G);
	return 0;
}
