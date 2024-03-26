#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100010,M=200010;
struct E{
    int a;
    int b;
    int w;
    bool operator < (const E& rhs){//通过边长进行排序
        return this->w < rhs.w;
    }

}Edges[N*2];

int p[N];
int res=0;
int n,m;
int cnt=0;

int find(int a){
    if(p[a]!=a){
        p[a]=find(p[a]);
    }
    return p[a];
}

void Kruskal(){
    for(int i=1;i<=m;i++){
        int pa=find(Edges[i].a);
        int pb=find(Edges[i].b);
        if(pa!=pb){
            res+=Edges[i].w;    
            p[pa]=pb;
            cnt++;
        }
    }
}
int main(){
    cin>>n>>m;
        for(int i = 1; i <= n; i++) p[i] = i;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        Edges[i]={a,b,c};
    }
    sort(Edges+1,Edges+m+1);
    Kruskal();
    if(cnt<n-1){
        cout<<"impossible"<<endl;
    }else{
        cout<<res<<endl;
    }
    return 0;
}