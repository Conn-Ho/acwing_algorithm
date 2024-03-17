#include<iostream>
using namespace std;
const int N=510;
int n,m,k;
int g[N][N];
int dist[N];
int st[N];
int bellman_ford(){
    for(int i=0;i<n;i++){

    }
}
int main(){
    cin>>n>>m>>k;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=min(g[a][b],c);
    }

}