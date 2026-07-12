#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;cin>>n;
    map<long long,long long> memoMap;
    auto f=[&](auto f,long long n)->long long{
        if(n==0)return 1;
        else if(memoMap.count(n))return memoMap[n];
        return memoMap[n]=f(f,n/2)+f(f,n/3);
    };
    cout<<f(f,n)<<endl;
    return 0;
}