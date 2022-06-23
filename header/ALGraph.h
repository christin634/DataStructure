//
// @author: Christinlj
// @date: 2022/6/23 15:08
// @description: 图的邻接表存储
//

#ifndef CLION_ALGRAPH_H
#define CLION_ALGRAPH_H

#include<iostream>
using namespace std;

const int INFINITY=INT_MAX;     //最大值，∞
const int MAX_VERTEX_NUM = 100; //最大顶点数
typedef enum {DG,DN,UDG,UDN} GraphKind;//图类型 {有向，有向网，无向图，无向网}
typedef char VertexType;    //顶点数据类型
typedef int ArcType;   //带权图中边上权值数据类型

//边结点
typedef struct ArcNode{
    int adjvex;     //该边指向的顶点位置
    struct ArcNode *nextarc;    //指向下一条边的指针
    //InforType info;       //边相关的信息
}ArcNode;
//顶点信息
typedef struct VNode{
    VertexType data;
    ArcNode *firstarc;  //指向第一条依附于该顶点的边
}VNode,AdjList[MAX_VERTEX_NUM];
//图
typedef struct {
    GraphKind graphKind;    //图类型
    AdjList vertices;   //邻接表
    int vexnum,arcnum;  //当前顶点数和边数
}ALGraph;

//创建无向图
void CreateUDG(ALGraph &G);

//找到顶点在定点表中的位置，若无返回-1
int LocateVex(ALGraph &G,VertexType v);

#endif //CLION_ALGRAPH_H
