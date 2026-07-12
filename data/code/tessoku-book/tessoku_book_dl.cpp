#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,d;
  cin>>n>>d;
  map<int,vector<int>> mp;
  for(int i=0;i<n;i++){
    int x,y;
    cin>>x>>y;
    mp[x].push_back(y);
  }
  priority_queue<int> pque;
  int ans=0;
  for(int i=1;i<=d;i++){
    for(int y:mp[i]){
      pque.push(y);
    }
    if(!pque.empty()){
      ans+=pque.top();
      pque.pop();
    }
  }
  cout<<ans<<endl;
  return 0;
}