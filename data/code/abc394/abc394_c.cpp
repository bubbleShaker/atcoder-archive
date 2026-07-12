#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  int n=s.size();
  for(int i_start=n-2;i_start>=0;i_start--){
    if(s.substr(i_start,2)=="WA"){
      s[i_start]='A';
      s[i_start+1]='C';
    }
  }
  cout<<s<<endl;
  return 0;
}