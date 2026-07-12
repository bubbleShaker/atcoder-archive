#include <bits/stdc++.h>
using namespace std;

int main(){
  int n=8;
  vector<string> s(n);
  for(int i=0;i<n;i++){
    cin>>s[i];
  }
  set<int> set_i,set_j;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(s[i][j]=='#'){
        set_i.insert(i);
        set_j.insert(j);
      }
    }
  }
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(set_i.count(i)||set_j.count(j)){
        continue;
      }
      ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}