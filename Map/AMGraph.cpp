//
// @author: Christinlj
// @date: 2022/6/23 14:45
// @description: 无向图的邻接表表示
//
//typedef struct {
//    GraphKind graphKind;    //图类型
//    VertexType vexs[MAX_VERTEX_NUM];   //顶点表
//    ArcType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  //邻接矩阵--边表
//    int vexnum,arcnum;  //当前顶点数和边数
//}AMGraph;

#include"../header/AMGraph.h"

//找到顶点在定点表中的位置，若无返回-1
int LocateVex(AMGraph &G,VertexType v){
    for(auto i=0;i<G.vexnum;i++)
        if(v==G.vexs[i])
            return i;
    return -1;
}

//创建无向图
void CreateUDG(AMGraph &G){
    G.graphKind=UDG;
    cout<<"Please input the number of vertex and arc:";
    cin>>G.vexnum>>G.arcnum;
    cout<<"Please input information about "<<G.vexnum<<" vertexs:";
    for(auto i=0;i<G.vexnum;i++)
        cin>>G.vexs[i];
    //初始化邻接矩阵，全部置为0
    for(auto i=0;i<G.vexnum;i++)
        for(auto j=0;j<G.vexnum;j++){
            G.arcs[i][j]=0;
        }
    cout<<"Please input arc's imformation:\n";
    //输入内容为两个结点,同一条边无需输入两次
    VertexType v1,v2;
    for(auto i=0;i<G.arcnum/2;i++){
        cin>>v1>>v2;
        auto x= LocateVex(G,v1),y= LocateVex(G,v2);
        G.arcs[x][y]=G.arcs[y][x]=1;
    }
}

void Print(AMGraph G){
    for(auto i=0;i<G.vexnum;i++){
        for(auto j=0;j<G.vexnum;j++){
            cout<<G.arcs[i][j]<<' ';
        }
        cout<<endl;
    }
}

int main() {
    AMGraph G;
    CreateUDG(G);
    Print(G);
    return 0;
}