#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  vector<pair<int,int>> ans;
  stack<pair<char,int>> stk;
  int n=s.size();
  for(int i=0;i<n;i++){
    if(!stk.empty()){
      if(s[i]==')'){
        ans.push_back({stk.top().second,i});
        stk.pop();
      }else{
        stk.push({s[i],i});
      }
    }else{
      stk.push({s[i],i});
    }
  }
  sort(ans.begin(),ans.end(),[&](pair<int,int> a,pair<int,int> b){
    int aMax=max(a.first,a.second);
    int bMax=max(b.first,b.second);
    return aMax<=bMax;
  });
  int m=ans.size();
  for(int i=0;i<m;i++){
    cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
  }
  return 0;
}