#include <bits/stdc++.h>
using namespace std;
int main(){
  int t,n;
  cin>>t>>n;
  vector<int> imos(t+10);
  for(int i=0;i<n;i++){
    int l,r;
    cin>>l>>r;
    imos[l]++;
    imos[r]--;
  }
  for(int i=1;i<=t;i++){
    imos[i]+=imos[i-1];
  }
  for(int i=0;i<=t-1;i++){
    cout<<imos[i]<<'\n';
  }
  return 0;
}