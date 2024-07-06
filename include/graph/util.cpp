/**
 * @author: SEKin
 * @Date: 2024-05-30 11:21:02
 * @description:  遍历算法
 * @Last Modified time: 2024-05-30 11:21:02
 */

#include "graph.h"
#include <iostream>
using  std::cout;
#define INF 100000;
const int maxSize = 100;
int visit[];

/* v 是起点编号,visit[]是一个全局数组,作为顶点的访问标记,初始时所有元素均为 0,
表示所有顶点都未被访问。因图中可能存在回路,当前经过的顶点在将来还可能再次经过,所以要对每个
顶点进行标记,以免重复访问*/
void DFS(AGraph *G, int v)
{
    ArcNode *p;
    visit[v] = 1;               // 置已访问标记
    Visit(v);                   // 函数 Visit()代表了一类访问顶点 v 的操作
    p = G->adjList[v].firstArc; // p 指向顶点v的第一条边
    while (p != nullptr)
    {
        if (visit[p->adjvex] == 0)
        {                      // 若顶点未访问,则递归访问它
            DFS(G, p->adjvex); //(1)
        }
        p = p->nextArc; // 修改为正确的成员名称
    }
}

// 广度优先遍历
void BFS(AGraph *G, int v, int visit[maxSize])
{
    // visit[]数组被初始化为全0
    ArcNode *p;
    int que[maxSize], front = 0, rear = 0; // 这是队列定义的简单写法
    int j;
    Visit(v);
    visit[v] = 1;
    rear = (rear + 1) % maxSize; // 当前顶点v进队
    que[rear] = v;
    while (front != rear) // 队空时说明遍历完成
    {
        front = (front + 1) % maxSize; // 顶点出队
        j = que[front];
        p = G->adjList[j].firstArc; // p 指向出队顶点j的第一条边
        while (p != nullptr)        // 将p的所有邻接点中未访问的入队
        {
            // 当前邻接顶点未被访问，则进队
            if (visit[p->adjvex] == 0)
            {
                Visit(p->adjvex);
                visit[p->adjvex] = 1;
                rear = (rear + 1) % maxSize; // 顶点入队
                que[rear] = p->adjvex;
            }
            p = p->nextArc; // p 指向j的下一条边
        }
    }
}

// 普利姆算法：注意这里并不是生成一个最小代价树，而是求最小代价
void Prim(MGraph g, int v0, int &sum)
{
    int lowcost[maxSize], vset[maxSize], v;
    int i, j, k, min;
    v = v0;
    for (i = 0; i < g.vexnum; i++)
    {
        vset[i] = 0;
        lowcost[i] = g.adj[v0][i];
    }

    vset[v0] = 1;
    sum = 0;
    for (i = 0; i < g.vexnum - 1; i++)
    {
        min = INF;
        // 找出当前节点的候选边中最小代价的节点
        for (j = 0; j < g.vexnum; j++)
        {
            if (vset[j] == 0 && lowcost[j] < min)
            {
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
            if (vset[j] == 0 && g.adj[v][j] < lowcost[j])
            {
                lowcost[j] = g.adj[v][j];
            }
        }
    }
}

// 克鲁斯卡尔算法：注意这里并不是生成一个最小代价树，而是求最小代价
Road road[maxSize];
int v[maxSize];    // 定义并查集数组
int getRoot(int a) // 在并查集中查找根结点的函数
{
    while (a != v[a])
        a = v[a];
    return a;
}

void Kruskal(MGraph g, int &sum, Road road[])
{
    int i;
    int E, N;
    E = g.arcnum;
    N = g.vexnum;
    sum = 0;

    // 初始化
    int a, b; // 边的两个端点
    for (i = 0; i < E; i++)
    {
        v[i] = i;
    }
    Sort(road, E);

    for (i = 0; i < E; i++)
    {
        a = getRoot(road[i].a);
        b = getRoot(road[i].b);
        if (a != b)
        {
            v[a] = b;
            sum += road[i].w;
        }
    }
}

// 迪杰斯特拉算法
// v：源顶点
void Dijkstra(MGraph g, int v, int dist[], int path[])
{
    int set[maxSize];
    int min, i, j, u;
    /*从这句开始对各数组进行初始化*/
    for (i = 0; i < g.vexnum; ++i) {
        dist[i] = g.adj[v][i];
        set[i] = 0;
        int infinity = INF;
        if (g.adj[v][i] < infinity)
        {
            path[i] = v;
        }
        else
        {
            path[i] = -1;
        }
    }
    set[v] = 1;
    path[v] = -1;
    /*初始化结束*/

    /*关键操作开始*/
    for (i = 0; i < g.vexnum - 1; ++i) {
        min = INF;
        /*这个循环每次从剩余顶点中选出一个顶点，通往这个顶点的路径在通往所有剩余顶点的路径中是长度最短的*/
        for (j = 0; j < g.vexnum; ++j) {
            if (set[j] == 0 && dist[j] < min) {
                u = j;
                min = dist[j];
            }
        }

        set[u] = 1; // 将选出的顶点并入最短路径中
        /*这个循环以刚并入的顶点作为中间点，对所有通往剩余顶点的路径进行检测*/
        for (j = 0; j < g.vexnum; ++j) {
            /*这个if语句判断顶点u的加入是否会出现通往顶点j的更短的路径，如果出现，则改变原来路径及其长度，否则什么都不做*/
            if (set[j] == 0 && dist[u] + g.adj[u][j] < dist[j]) {
                dist[j] = dist[u] + g.adj[u][j];
                path[j] = u;
            }
        }
    }
    /*关键操作结束*/
}

/*函数结束时，dist[]数组中存放了v点到其余顶点的最短路径长度，path[]中存放v点到其余各顶点的最短路径*/

// 弗洛伊德算法
void Floyd(MGraph *g, int Path[][maxSize], int A[][maxSize])
{ // 图g的边矩阵中，用INF来表示两点之间不存在边

    int i, j, k;

    /*这个双循环对数组A[][]和Path[][]进行了初始化*/
    for (i = 0; i < g->vexnum; ++i) {
        for (j = 0; j < g->vexnum; ++j) {
            A[i][j] = g->adj[i][j];
            Path[i][j] = -1;
        }
    }

    /*下面这个三层循环是本算法的主要操作，完成了以k为中间点对所有的顶点对（i，j）进行检测和修改*/
    for (k = 0; k < g->vexnum; ++k)
        for (i = 0; i < g->vexnum; ++i)
            for (j = 0; j < g->vexnum; ++j)
                if (A[i][j] > A[i][k] + A[k][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                    Path[i][j] = k;
                }
};

// 拓扑排序算法
int TopSort(AGraph *G){
    int i,j,n=0;
    int stack[maxSize], top = -1;
    ArcNode *p;
    // 这个循环将图中入度为0的顶点入栈
    for ( i = 0; i < G->n; ++i) {
        if(G->adjList[i].count == 0){
                stack[++top] = i;
        }
    }
    // 关键操作开始
    while (top!=-1) {
        i = stack[top--];
        ++n; //计数器加1，统计当前顶点
        cout<<i<<" "; // 输出当前顶点
        p = G->adjList[i].firstArc;
        // 这个循环实现了将所有由此顶点引出的边所指向的顶点的入度都减少1，并将这个过程中入度变为0的顶点入栈
        while (p!=nullptr){
            /* code */
            j=p->adjvex;
            --(G->adjList[j].count);
            if(G->adjList[j].count == 0){
                stack[++top]=j;
            }
            p=p->nextArc;
        }
    }
    // 关键操作结束
    if(n=G->n){
        return 1;
    }else{
        return 0;
    }
    
}
