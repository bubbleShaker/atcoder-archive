#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  string s;
  cin>>s;
  map<char,vector<ll>> char_idx;
  for(int i=0;i<s.size();i++){
    char_idx[s[i]].push_back(i);
  }
  map<char,vector<ll>> char_idx_rsw;
  for(auto [c,idx_vec]:char_idx){
    char_idx_rsw[c]=idx_vec;
    for(int i=idx_vec.size()-1;i>0;i--){
      char_idx_rsw[c][i-1]+=char_idx_rsw[c][i];
    }
  }
  ll ans=0;
  for(auto [c,idx_rsw]:char_idx_rsw){
    int n=idx_rsw.size();
    for(int i=0;i<n-1;i++){
      ll cnt=n-i-1;
      ans+=idx_rsw[i+1]-char_idx[c][i]*cnt-cnt;
    }
  }
  cout<<ans<<endl;
  return 0;
}