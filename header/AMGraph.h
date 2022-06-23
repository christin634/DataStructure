//
// @author: Christinlj
// @date: 2022/6/23 10:25
// @description: 图-邻接矩阵存储
//

#ifndef CLION_AMGRAPH_H
#define CLION_AMGRAPH_H

#include<iostream>
using namespace std;

const int INFINITY=INT_MAX;     //最大值，∞
const int MAX_VERTEX_NUM = 100; //最大顶点数
typedef enum {DG,DN,UDG,UDN} GraphKind;//图类型 {有向，有向网，无向图，无向网}
typedef char VertexType;    //顶点数据类型
typedef int ArcType;   //带权图中边上权值数据类型

typedef struct {
    GraphKind graphKind;    //图类型
    VertexType vexs[MAX_VERTEX_NUM];   //顶点表
    ArcType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  //邻接矩阵--边表
    int vexnum,arcnum;  //当前顶点数和边数
}AMGraph;

//创建无向图
void CreateUDG(AMGraph &G);
//找到顶点在定点表中的位置，若无返回-1
int LocateVex(AMGraph G,VertexType v);
//找到顶点v的第一个邻接点，返回索引，无则返回-1
int FirstNeighbor(AMGraph G,int v);
//找到顶点v的在w之后的邻接点，返回索引，无则返回-1
int NextNeighbor(AMGraph G,int v,int w);
//BFS搜索图G
void BFSTraverse(AMGraph G);
//BFS搜索图G,从顶点v(v为索引)开始
void BFS(AMGraph G,int v);
//访问顶点v
void visit(AMGraph G,int v);
#endif //CLION_AMGRAPH_H
