#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int n;
  cin>>n;
  vector<ll> l(n),r(n);
  vector<ll> inc(n);
  ll mi=0,ma=0;
  for(int i=0;i<n;i++) cin>>l[i]>>r[i],mi+=l[i],ma+=r[i],inc[i]=r[i]-l[i];
  if(ma<0||mi>0){
    cout<<"No"<<endl;
    return 0;
  }
  ll re=-mi;
  vector<ll> ans=l;
  for(int i=0;i<n;i++){
    if(re==0) break;
    if(inc[i]<=re){
      ans[i]+=inc[i];
      re-=inc[i];
    }else{
      ans[i]+=re;
      re=0;
    }
  }
  cout<<"Yes"<<endl;
  for(int i=0;i<n;i++){
    cout<<ans[i]<<" ";
  }
  cout<<endl;
  return 0;
}