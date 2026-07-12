#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> a(n),b(m);
  priority_queue<int> pq;
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<m;i++) cin>>b[i],pq.push(b[i]);
  map<int,int> mp;
  for(int i=0;i<n;i++){
    while(!pq.empty()&&pq.top()>=a[i]){
      mp[pq.top()]=i+1;
      pq.pop();
    }
  }
  while(!pq.empty()){
    mp[pq.top()]=-1;
    pq.pop();
  }
  for(int i=0;i<m;i++){
    cout<<mp[b[i]]<<" ";
  }
  cout<<endl;
  return 0;
}