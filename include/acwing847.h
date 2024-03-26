#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=100010;
int dist[N];
int n,m;
int e[N],ne[N],h[N],idx;
int st[N];

void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

void  bfs(){
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    queue<int>q;
    q.push(1);
    st[1]=1;
    while(q.size()){
        int t=q.front();
        q.pop();
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            if(!st[j]){
                dist[j]=dist[t]+1;
                q.push(j);
                st[j]=1;
            }
        }
    }
}

int main(){
    cin>>n>>m;
    memset(h,-1,sizeof(h));
    while(m--){
        int a,b;
        cin>>a>>b;
        add(a,b);
    }
    bfs();
    if(dist[n]<=0x3f){
        cout<<dist[n]<<endl;
    }else{
        cout<<"-1"<<endl;
    }
    return 0;
}