#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<string> s(n);
  for(int i=0;i<n;i++) cin>>s[i];
  vector<char> c0={'H' , 'D' , 'C' , 'S'};
  vector<char> c1={ 'A' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' , 'T' , 'J' , 'Q' , 'K'};
  set<char> c0_st,c1_st;
  set<string> s_st;
  for(auto ch:c0) c0_st.insert(ch);
  for(auto ch:c1) c1_st.insert(ch);
  for(int i=0;i<n;i++){
    if(!c0_st.count(s[i][0])){
      cout<<"No"<<endl;
      return 0;
    }
    if(!c1_st.count(s[i][1])){
      cout<<"No"<<endl;
      return 0;
    }
    if(s_st.count(s[i])){
      cout<<"No"<<endl;
      return 0;
    }
    s_st.insert(s[i]);
  }
  cout<<"Yes"<<endl;
  return 0;
}