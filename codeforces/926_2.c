#include<iostream>
using namespace std;
const int N = 10000000;
int m;
int a[N];
//每个点都有两个对角线
//所以只需要计算最大需要的点数
int main(){
    cin>>m;
    int n,k;
    while(m--){
       cin>>n>>k;
        if(k % 2==1){

             cout<<(k+1)/2<<endl;
        }else{
             if(k == 4*n -2 ){
                cout<< n*2 <<endl;
            }else{
            cout<<(k/2)<<endl;
            }
        }
    }
    return 0;
}