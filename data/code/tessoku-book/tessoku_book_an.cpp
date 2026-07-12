#include <bits/stdc++.h>
using namespace std;
long long nC3(long long n){
  return (n*(n-1)*(n-2))/(3*2);
}
int main(){
  long long n;
  cin>>n;
  map<long long,long long> mp;
  for(int i=0;i<n;i++){
    long long a;
    cin>>a;
    mp[a]++;
  }
  long long ans=0;
  for(auto [a,cnt]:mp){
    ans+=nC3(cnt);
  }
  cout<<ans<<endl;
  return 0;
}