#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;


int lowest_cost(vector<int> nums) {
    int n = nums.size();
    if(n<=2){return 0;}
    vector<vector<int>> dp(n, vector<int>(n, 0));
    //第i到第j取走的最小代价

    for(int len=2;len<n+1;++len){
        for(int i=0;i<n-len;++i){
            int j=i+len;
            dp[i][j]=INT_MAX;
            for(int k=i+1;k<j;++k){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+nums[i]*nums[j]*nums[k]);
            }
        }
    }
    return dp[0][n-1];

}



