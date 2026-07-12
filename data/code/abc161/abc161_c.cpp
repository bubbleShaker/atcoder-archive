#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,k;cin>>n>>k;
    long long a=n%k;
    long long b=k-a;
    cout<<min(a,b)<<endl;
    return 0;
}