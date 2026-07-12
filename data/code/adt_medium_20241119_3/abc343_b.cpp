#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<vector<int>> G(N);
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      int a;
      cin>>a;
      if(a==1){
        G[i].push_back(j);
      }
    }
  }
  for(int i=0;i<N;i++){
    for(auto v:G[i]){
      cout<<v+1<<" ";
    }cout<<endl;
  }
}