#include <bits/stdc++.h>
using namespace std;

int main(){
  string s,t;
  cin>>s>>t;
  set<string> st;
  for(int i=0;i<=(int)s.size()-(int)t.size();i++){
    st.insert(s.substr(i,t.size()));
  }
  if(st.count(t)){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}