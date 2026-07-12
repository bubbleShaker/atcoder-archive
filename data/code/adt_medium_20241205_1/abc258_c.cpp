#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,q;
  cin>>n>>q;
  string s;
  cin>>s;
  int sen=0;//先頭のind
  while(q--){
    int t,x;
    cin>>t>>x;
    if(t==1){
      sen-=x;
      sen=(sen+n)%n;//負数への対応
    }
    if(t==2){
      x--;
      int ind=sen+x;
      ind=(ind)%n;
      cout<<s[ind]<<endl;
    }
  }
  return 0;
}