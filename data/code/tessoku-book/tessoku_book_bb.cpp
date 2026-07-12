#include <bits/stdc++.h>
using namespace std;
int main(){
  int q;
  cin>>q;
  map<string,int> mp;
  while(q--){
    int type;
    cin>>type;
    if(type==1){
      string x;
      int y;
      cin>>x>>y;
      mp[x]=y;
    }else if(type==2){
      string x;
      cin>>x;
      cout<<mp[x]<<endl;
    }
  }
  return 0;
}