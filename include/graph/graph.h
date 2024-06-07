/**
 * @author: SEKin
 * @Date: 2024-05-30 10:40:20
 * @description:  图结构的有关定义
 * @Last Modified time: 2024-05-30 10:40:20
 */
#pragma once

// 要在头文件中定义常量并在多个源文件中使用它们，通常应该使用 const 或 constexpr 来定义常量，而不是使用宏定义。例如：
const int Maxsize = 100;

// 邻接矩阵的定义
typedef struct
{
	int n;
	char info;
} VertexType;

typedef struct
{
	VertexType vexs[Maxsize];  // 结点信息
	int adj[Maxsize][Maxsize]; // 边信息
	int vexnum, arcnum;		   // 顶点数，边数
} MGraph;

// 邻接表的定义

typedef struct ArcNode // 边定义
{
	int adjvex;
	int info;
	struct ArcNode *nextArc;
} ArcNode;

typedef struct // 顶点定义

{
	char data;
	ArcNode *firstArc; // 顶点的第一条边
} VNode;

typedef struct
{
	VNode adjList[Maxsize];
	int n, e;
} AGraph;

typedef struct
{
  int a, b;  // a 和 b 为一条边所连的两个顶点
  int w;     // 边的权值
} Road;

// 函数 Visit()代表了一类访问顶点 v 的操作
void Visit(int v);

// 排序函数
void Sort(Road [], int);

