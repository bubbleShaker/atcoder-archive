#include <bits/stdc++.h>
using namespace std;
long long modpowll(long long a,long long b,long long MOD){
    map<long long,long long> A;
    long long ans=1;
    A[1LL<<0]=a;
    for(int i=0;(1LL<<i)<=b;i++){
        if(i>=1){
            A[1LL<<i]=A[1LL<<(i-1)]*A[1LL<<(i-1)];
            A[1LL<<i]%=MOD;
        }
        if((b|(1LL<<i))==b){
            ans*=A[(1LL<<i)];
        }
        ans%=MOD;
    }
    return ans;
}
int main(){
    const long long MOD=(long long)1e9+7;
    long long a,b;
    cin>>a>>b;
    cout<<modpowll(a,b,MOD)<<endl;
    return 0;
}