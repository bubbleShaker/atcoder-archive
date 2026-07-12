#include <bits/stdc++.h>
using namespace std;

int main(){
    long long h;cin>>h;
    long long count=0;
    long long keisu=1;
    while(h!=0){
        count+=keisu;
        h/=2;
        keisu*=2;
    }
    cout<<count<<endl;
    return 0;
}