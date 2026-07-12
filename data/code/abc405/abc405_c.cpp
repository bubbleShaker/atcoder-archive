#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int n;
  cin>>n;
  vector<ll> a(n);
  ll rsw=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    rsw+=a[i];
  }
  ll ans=0;
  rsw-=a[0];
  for(int i=0;i<n-1;i++){
    ans+=a[i]*rsw;
    rsw-=a[i+1];
  }
  cout<<ans<<endl;
  return 0;
}