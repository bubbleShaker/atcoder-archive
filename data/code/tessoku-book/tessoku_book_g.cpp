#include <bits/stdc++.h>
using namespace std;
int main(){
  int d,n;
  cin>>d>>n;
  vector<int> imos(d+10);
  for(int i=0;i<n;i++){
    int l,r;
    cin>>l>>r;
    imos[l]++;
    imos[r+1]--;
  }
  for(int i=1;i<=d;i++){
    imos[i]+=imos[i-1];
  }
  for(int i=1;i<=d;i++){
    cout<<imos[i]<<'\n';
  }
  return 0;
}