#include <bits/stdc++.h>
using namespace std;

int main(){
  const int INF=1e9;
  int n,m;
  cin>>n>>m;
  vector<int> imos(n+2);
  for(int i=0;i<m;i++){
    int l,r;
    cin>>l>>r;
    imos[l]++;
    imos[r+1]--;
  }
  for(int i=0;i<=n;i++){
    imos[i+1]+=imos[i];
  }
  int ans=INF;
  for(int i=1;i<=n;i++){
    ans=min(ans,imos[i]);
  }
  cout<<ans<<endl;
  return 0;
}