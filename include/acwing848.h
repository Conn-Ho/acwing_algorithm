#include<iostream>
#include<cstring>
using namespace std;
const int N=100010;
int n,m;
int e[N],ne[N],h[N],idx;
int q[N],tt=-1,hh=0;
int d[N];
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

void topo(){
    for(int i=1;i<=n;i++){
        if(d[i]==0){
            q[++tt]=i;
        }
    }
    while(tt>=hh){
        int t=q[hh++];
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            d[j]--;
            if(d[j]==0){
                q[++tt]=j;
            }
        }
    }
    
    if(tt==n-1){
        for(int i=0;i<n;i++){
            cout<<q[i]<<" ";
        }
    }else{
        cout<<"-1"<<endl;
    }
    
}

int main(){
    cin>>n>>m;
    memset(h,-1,sizeof(h));
    while(m--){
        int a,b;
        cin>>a>>b;
        d[b]++;
        add(a,b);
    }
    topo();
    return 0;
}