#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
int main() {
  int n;
  cin>>n;
  map<int,vector<int>> startMap,endMap;
  vector<int> vec;
  for(int i=0;i<n;i++){
    int l,r;
    cin>>l>>r;
    startMap[l].emplace_back(i);
    endMap[r].emplace_back(i);
    vec.emplace_back(l);
    vec.emplace_back(r);
  }
  sort(vec.begin(),vec.end());
  auto itr=unique(vec.begin(),vec.end());
  vec.erase(itr,vec.end());
  set<int> searchSet;
  long long ans=0;
  for(int elem:vec){
    for(int number:startMap[elem]){
      ans+=searchSet.size();
      searchSet.insert(number);
    }
    for(int number:endMap[elem]){
      searchSet.erase(number);
    }
  }
  cout<<ans<<endl;
  return 0;
}