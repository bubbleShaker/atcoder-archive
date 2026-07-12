#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int n=s.size();
  set<char> st;
  st.insert('A');
  st.insert('C');
  st.insert('G');
  st.insert('T');
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      bool isOk=true;
      for(int k=i;k<=j;k++){
        if(!st.count(s[k])){
          isOk=false;
          break;
        }
      }
      if(!isOk){
        continue;
      }
      ans=max(ans,j-i+1);
    }
  }
  cout<<ans<<'\n';
  return 0;
}