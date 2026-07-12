#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  vector<int> a;
  int cnt=0;
  for(int i=1;i<s.size();i++){
    if(s[i]=='-'){
      cnt++;
    }else if(s[i]=='|'){
      a.push_back(cnt);
      cnt=0;
    }
  }
  for(int i=0;i<a.size();i++) cout<<a[i]<<" ";
  cout<<endl;
  return 0;
}