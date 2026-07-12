#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int n;
  ll s;
  cin>>n>>s;
  vector<ll> a(n);
  ll sum=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
  }
  s%=sum;
  vector<ll> rsw(2*n+1);
  for(int i=1;i<=2*n;i++){
    rsw[i]=rsw[i-1]+a[(i-1)%n];
  }
  for(int l=0;l<=2*n;l++){
    auto itr=lower_bound(rsw.begin(),rsw.end(),s+rsw[l]);
    if(itr!=rsw.end()&&*itr==s+rsw[l]){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
  return 0;
}