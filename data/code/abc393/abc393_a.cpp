#include <bits/stdc++.h>
using namespace std;

int main(){
  string s1,s2;
  cin>>s1>>s2;
  if(s1==s2){
    if(s1=="sick"){
      cout<<1<<endl;
    }else{
      cout<<4<<endl;
    }
  }else if(s1=="sick"){
    cout<<2<<endl;
  }else{
    cout<<3<<endl;
  }
  return 0;
}