#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> f(int a,int b){
  vector<pair<int,int>> ret;
  
  ret.push_back({a+2,b+1});
  ret.push_back({a+2,b-1});
  ret.push_back({a-2,b+1});
  ret.push_back({a-2,b-1});
  
  ret.push_back({a+1,b+2});
  ret.push_back({a-1,b+2});
  ret.push_back({a+1,b-2});
  ret.push_back({a-1,b-2});
  
  return ret;
}

int main(){
  long long n;
  int m;
  cin>>n>>m;
  long long ans=n*n;
  set<pair<int,int>> st_p;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    st_p.insert({a,b});
    vector<pair<int,int>> pairs=f(a,b);
    for(int j=0;j<8;j++){
      pair<int,int> p=pairs[j];
      auto [x,y]=p;
      if(x<=0||x>n||y<=0||y>n){
        continue;
      }
      st_p.insert(p);
    }
  }
  ans-=(long long)st_p.size();
  cout<<ans<<endl;
  return 0;
}