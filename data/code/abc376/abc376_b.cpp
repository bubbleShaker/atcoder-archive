#include <iostream>
#include <utility>
using namespace std;

int f(int s,int t,int x,int n){
  if(t<s){
    swap(s,t);
  }
  if(s<x&&x<t){
    return n-(t-s);
  }else{
    return t-s;
  }
}

int main(){
  int n,q;
  cin>>n>>q;
  int l=0,r=1;
  int ans=0;
  while(q--){
    char h;
    int t;
    cin>>h>>t;
    t--;
    int ret;
    if(h=='L'){
      ret=f(l,t,r,n);
      l=t;
    }else{
      ret=f(r,t,l,n);
      r=t;
    }
    ans+=ret;
  }
  cout<<ans<<endl;
  return 0;
}