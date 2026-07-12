#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int n,k;
  ll MOD=1e9;
  cin>>n>>k;
  if(n<k){
    cout<<1<<endl;
    return 0;
  }else if(n==k){
    cout<<k<<endl;
    return 0;
  }
  vector<ll> a(n+1);
  for(int i=0;i<k;i++){
    a[i]=1;
  }
  ll rsw=k;
  for(int i=k;i<=n;i++){
    a[i]=rsw;
    rsw-=a[i-k];
    rsw+=a[i];
    while(rsw<0){
      rsw+=MOD;
    }
    a[i]%=MOD;
    rsw%=MOD;
  }
  cout<<a[n]<<endl;
  return 0;
}