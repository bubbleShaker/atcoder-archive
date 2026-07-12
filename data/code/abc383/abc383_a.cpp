#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> t(n),v(n);
  for(int i=0;i<n;i++) cin>>t[i]>>v[i];
  int now=v[0];
  for(int i=1;i<n;i++){
    int dec=t[i]-t[i-1];
    if(dec<now){
      now-=dec;
    }else{
      now=0;
    }
    now+=v[i];
  }
  cout<<now<<endl;
  return 0;
}