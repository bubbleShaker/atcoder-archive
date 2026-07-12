#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,m;

bool is_ok(ll x){
  return 0<=x&&x<=n;
}

int main(){
  cin>>n>>m;
  for(ll x=0;x<=n;x++){
    ll z=m-3*n+x;
    ll y=n-x-z;
    if(is_ok(x)&&is_ok(y)&&is_ok(z)){
      cout<<x<<" "<<y<<" "<<z<<endl;
      return 0;
    }
  }
  cout<<"-1 -1 -1"<<endl;
  return 0;
}