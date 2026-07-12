#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,k;
vector<ll> a;
ll a_xor_sum=0;
ll ans=0;
bool is_hanten=false;

void dfs(ll k,ll len,ll ind,ll xor_sum){
  if(len==k){
    if(is_hanten){//n-kを選んでいるなら全体のxorとxor
      ans=max(ans,a_xor_sum^xor_sum);
    }else{
      ans=max(ans,xor_sum);
    }
    return;
  }
  if(ind==n)return;
  dfs(k,len+1,ind+1,xor_sum^a[ind]);
  dfs(k,len,ind+1,xor_sum);
}

int main(){
  cin>>n>>k;
  a.resize(n);
  for(int i=0;i<n;i++)cin>>a[i],a_xor_sum^=a[i];
  if(2*k<=n){
    dfs(k,0,0,0);//k個選ぶ
  }else{
    is_hanten=true;
    dfs(n-k,0,0,0);//n-k個選ぶ
  }
  cout<<ans<<endl;
  return 0;
}