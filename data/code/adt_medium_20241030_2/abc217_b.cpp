#include <bits/stdc++.h>
using namespace std;

int main(){
  set<char> st;
  st.insert('B');
  st.insert('R');
  st.insert('G');
  st.insert('H');
  for(int i=0;i<3;i++){
    string s;
    cin>>s;
    st.erase(s[1]);
  }
  cout<<'A'<<*st.begin()<<'C'<<endl;
  return 0;
}