#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MaxV 20
//�����ڽӱ�Ľṹ��
typedef struct ArcNode {//�߽��
	int adjvex;//�ñ���ָ��Ķ����������е�λ��
	struct ArcNode* nextarc;//ָ����һ���ߵ�ָ��
}ArcNode;

typedef struct VNode {//������Ϣ��������Ϊÿ��������ı�ͷ��㣩
	int data;
	ArcNode* firstarc;//ָ���һ�������ö���ıߵ�ָ��
}AdjList[MaxV];
typedef struct {
	AdjList vertices;
	int vexnum, arcnum;//ͼ�ĵ�ǰ�������ͱ���
	int kind;//�ֳ�����ͼ������ͼ
}ALGraph;
void InitALGraph(ALGraph* G, int vexnum, int arcnum) {//��������ͱ���
	G->vexnum = vexnum;
	G->arcnum = arcnum;
	for (int i = 0; i < G->vexnum; i++) {//�����㸳ֵ��������ͷ���
		scanf("%d", &G->vertices[i].data);
		G->vertices[i].firstarc = NULL;
	}
	for (int k = 0; k < G->arcnum; k++) {
		int v1 = 0;//ÿ���߹�����������
		int v2 = 0;
		scanf("%d%d", &v1, &v2);
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);//(i,j)��Ϊ��Ӧ������vertices�����е�λ��
		ArcNode* newNode1 = (ArcNode*)malloc(sizeof(ArcNode));
		newNode1->adjvex = j;
		newNode1->nextarc = G->vertices[i].firstarc;//ͷ�巨
		G->vertices[i].firstarc = newNode1;
		//�Գ�
		if (G->kind == 0) {//����ͼ
			ArcNode* newNode2 = (ArcNode*)malloc(sizeof(ArcNode));
			newNode2->adjvex = i;
			newNode2->nextarc = G->vertices[j].firstarc;//ͷ�巨
			G->vertices[j].firstarc = newNode2;
		}
	}
}
int LocateVex(ALGraph* G, int u)
{
	/* ��ʼ����: ͼG����,u��G�ж�������ͬ����*/
	/* �������: ��G�д��ڶ���u,�򷵻ظö�����ͼ��λ��;���򷵻�-1 */
	for (int i = 0; i < G->vexnum; ++i) {
		if (u == G->vertices[i].data) {
			return i;
		}
	}
	return -1;
}
void printALGraph(ALGraph* G) {
	int v = 0;
	for (v = 0; v < G->vexnum; v++) {//�������еĶ��㣬�ֱ����ÿ������ĵ�����
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
