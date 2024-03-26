#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100010*2,M=100010;
int e[N],h[N],ne[N],idx;
int color[N];  
int n,m;
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx;
    idx++;
}
bool dfs(int u,int c){
    color[u]=c;
    for(int i=h[u];i!=-1;i=ne[i]){
        int b=e[i];
        if(!color[b]){
            if(!dfs(b,3-c))  return false;
        }else if(color[b] && color[b]!=3-c){
            return false;
        }
        
    }
    return true;
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof(h));
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    for(int i=1;i<=n;i++){
        if(!color[i]){
            if(!dfs(i,1)){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}




