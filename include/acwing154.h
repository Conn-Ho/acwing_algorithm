#include<iostream>
#include<deque>
using namespace std;
const int N=1000010;
int a[N];
deque<int>q;
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //min
    for(int i=0;i<n;i++){
        while(q.size() && q.back()>a[i]){
            q.pop_back();
        }
        q.push_back(a[i]);
        if(i>=k && q.front()==a[i-k]){
            q.pop_front();
        }
        if(i+1>=k){
            cout<<q.front()<<" ";
        }
    }
    cout<<endl;
    q.clear();
    //max
    for(int i=0;i<n;i++){
        while(q.size() && q.back()<a[i]){
            q.pop_back();
        }
        q.push_back(a[i]);
        if(i>=k && q.front()==a[i-k]){
            q.pop_front();
        }
        if(i+1>=k){
            cout<<q.front()<<" ";
        }
    }
    
    return 0;
}