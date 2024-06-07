/**
 * @author: SEKin 
 * @Date: 2024-05-30 11:21:02 
 * @description:  遍历算法
 * @Last Modified time: 2024-05-30 11:21:02 
 */

#include "graph.h"
#define INF 100000;

const int maxSize = 100;
int visit[];

/* v 是起点编号,visit[]是一个全局数组,作为顶点的访问标记,初始时所有元素均为 0,
表示所有顶点都未被访问。因图中可能存在回路,当前经过的顶点在将来还可能再次经过,所以要对每个
顶点进行标记,以免重复访问*/
void DFS(AGraph *G, int v)
{
	ArcNode *p;
	visit[v] = 1;				// 置已访问标记
	Visit(v);					// 函数 Visit()代表了一类访问顶点 v 的操作
	p = G->adjList[v].firstArc; // p 指向顶点v的第一条边
	while (p != nullptr)
	{
		if (visit[p->adjvex] == 0)
		{					   // 若顶点未访问,则递归访问它
			DFS(G, p->adjvex); //(1)
		}
		p = p->nextArc; // 修改为正确的成员名称
	}
}

//广度优先遍历
void BFS (AGraph *G, int v, int visit[maxSize])
{
    //visit[]数组被初始化为全0
    ArcNode *p;
    int que[maxSize], front=0, rear=0; //这是队列定义的简单写法
    int j;
    Visit(v);
    visit[v]=1;
    rear = (rear+1) % maxSize;  // 当前顶点v进队
    que[rear] = v;
    while (front != rear) // 队空时说明遍历完成
    {
        front = (front+1) % maxSize; // 顶点出队
        j = que[front];
        p = G->adjList[j].firstArc; //p 指向出队顶点j的第一条边
        while (p != nullptr)//将p的所有邻接点中未访问的入队
        {
            // 当前邻接顶点未被访问，则进队
            if (visit[p->adjvex] == 0)
            {
                Visit(p->adjvex);
                visit[p->adjvex] = 1;
                rear = (rear + 1) % maxSize; // 顶点入队
                que[rear] = p->adjvex;
            }
            p = p->nextArc; //p 指向j的下一条边
        }
    }
}

// 普利姆算法：注意这里并不是生成一个最小代价树，而是求最小代价
void Prim(MGraph g, int v0, int &sum){
    int lowcost[maxSize], vset[maxSize], v;
    int i,j,k,min;
    v = v0;
    for ( i = 0; i < g.vexnum; i++)
    {
        vset[i] = 0;
        lowcost[i] = g.adj[v0][i];
    }

    vset[v0] = 1;
    sum=0;
    for ( i = 0; i < g.vexnum - 1; i++)
    {
        min = INF;
        // 找出当前节点的候选边中最小代价的节点
        for ( j = 0;  j < g.vexnum; j++)
        {
            if(vset[j] == 0 && lowcost[j] < min){
                min = lowcost[j];
                k = j;
            }
        }

        vset[k] = 1;
        sum += min;
        v = k;

        // 更新新并入的节点的lowcost
        for (j = 0; j < g.vexnum; j++)
        {
           if(vset[j] == 0 && g.adj[v][j] < lowcost[j]){
                lowcost[j] = g.adj[v][j];
           }
        }
    }
}

// 克鲁斯卡尔算法：注意这里并不是生成一个最小代价树，而是求最小代价
Road road[maxSize];
int v[maxSize];  // 定义并查集数组
int getRoot(int a)  // 在并查集中查找根结点的函数
{
  while (a != v[a]) a = v[a];
  return a;
}
 
void Kruskal(MGraph g, int &sum, Road road[]) {
    int i;
    int E, N;
    E = g.arcnum;
    N = g.vexnum;
    sum = 0;

    // 初始化
    int a ,b; //边的两个端点
    for ( i = 0; i < E; i++) { v[i] = i; }
    Sort(road, E);

    for ( i = 0; i < E; i++) {
       a = getRoot(road[i].a);
       b = getRoot(road[i].b);
       if(a!=b){
          v[a] = b;
          sum+=road[i].w;
       }
    }
}

