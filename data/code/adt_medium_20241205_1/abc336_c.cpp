#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll powll(long long a,int b){
  long long ret=1;
  for(int i=0;i<b;i++){
    ret*=a;
  }
  return ret;
}

int main(){
  ll n;
  cin>>n;
  n--;
  ll ans=0;
  for(int k=20;k>=0;k--){
    if(n>=powll(5,k)){
      ll syo=n/powll(5,k);
      ans+=2*powll(10,k)*syo;
      n-=powll(5,k)*syo;
    }
  }
  cout<<ans<<endl;
  return 0;
}