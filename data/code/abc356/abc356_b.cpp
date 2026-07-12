#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<int> a(m);
  for(auto &&in:a){
    cin>>in;
  }
  vector<vector<int>> x(n,vector<int>(m));
  for(auto &&row:x){
    for(auto &&in:row){
      cin>>in;
    }
  }
  vector<int> vec(m);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      vec[j]+=x[i][j];
    }
  }
  for(int i=0;i<m;i++){
    if(vec[i]<a[i]){
      cout<<"No"<<'\n';
      return 0;
    }
  }
  cout<<"Yes"<<'\n';
  return 0;
}