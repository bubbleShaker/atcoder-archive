#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> b(n);
  map<int,int> mp;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    if(mp.count(a)==false){
      b[i]=-1;
    }else{
      b[i]=mp[a];
    }
    mp[a]=i+1;
  }
  for(int i=0;i<n;i++){
    cout<<b[i]<<" ";
  }
  cout<<endl;
  return 0;
}