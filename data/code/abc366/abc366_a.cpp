#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,t,a;
  cin>>n>>t>>a;
  int ma=max(t,a);
  if(ma>=n/2+1){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}