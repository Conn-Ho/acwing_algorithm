#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=100010,M=100010;
int n,m;
int dist[N],st[N];
queue<int> q;
int idx,h[N],e[N],ne[N],w[N];

void add(int a,int b,int c){
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx;
    idx++;
}

int spfa(){
        q.push(1);
        dist[1]=0;
        st[1]=1;
        while(q.size()){
            int t=q.front();q.pop();
            st[t]=0;
            
            for(int i=h[t];i!=-1;i=ne[i]){
                int b=e[i],c=w[i];
                if(dist[b]>dist[t]+c){
                    dist[b]=dist[t]+c;
                    if(!st[b]){
                        q.push(b);
                        st[b]=1;
                    }
                }
            }
        }
}

int main(){
    memset(dist,0x3f,sizeof(dist));
    memset(h,-1,sizeof(h));
    
    cin>>n>>m;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    spfa();
    if(dist[n]==0x3f3f3f3f ){
        cout<<"impossible"<<endl;
    }else{
        cout<<dist[n]<<endl;
    }
    return 0;
}