#include <bits/stdc++.h>
using namespace std;
int main(){
  int d,t,s;
  cin>>d>>t>>s;
  auto ceili=[&](int a,int b){
    return (a+(b-1))/b;
  };
  cout<<((ceili(d,s)<=t)?"Yes":"No")<<'\n';
  return 0;
}