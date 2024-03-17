#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N=10010;
int a[N];

int main(){
    int n;
    cin>>n;
    priority_queue<int,vector<int>,greater<int>>heap;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        heap.push(a);
    }
    int res=0;
    while(heap.size()>1){
        int a=heap.top();heap.pop();
        int b=heap.top();heap.pop();
        res+=a+b;
        heap.push(a+b);
    }
    cout<<res;
    return 0;

}