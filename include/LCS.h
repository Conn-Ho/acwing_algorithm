#include<iostream>
#include<vector>
#include<string>
using namespace std;


int LCS(string word1,string word2){

    int m=word1.length();
    int n=word2.length();


    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    string ret;
    //输出需要维护一个状态数组 回溯动态规划表格

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(word1[i]==word2[j]){
                dp[i][j]=dp[i-1][j-1]+1;

            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

            }

        }
    }

    int i=m,j=n;
    string lcs="";
    while(i>0 && j>0){
        if(word1[i-1]==word2[j-1]){
            lcs=word1[i-1]+lcs;
            i--;
            j--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }

    //可以输出其中一种
    cout<<lcs<<endl;

    return dp[m][n];

}


