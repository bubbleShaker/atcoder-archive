#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin>>a>>b;
  for(int i=0;i<=9;i++){
    if(a+b!=i){
      cout<<i<<endl;
      return 0;
    }
  }
  return 0;
}