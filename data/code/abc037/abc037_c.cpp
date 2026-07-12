#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int n,k;
  cin>>n>>k;
  vector<ll> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  ll sum=0;
  for(int i=0;i<k;i++){
    sum+=a[i];
  }
  int ind_dec=0;
  int ind_inc=k;
  ll ans=0;
  while(1){
    ans+=sum;
    if(ind_inc==n)break;
    sum-=a[ind_dec++];
    sum+=a[ind_inc++];
  }
  cout<<ans<<endl;
  return 0;
}