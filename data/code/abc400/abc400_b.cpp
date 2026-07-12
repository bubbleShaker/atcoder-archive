#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  auto powll=[&](long long a,int b){
    long long ret=1;
    for(int i=0;i<b;i++){
      ret*=a;
    }
    return ret;
  };
  ll N,M;
  cin>>N>>M;
  ll X=0;
  for(ll i=0;i<=M;i++){
    X+=powll(N,i);
    if(X>(ll)1e9){
      cout<<"inf"<<endl;
      return 0;
    }
  }
  cout<<X<<endl;
  return 0;
}