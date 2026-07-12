#include <bits/stdc++.h>
using namespace std;

bool isprime(int val){
    int cnt=0;
    for(int i=1;i<=val;i++){
        if(val%i==0)cnt++;
    }
    return cnt==2;
}

int main(){
    int n;cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++)sum+=i;
    if(isprime(sum))cout<<"WANWAN"<<endl;
    else cout<<"BOWWOW"<<endl;
    return 0;
}