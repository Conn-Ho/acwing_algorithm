#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef pair<int,int> PIR;
const int N=300010;

vector<PIR>add;
vector<PIR>inquire;
vector<int>alls;
int a[N],s[N];

int find(int x){
    int l=0,r=alls.size()-1;
    while(l<r){
        int mid=l+r>>1;
        if(alls[mid]>=x) r=mid;
        else{
                l=mid+1;
        }
    }
    return r+1;
}


int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x,c;
        cin>>x>>c;
        add.push_back({x,c});
        alls.push_back(x);
    }
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        inquire.push_back({l,r});
        alls.push_back(l);
        alls.push_back(r);
    }

    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());

    for(auto item:add){
        int x=find(item.first);
        a[x]+=item.second;
    }

    for(int i=0;i<=alls.size();i++){
        s[i]=s[i-1]+a[i];
    }

    for(auto item:inquire){
        int l=find(item.first),r=find(item.second);
        cout<<s[r]-s[l-1]<<endl;
    }
    return 0;

}