#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll N,T;
  cin>>N>>T;
  vector<ll> A(N+1);
  vector<ll> rsw(N+1);
  for(int i=1;i<=N;i++) cin>>A[i];
  for(int i=1;i<=N;i++) rsw[i]=rsw[i-1]+A[i];
  ll sum=accumulate(A.begin(),A.end(),0LL);
  ll pt=T%sum;
  int ind=lower_bound(rsw.begin(),rsw.end(),pt)-rsw.begin();
  ind--;
  cout<<ind+1<<" "<<pt-rsw[ind]<<endl;
}