#include <bits/stdc++.h>
using namespace std;

int main(){
  string s,t;
  cin>>s>>t;
  if(s==t){
    cout<<0<<endl;
    return 0;
  }
  int sn=s.size();
  int tn=t.size();
  int mi=min(sn,tn);
  for(int i=0;i<mi;i++){
    if(s[i]!=t[i]){
      cout<<i+1<<endl;
      return 0;
    }
  }
  cout<<mi+1<<endl;
  return 0;
}