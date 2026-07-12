#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s;
  cin>>n>>s;
  vector<pair<int,char>> w(n);
  int base_adlt_cnt=0;
  int base_chld_cnt=0;
  for(int i=0;i<n;i++){
    cin>>w[i].first;
    w[i].second=s[i];
    if(s[i]=='1'){
      base_adlt_cnt++;
    }
  }
  sort(w.begin(),w.end());
  int ans=base_adlt_cnt;
  for(int i=0;i<n;i++){
    if(i>=1&&w[i].first!=w[i-1].first){
      ans=max(ans,base_adlt_cnt+base_chld_cnt);
    }
    int x=w[i].first;
    if(w[i].second=='1'){
      base_adlt_cnt--;
    }else if(w[i].second=='0'){
      base_chld_cnt++;
    }
  }
  ans=max(ans,base_adlt_cnt+base_chld_cnt);
  cout<<ans<<endl;
  return 0;
}