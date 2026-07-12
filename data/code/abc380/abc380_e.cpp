#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,q;
  cin>>n>>q;
  vector<int> cnt(n+1,1);
  set<pair<int,int>> s;
  for(int i=0;i<n;i++) s.insert({i,i});
  s.insert({-1,2e9});
  s.insert({n,2e9});
  while(q--){
    int t;
    cin>>t;
    if(t==1){
      int x,c;
      cin>>x>>c;
      x--;c--;
      auto it=s.lower_bound({x,2e9});
      auto [R,Rc]=*it;
      auto [L,Mc]=*--it;
      auto [_,Lc]=*--it;
      cnt[Mc]-=R-L;
      cnt[c]+=R-L;
      it++;
      it=s.erase(it);
      if(Rc==c){
        it=s.erase(it);
      }
      if(Lc==c){
        //pass
      }else{
        s.insert({L,c});
      }
    }else{
      int c;
      cin>>c;
      c--;
      cout<<cnt[c]<<endl;
    }
  }
}