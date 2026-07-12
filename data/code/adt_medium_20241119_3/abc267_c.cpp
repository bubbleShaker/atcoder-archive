#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int n,m;
  cin>>n>>m;
  vector<ll> a(n+1);
  vector<ll> rsw(n+1);
  for(int i=1;i<=n;i++) cin>>a[i]; 
  for(int i=1;i<=n;i++) rsw[i]=rsw[i-1]+a[i]; 
  ll sum=0;
  for(int i=1;i<=m;i++) sum+=i*a[i];
  ll ans=sum;
  for(int i=2;i+m-1<=n;i++){
    sum-=(rsw[i-1+m-1]-rsw[i-2]);
    sum+=m*a[i+m-1];
    ans=max(ans,sum);
  }
  cout<<ans<<endl;
}