#include<iostream>
#include<unordered_map>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
unordered_map<string,int>h;
string s;
queue<string> q;
int main(){
    char c;
    for(int i=0;i<9;i++){
        cin>>c;
        s+=c;
    }
    q.push(s);
    while(!q.empty()){
        string t=q.front();
        q.pop();
        if(t=="12345678x"){
            cout<<h[t]<<endl;
            return 0;
        }
        int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
        int pos=t.find('x');
        int a=pos/3,b=pos%3;
        int dist=h[t];
        for(int i=0;i<4;i++){
            int x=a+dx[i],y=b+dy[i];
            if(x>=0 && x<3 && y>=0 && y<3){
                swap(t[pos],t[x*3+y]);
                if(h.find(t)==h.end()){
                    q.push(t);
                    h[t]=dist+1;
                }
                swap(t[pos],t[x*3+y]);
            }
        }
        
    }
    cout<<-1;
    return 0;
}

