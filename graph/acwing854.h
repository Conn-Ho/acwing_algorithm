#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=200,INF=1e9;
int n,m,q;
int g[N][N];
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
}

int main(){
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) g[i][j]=0;
            else g[i][j]=INF;
        }
    }
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=min(g[a][b],c);
    }
    floyd();
    while(q--){
        int a,b;
        cin>>a>>b;
        if(g[a][b]>INF/2){cout<<"impossible"<<endl;}
        else{
            cout<<g[a][b]<<endl;
        }
    }
    return 0;

}