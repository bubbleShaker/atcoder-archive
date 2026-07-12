#include <bits/stdc++.h>
using namespace std;

int main(){
  unsigned long long ans=0,num=1;
  for(int i=0;i<64;i++){
    unsigned long long a;
    cin>>a;
    if(a==1) ans+=num;
    num*=2;
  }
  cout<<ans<<endl;
  return 0;
}