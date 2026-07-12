#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,Q;
  cin>>N>>Q;
  map<int,int> mp,mp_nest,nest_mp;
  for(int i=1;i<=N;i++){
    mp[i]=i;
    mp_nest[i]=i;
    nest_mp[i]=i;
  }
  while(Q--){
    int op;
    cin>>op;
    if(op==1){
      int a,b;
      cin>>a>>b;
      mp[a]=nest_mp[b];
    }
    if(op==2){
      int a,b;
      cin>>a>>b;
      swap(nest_mp[a],nest_mp[b]);
      swap(mp_nest[nest_mp[a]],mp_nest[nest_mp[b]]);
    }
    if(op==3){
      int a;
      cin>>a;
      int nest=mp[a];
      cout<<mp_nest[nest]<<endl;
    }
  }
  return 0;
}