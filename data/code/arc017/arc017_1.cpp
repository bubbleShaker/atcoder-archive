#include <bits/stdc++.h>
using namespace std;

bool isprime(int n){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(n%i==0)cnt++;
    }
    return cnt==2;
}

int main(){
    int n;cin>>n;
    if(isprime(n))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}