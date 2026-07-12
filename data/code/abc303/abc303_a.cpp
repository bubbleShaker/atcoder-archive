#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  string s,t;
  cin>>s>>t;
  for(int i=0;i<n;i++){
    if(s[i]=='0')s[i]='o';
    if(t[i]=='0')t[i]='o';
    if(s[i]=='1')s[i]='l';
    if(t[i]=='1')t[i]='l';
  }
  if(s==t){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}