#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;cin>>n;
    long long nowVal=1;
    for(long long i=1;;i++){
        if(i*i>n){
            break;
        }
        nowVal=i*i;
    }
    cout<<nowVal<<endl;
    return 0;
}