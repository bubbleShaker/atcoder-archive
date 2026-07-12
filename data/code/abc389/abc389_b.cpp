#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll x;
  cin>>x;
  ll ans=1;
  ll num=1;
  while(num!=x){
    num*=(ans+1);
    ans++;
  }
  cout<<ans<<endl;
  return 0;
}