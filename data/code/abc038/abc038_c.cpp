#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  ll l=0,r=1;
  ll ans=0;
  while(r<n){
    if(a[r-1]<a[r]){
      r++;
    }else{
      ll m=r-l;
      ans+=(m*(m+1))/2;
      l=r;
      r=r+1;
    }
  }
  ll m=r-l;
  ans+=(m*(m+1))/2;
  cout<<ans<<endl;
  return 0;
}