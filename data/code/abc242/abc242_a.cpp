#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,x;
  cin>>a>>b>>c>>x;
  if(a>=x){
    cout<<1<<endl;
  }else if(a<x&&x<=b){
    cout<<fixed<<setprecision(10);
    cout<<(double)c/((double)b-a)<<endl;
  }else{
    cout<<0<<endl;
  }
  return 0;
}