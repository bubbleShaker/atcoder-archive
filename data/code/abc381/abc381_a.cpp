#include <bits/stdc++.h>
using namespace std;

bool is_ok(int &n,string &s){
  if(n%2==0){
    return false;
  }
  for(int i=0;i<(n+1)/2-1;i++){
    if(s[i]!='1'){
      return false;
    }
  }
  if(s[(n+1)/2-1]!='/'){
    return false;
  }
  for(int i=(n+1)/2;i<n;i++){
    if(s[i]!='2'){
      return false;
    }
  }
  return true;
}

int main(){
  int n;
  string s;
  cin>>n>>s;
  if(is_ok(n,s)){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}