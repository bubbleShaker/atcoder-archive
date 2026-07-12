#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,q;
  cin>>n>>q;
  vector<int> a(n+1);
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  vector<int> rsw(n+1);
  for(int i=1;i<=n;i++){
    rsw[i]+=a[i]+rsw[i-1];
  } 
  while(q--){
    int l,r;
    cin>>l>>r;
    cout<<rsw[r]-rsw[l-1]<<'\n';
  }
  return 0;
}