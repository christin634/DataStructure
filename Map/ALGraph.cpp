//
// @author: Christinlj
// @date: 2022/6/23 15:08
// @description: 无向图-邻接表
//

#include "../header/ALGraph.h"

//找到顶点在定点表中的位置，若无返回-1
int LocateVex(ALGraph &G,VertexType v){
    for(auto i=0;i<G.vexnum;i++)
        if(v==G.vertices[i].data)
            return i;
    return -1;
}

//创建无向图
void CreateUDG(ALGraph &G){
    G.graphKind=UDG;
    cout<<"Please input the number of vertex and arc:";
    cin>>G.vexnum>>G.arcnum;
    cout<<"Please input information about "<<G.vexnum<<" vertexs:";
    for(auto i=0;i<G.vexnum;i++){
        cin>>G.vertices[i].data;
        G.vertices[i].firstarc= nullptr;    //初始化表头结点的指针
    }
    cout<<"Please input arc's imformation:\n";
    //输入内容为两个结点信息
    VertexType v1,v2;
    for(auto i=0;i<G.arcnum;i++){
        cin>>v1>>v2;
        auto x= LocateVex(G,v1),y= LocateVex(G,v2);
        auto p1=new ArcNode,p2=new ArcNode;
        //分别将结点p1、p2插入到边表头部
        p1->adjvex=x;
        p1->nextarc=G.vertices[y].firstarc;
        G.vertices[y].firstarc=p1;
        p2->adjvex=y;
        p2->nextarc=G.vertices[x].firstarc;
        G.vertices[x].firstarc=p2;
    }
}

void Print(ALGraph G){
    //一个一个结点遍历
    for(auto i = 0 ; i < G.vexnum ; i++){
        auto p = G.vertices[i].firstarc;
        if(p == nullptr){
            cout << G.vertices[i].data<<endl;
        }
        else{
            cout << G.vertices[i].data;
            while(p){
                cout << "->";
                cout << G.vertices[p->adjvex].data;
                p = p->nextarc;
            }
        }
        cout << endl;
    }
}

int main(){
    ALGraph G;
    CreateUDG(G);
    Print(G);
    return 0;
}