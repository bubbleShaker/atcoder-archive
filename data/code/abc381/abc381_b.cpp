#include <bits/stdc++.h>
using namespace std;

bool is_ok(string s){
  int n=s.size();
  if(n%2){
    return false;
  }
  set<char> st;
  for(int i=0;i<n/2;i++){
    if(s[2*i]!=s[2*i+1]){
      return false;
    }
    if(st.count(s[2*i])){
      return false;
    }else{
      st.insert(s[2*i]);
    }
  }
  return true;
}

int main(){
  string s;
  cin>>s;
  if(is_ok(s)){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}