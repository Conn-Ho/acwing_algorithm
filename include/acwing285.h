#include<iostream>
#include<cstring>
using namespace std;
const int N=6010;
int happy[N];
int dp[N][2];
int idx,e[N],ne[N],h[N];
bool has_father[N];

void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx;
    idx++;
}

void dfs(int u){
    dp[u][1]=happy[u];
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        dfs(j);
        dp[u][0]+=max(dp[j][0],dp[j][1]);
        dp[u][1]+=dp[j][0];
    }   
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>happy[i];
    }
    memset(h,-1,sizeof(h));
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;
        has_father[a]=true;
        add(b,a);
    }
    int root=1;
    while(has_father[root]) root++;
    dfs(root);
    cout<<max(dp[root][0],dp[root][1])<<endl;
    return 0;
}
    


