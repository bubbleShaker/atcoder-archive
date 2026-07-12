#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll N;

ll dfs(string &S){
  ll ret=0;
  vector<char> lis={'3','5','7'};
  if(S.size()>0){
    bool ok=true;
    if(stoll(S)>N){
      return ret;
    }
    for(auto &c:lis){
      if(S.find(c)==string::npos) ok=false;
    }
    if(ok) ret++;
  }
  for(auto &c:lis){
    S.push_back(c);
    ret+=dfs(S);
    S.pop_back();
  }
  return ret;
}

int main(){
  cin>>N;
  string S="";
  cout<<dfs(S)<<endl;
}