#include<iostream>
#include<algorithm>
using namespace std;
int n;
const int N=10;
char path[N][N];
int state[N][N];
bool col[N],dg[N],udg[N];

void dfs(int u){
    if (u==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<path[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        if(!col[i] && !dg[u+i] && !udg[n-u+i]){
            path[u][i]='Q';
            col[i]=dg[u+i]=udg[n-u+i]=true;
            dfs(u+1);
            col[i]=dg[u+i]=udg[n-u+i]=false;
            path[u][i]='.';
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            path[i][j]='.';
        }
    }
    dfs(0);
    return 0;
}