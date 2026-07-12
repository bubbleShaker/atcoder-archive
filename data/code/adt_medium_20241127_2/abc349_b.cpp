#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  map<char,int> mp;
  map<int,set<char>> mpst;
  for(int i=0;i<s.size();i++){
    mp[s[i]]++;
  }
  for(auto [ch,cn]:mp){
    mpst[cn].insert(ch);
  }
  for(auto [cn,st]:mpst){
    if(st.size()!=2){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}