#include <iostream>
#include <cstring>

using namespace std;

int lowbit(int x){
    return x & -x;
}

int main(){
    int n;
    cin>>n;

    while(n--){
        int num;
        cin>>num;

        int res=0;

        while(num){
            num-= lowbit(num);
            res++;
        }
        cout<<res<<" ";
    }
    return 0;
}