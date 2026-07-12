#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
const ll MOD=998244353;

ll keta(ll n){
  ll ret=0;
  while(n!=0) ret++,n/=10;
  return ret;
}

ll tosa(ll n){
  if(n%2){
    ll x=(n+1)/2;
    x%=MOD;
    ll y=n;
    y%=MOD;
    return x*y%MOD;
  }else{
    ll x=n/2;
    x%=MOD;
    ll y=n+1;
    y%=MOD;
    return x*y%MOD;
  }
}

ll powll(ll a,ll b){
  ll ret=1;
  for(int i=0;i<b;i++) ret*=a;
  return ret;
}

int main(){
  ll n;
  cin>>n;
  ll ket=keta(n);
  ll ans=0;
  for(int k=1;k<ket;k++){
    ans+=tosa(9*powll(10,(k-1)));
    if(ans>MOD) ans%=MOD;
  }
  ans+=tosa(1+n-powll(10,(ket-1)));
  if(ans>MOD) ans%=MOD;
  cout<<ans<<endl;
  return 0;
}