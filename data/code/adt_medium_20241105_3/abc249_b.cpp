#include <bits/stdc++.h>
using namespace std;

bool is_ok(string s){
  bool f1=false,f2=false,f3=false;
  set<char> st;
  for(int i=0;i<s.size();i++){
    if(isupper(s[i])){
      f1=true;
    }else if(islower(s[i])){
      f2=true;
    }
    st.insert(s[i]);
  }
  if(s.size()==st.size()){
    f3=true;
  }
  return f1&&f2&&f3;
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