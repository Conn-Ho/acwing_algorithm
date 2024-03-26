#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100010;
int e[N],h[N],ne[N],idx;
int n1,n2,m;
bool st[N];
int match[N];

void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx;
    idx++;
}
bool find(int x){
    for(int i=h[x];i!=-1;i=ne[i]){
        int j=e[i];
        if(!st[j]){
            st[j]=true;
            if(!match[j]||find(match[j])){
                match[j]=x;
                return true;
            }
        }
    }
    return false;
}
int main(){
    cin>>n1>>n2>>m;
    memset(h,-1,sizeof(h));
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
    }
    int res=0;
    for(int i=1;i<=n1;i++){
        memset(st,false,sizeof(st));
        if(find(i)){
            res++;
        }
    }
    cout<<res<<endl;
    return 0;
}




