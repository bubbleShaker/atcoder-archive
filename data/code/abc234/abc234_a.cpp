#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  auto f=[&](int t){
    return t*t+2*t+3;
  };
  cout<<f(f(f(t)+t)+f(f(t)))<<'\n';
  return 0;
}