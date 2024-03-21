#include<iostream>
using namespace std;
const int N = 110;
int n;
int a[N];
void quick_sort(int a[],int l,int r){

}
int main(){
    cin>>n;
    int k;
    while(n--){
        cin>>k;
        int min=1e9;
        int max=0;
        for(int i=0;i<k;i++){
            cin>>a[i];
            if(a[i]>=max){
                max=a[i];
            }
            if(a[i]<=min){
                min=a[i];
            }
        }
        cout<<max-min<<endl;
    }
    return 0;
}