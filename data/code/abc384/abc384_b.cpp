#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,r;
  cin>>n>>r;
  int now=r;
  for(int i=0;i<n;i++){
    int d,a;
    cin>>d>>a;
    if(d==1){
      if(1600<=now&&now<=2799){
        now+=a;
      }
    }
    if(d==2){
      if(1200<=now&&now<=2399){
        now+=a;
      }
    }
  }
  cout<<now<<endl;
  return 0;
}