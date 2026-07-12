#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,d;
  string s;
  cin>>n>>d>>s;
  int dot=0,cok=0;
  for(int i=0;i<n;i++){
    if(s[i]=='@')cok++;
    else dot++;
  }
  if(d<=cok){
    cout<<dot+d<<endl;
  }else{
    cout<<dot+cok<<endl;
  }
  return 0;
}