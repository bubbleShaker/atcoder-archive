#include <bits/stdc++.h>
using namespace std;
long long modfact(long long n,long long MOD){
    long long ret=1;
    while(n>=1){
        ret*=n;
        n--;
        ret%=MOD;
    }
    return ret;
}
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
long long moddiv(long long a,long long b,long long MOD){
    return a*modpowll(b,MOD-2,MOD)%MOD;
}
int main(){
    const long long MOD=(long long)1e9+7;
    int n,r;
    cin>>n>>r;
    long long a=modfact(n,MOD);
    long long b=modfact(r,MOD)*modfact(n-r,MOD)%MOD;
    cout<<moddiv(a,b,MOD)<<endl;
    return 0;
}