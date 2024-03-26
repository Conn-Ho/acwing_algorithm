#include<iostream>
#include<cstring>
using namespace std;
const int N=510,M=10010;
int n,m,k;
int dist[N],backup[N];
struct edge{
    int a,b,w;
}Edges[M];
bool bellman_ford(){
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    
    for(int i=0;i<k;i++){
        memcpy(backup,dist,sizeof(dist));
        for(int j=0;j<m;j++){
            int a=Edges[j].a, b=Edges[j].b, w=Edges[j].w;
            dist[b]=min(dist[b],backup[a]+w);
        }
    }
    if(dist[n]>0x3f3f3f3f/2) {
        return false;
    }
    return true;
    
}

int main(){
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        Edges[i]={a,b,w};
    }
    int t=bellman_ford();
   
    if(!t){
        cout<<"impossible"<<endl;
    }else{
        cout<<dist[n]<<endl;
    }
    return 0;
}