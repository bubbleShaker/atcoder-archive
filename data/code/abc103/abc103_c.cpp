#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int n;
  cin>>n;
  vector<ll> a(n);
  ll ans=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    ans+=a[i]-1;
  }
  cout<<ans<<endl;
  return 0;
}