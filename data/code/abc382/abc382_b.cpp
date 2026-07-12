#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,d;
  string s;
  cin>>n>>d>>s;
  for(int i=n-1;i>=0;i--){
    if(s[i]=='@'){
      if(d>0){
        s[i]='.';
        d--;
      }
    }
  }
  cout<<s<<endl;
  return 0;
}