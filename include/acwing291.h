#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
const int N=12,M=1<<N;
int n,m;
long long f[N][M];
bool st[M];
vector<vector<int>> state(M);
int main(){
    while(cin>>n>>m,n||m){
        //筛掉所有列中奇数个0的情况
        for(int i=0;i<(1<<n);i++){
            int  cnt=0;
            bool isValid=true;
            for(int j=0;j<n;j++){
                if((i>>j)&1){
                    if (cnt & 1){
                        isValid=false;
                        break; 
                    }
                    cnt=0;
                }
                else{
                    cnt++;
                }
            }
            if (cnt & 1)  isValid = false; 
            st[i]  = isValid;
        }
        
        //筛掉相邻两列冲突的情况 j和k都是二进制表示 比如10010和01000
        //j和k都是行 一共有2^n行
        for(int j=0;j<(1<<n);j++){
            state[j].clear();
            for(int k=0;k<(1<<n);k++){
                if((j&k)==0 && st[j|k]){
                    state[j].push_back(k);
                }   
            }
        }
        
        memset(f,0,sizeof(f));
        f[0][0]=1;
        for(int i=1;i<=m;i++){
            for(int j=0;j<(1<<n);j++){
                for(auto k: state[j]){
                    f[i][j]+=f[i-1][k];
                }
            }
        }
        cout<<f[m][0]<<endl;
    }
}