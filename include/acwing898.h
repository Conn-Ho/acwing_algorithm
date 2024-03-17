#include<iostream>
using namespace std;
const int N=510;

int n;
int a[N][N];
int dp[N][N];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        dp[n][i]=a[n][i];
    }

    for(int i=n-1;i>=1;i--){
        for(int j=i;j>=1;j--){
            dp[i][j]=max(dp[i+1][j]+a[i][j],dp[i+1][j+1]+a[i][j]);
        }
    }
    cout<<dp[1][1];
    return 0;
}