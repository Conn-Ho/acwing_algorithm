#include<iostream>
#include<cstring>
using namespace std;
const int N=510,INF=0x3f3f3f3f;
int n,m;
int g[N][N];
int dist[N];
int st[N];

int kruskal(){

}

int main(){
    cin>>n>>m;
    memset(g,INF,sizeof g);
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        g[b][a]=g[a][b]=min(g[a][b],c);
    }
    int res=kruskal();
    cout<<res<<endl;
    return 0;
}