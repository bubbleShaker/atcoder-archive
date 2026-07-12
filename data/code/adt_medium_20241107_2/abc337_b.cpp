#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  string ns;
  ns+=s[0];
  for(int i=1;i<s.size();i++){
    if(s[i-1]!=s[i]){
      ns+=s[i];
    }
  }
  if(ns=="ABC"||ns=="AB"||ns=="AC"||ns=="BC"||ns=="A"||ns=="B"||ns=="C"){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}