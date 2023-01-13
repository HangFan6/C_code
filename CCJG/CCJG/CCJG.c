#define Default_Vertex_Size  10

#define T char

typedef struct GraphMtx
{
	int MaxVertices;//最大顶点容量
	int NumVertices;//图中顶点个数
	int NumEdges;//图中边的条数

	T   *VerticesList;//指向存有顶点的空间的指针
	int **Edge;//指向存矩阵的空间的指针
}GraphMtx;
void InitGraph(GraphMtx *g)
{
	g->MaxVertices = Default_Vertex_Size;
	g->NumVertices = g->NumEdges = 0;

//为存储顶点的空间进行初始化
	g->VerticesList = (T*)malloc(sizeof(T)*(g->MaxVertices));
	assert(g->VerticesList != NULL);

//为存储矩阵的空间进行初始化
	g->Edge = (int**)malloc(sizeof(int*) * g->MaxVertices);
	assert(g->Edge != NULL);
	for(int i=0; i<g->MaxVertices; ++i)
	{
		g->Edge[i] = (int*)malloc(sizeof(int) * g->MaxVertices);
	}
	for(i=0; i<g->MaxVertices; ++i)
	{
		for(int j=0; j<g->MaxVertices; ++j)
		{
			g->Edge[i][j] = 0;
		}
	}
}
void main()
{
	GraphMtx gm;
	InitGraph(&gm);
	InsertVertex(&gm,'A');
	InsertVertex(&gm,'B');
	InsertVertex(&gm,'C');
	InsertVertex(&gm,'D');
	InsertVertex(&gm,'E');

	InsertEdge(&gm,'A','B');
	InsertEdge(&gm,'A','D');
	InsertEdge(&gm,'B','C');
	InsertEdge(&gm,'B','E');
	InsertEdge(&gm,'C','E');
	InsertEdge(&gm,'C','D');
	ShowGraph(&gm);
	//int p = GetFirstNeighbor(&gm,'D');
	int p = GetNextNeighbor(&gm,'D','C');
}
void InsertVertex(GraphMtx *g, T v)
{
	if(g->NumVertices >= g->MaxVertices)
		return;
	g->VerticesList[g->NumVertices++] = v;
}
//获取顶点在连续内存（看做数组）中的的位置
int  GetVertexPos(GraphMtx *g, T v)
{
	for(int i=0; i<g->NumVertices; ++i)
	{
		if(g->VerticesList[i] == v)
			return i;
	}
	return -1;
}


//插入边
void InsertEdge(GraphMtx *g, T v1, T v2)
{
	int p1 = GetVertexPos(g,v1);
	int p2 =  GetVertexPos(g,v2);
	if(p1==-1 || p2==-1)
		return;

	if(g->Edge[p1][p2] != 0)
		return;

	g->Edge[p1][p2] = g->Edge[p2][p1] = 1;
	g->NumEdges++;
}



//#include<stdio.h>
////#include
//#define MAX_VER_NUM 50
//typedef char VertexType;
//typedef enum
//{
//DG,UDG
//}GraphType;
//typedef struct
//{
//VertexType vexs[MAX_VER_NUM]; //顶点向量
//int arcs[MAX_VER_NUM][MAX_VER_NUM]; //邻接矩阵
//int vexnum,arcnum; //图的当前顶点数和弧数
//GraphType type; //图的种类标志
//}MGraph;
////根据名称得到指定顶点在顶点集合中的下标
////vex 顶点
////return 如果找到，则返回下标，否则，返回0
//int getIndexOfVexs(char vex,MGraph *MG)
//{
//int i;
//for(i=1;i<=MG->vexnum;i++)
//{
//if(MG->vexs[i]==vex)
//{
//return i;
//}
//}
//return 0;
//}
////创建邻接矩阵
//void create_MG(MGraph *MG)
//{
//int i,j,k;
//int v1,v2,type;
//char c1,c2;
//printf("Please input graph type DG(0) or UDG(1):");
//scanf("%d",&type);
//if(type==0)
//{
//MG->type=DG;
//}
//else if(type==1)
//{
//MG->type=UDG;
//}
//else
//{
//printf("Please input correct graph type DG(0) or UDG(1)!");
//return;
//}
//printf("Please input vexnum:");
//scanf("%d",&MG->vexnum);
//printf("Please input arcnum:");
//scanf("%d",&MG->arcnum);
//getchar();
//for(i=1;i<=MG->vexnum;i++)
//{
//printf("Please input %dth vex(char):",i);
//scanf("%c",&MG->vexs[i]);
//getchar();
//}
////初始化邻接矩阵
//for(i=1;i<=MG->vexnum;i++)
//{
//for (j=1;j<=MG->vexnum;j++)
//{
//MG->arcs[i][j]=0;
//}
//}
////输入边的信息，建立邻接矩阵
//for(k=1;k<=MG->arcnum;k++)
//{
//printf("Please input %dth arc v1(char) v2(char):",k);
//scanf("%c %c",&c1,&c2);
//v1=getIndexOfVexs(c1,MG);
//v2=getIndexOfVexs(c2,MG);
//if(MG->type==-1)
//{
//MG->arcs[v1][v2]=MG->arcs[v2][v1]=1;
//}
//else
//{
//MG->arcs[v1][v2]=1;
//}
//getchar();
//}
//}
////打印邻接矩阵和顶点信息
//void print_MG(MGraph MG)
//{
//int i,j;
//if(MG.type==DG)
//{
//printf("Graph type: Direct graph\n");
//}
//else
//{
//printf("Graph type: Undirect graph\n");
//}
//printf("Graph vertex number: %d\n",MG.vexnum);
//printf("Graph arc number: %d\n",MG.arcnum);
//printf("Vertex set:");
//for(i=1;i<=MG.vexnum;i++)
//{
//printf("%c",MG.vexs[i]);
//}
//printf("\nAdjacency Matrix:\n");
//for(i=1;i<=MG.vexnum;i++)
//{
//for(j=1;j<=MG.vexnum;j++)
//{
//printf("%d",MG.arcs[i][j]);
//}
//printf("\n");
//}
//}
////主函数
//int main(void)
//{
//MGraph MG;
//create_MG(&MG);
//print_MG(MG);
//return 0;
//}