#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> L(n),R(n);
  map<int,int> l_max_of_r;
  for(int i=0;i<n;i++){
    cin>>L[i]>>R[i];
    l_max_of_r[R[i]]=max(l_max_of_r[R[i]],L[i]);
  }
  int l_min_ok=1;
  ll ans=0;
  for(int r=1;r<=m;r++){
    if(l_max_of_r.count(r)){
      int l_max=l_max_of_r[r];
      if(l_min_ok<=l_max){
        l_min_ok=l_max+1;
      }
    }
    if(r<l_min_ok)continue;
    ans+=r-l_min_ok+1;
  }
  cout<<ans<<endl;
  return 0;
}
