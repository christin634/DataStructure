//
// @author: Christinlj
// @date: 2022/6/23 15:08
// @description: 图-邻接表
//

#include "../header/ALGraph.h"
#include<queue>
#include<stack>
//找到顶点在定点表中的位置，若无返回-1
int LocateVex(ALGraph G,VertexType v){
    for(auto i=0;i<G.vexnum;i++)
        if(v==G.vertices[i].data)
            return i;
    return -1;
}

//创建无向图
void CreateUDG(ALGraph &G){
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
//创建有向图
void CreateDG(ALGraph &G){
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
        auto p=new ArcNode;
        //将结点p插入到边表头部
        p->adjvex=y;
        p->nextarc=G.vertices[x].firstarc;
        G.vertices[x].firstarc=p;
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

//找到顶点v的第一个邻接点，返回索引，无则返回-1
int FirstNeighbor(ALGraph G,int v){
    return G.vertices[v].firstarc== nullptr?-1:G.vertices[v].firstarc->adjvex;
}
//找到顶点v的在w之后的邻接点，返回索引，无则返回-1
int NextNeighbor(ALGraph G,int v,int w){
    auto p=G.vertices[v].firstarc;
    for(;p!= nullptr;p=p->nextarc){
        if(w==p->adjvex){
            break;
        }
    }
    p=p->nextarc;
    return p==nullptr?-1:p->adjvex;
}
bool visited[MAX_VERTEX_NUM];   //访问标记数组
//BFS搜索图G
void BFSTraverse(ALGraph G){
    for(auto i=0;i<G.vexnum;i++)
        visited[i]= false;
    for(auto i=0;i<G.vexnum;i++)
        if(!visited[i])
            BFS(G,i);
}
//BFS搜索图G,从顶点v(v为索引)开始
void BFS(ALGraph G,int v){
    queue<int> q;
    visit(G,v);
    visited[v]= true;
    q.push(v);
    while(!q.empty()){
        //顶点出列
        v = q.front();
        q.pop();
        //访问v的所有邻接点
        for(auto w= FirstNeighbor(G,v);w>=0;w= NextNeighbor(G,v,w))
            if (!visited[w]) {
                visit(G, w);
                visited[w] = true;
                q.push(w);
            }
    }
}
//访问顶点v
void visit(ALGraph G,int v){
    cout<<G.vertices[v].data<<' ';
}

//DFS搜索图G
void DFSTraverse(ALGraph G){
    for(auto i=0;i<G.vexnum;i++)
        visited[i]= false;
    for(auto i=0;i<G.vexnum;i++)
        if(!visited[i])
            DFS(G,i);
}
//DFS搜索图G,从顶点v(v为索引)开始
void DFS(ALGraph G,int v){
    visit(G,v);
    visited[v]= true;
    for(auto w= FirstNeighbor(G,v);w>=0;w= NextNeighbor(G,v,w))
        if(!visited[w])
            DFS(G,w);
}

//从v开始，非递归DFS
void DFS_Non_RC(ALGraph G,int v){
    //访问标记数组，记录是否已经入过栈
    for(auto i=0;i<G.vexnum;i++)
        visited[i]= false;
    stack<int> stack;
    stack.push(v);
    visited[v]= true;
    while(!stack.empty()){
        auto p=stack.top();
        stack.pop();    //出栈后访问
        visit(G,p);
        for(auto w= FirstNeighbor(G,p);w>=0;w= NextNeighbor(G,p,w))
            if(!visited[w]){//未入过栈的，先入栈
                stack.push(w);
                visited[w]= true;
            }
    }
}

int main(){
    ALGraph G;
    int graphKind;
    cout<<"Choose to create what kind of graph:\n";
    cout<<"0.Directed Graph\n1.Undirected Graph\n";
    cin>>graphKind;
    switch(graphKind){
        case DG:
            CreateDG(G);break;
        case UDG:
            CreateUDG(G);break;
        default:break;
    }
    cout<<"AdjList:\n";
    Print(G);
    cout<<"BFS:\n";
    BFSTraverse(G);
    cout<<"\nDFS:\n";
    DFSTraverse(G);
    cout<<"\nNon_Recursion_DFS:\n";
    DFS_Non_RC(G,0);
    return 0;
}