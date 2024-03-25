#include<iostream>
#include<vector>
using namespace std; 
const int N=30;
int num[N];
int n,k;
bool state[N];
vector<int> path;
bool prime_number(int a){
    int res;
    for(int i=2;i<=a/i;i++){
        if(a%i==0){
            return false;
        }
    }
    return true;
}
int total_num=0;
int prime_sum=0;
void dfs(int u){
    if(u==k){
        prime_sum+=prime_number(total_num);
    }
    for(int i=0;i<k;i++){
        if(!state[i]){
            path.push_back(num[i]);
            total_num+=num[i];
            state[i]=true;
            dfs(u+1);
            state[i]=false;
            path.pop_back();
            total_num-=num[i];
        }
    }
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    cout<<prime_sum<<endl;
}