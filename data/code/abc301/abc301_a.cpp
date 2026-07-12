#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s;
  cin>>n>>s;
  map<char,int> mp;
  for(int i=0;i<n;i++){
    mp[s[i]]++;
    if(mp[s[i]]==(n+1)/2){
      cout<<s[i]<<endl;
      return 0;
    }
  }
  return 0;
}