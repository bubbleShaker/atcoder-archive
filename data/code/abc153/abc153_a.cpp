#include <bits/stdc++.h>
using namespace std;
int ceili(int a,int b){
  return (a+(b-1))/b;
}
int main(){
  int h,a;
  cin>>h>>a;
  cout<<ceili(h,a)<<endl;
  return 0;
}