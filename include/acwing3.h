#include<iostream>
using namespace std;

const int N=1010;

int dp[N][N];
int a[N],b[N];

int main(){
    int n,v;
    cin>>n>>v;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<=v;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=a[i]){
                dp[i][j]=max(dp[i][j],dp[i][j-a[i]]+b[i]);
            }
        }
    }
    cout<<dp[n][v]<<endl;

    return 0;
}