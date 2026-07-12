#include <bits/stdc++.h>
using namespace std;

long long modpow(long long a,long long n,long long MOD){
    int l=62;
    long long powVal=1;
    long long res=1;
    long long nowA=1;
    long long nowN=n;
    vector<long long> forPowVec(l);
    set<long long> powValSet;
    for(int i=0;i<l;i++){
        forPowVec[i]=powVal;
        powVal*=2;
    }
    while(nowN!=0){
        long long ind=upper_bound(forPowVec.begin(),forPowVec.end(),nowN)-forPowVec.begin();
        ind--;
        powValSet.insert(forPowVec[ind]);
        nowN-=forPowVec[ind];
    }
    powVal=1;
    for(int j=1;j<=l;j++){
        if(j==1){
            nowA*=a;
        }else{
            nowA*=nowA;
            nowA%=MOD;
        }
        if(powValSet.count(powVal)){
            res*=nowA;
            res%=MOD;
        }
        powVal*=2;
    }
    return res;
}

int main(){
    long long n,p;cin>>n>>p;
    const long long MOD=(long long)1e9+7;
    long long ans=(p-1)*modpow(p-2,n-1,MOD);
    ans%=MOD;
    cout<<ans<<endl;
    return 0;
}