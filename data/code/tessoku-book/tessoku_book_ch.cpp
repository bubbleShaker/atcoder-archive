#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<vector<int>> imos(1500+2,vector<int>(1500+2));
  for(int i=0;i<n;i++){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    imos[a][b]++;
    imos[a][d]--;
    imos[c][b]--;
    imos[c][d]++;
  }
  //列方向に累積和
  for(int i=0;i<=1500;i++){
    for(int j=1;j<=1500;j++){
      imos[i][j]+=imos[i][j-1];
    }
  }
  //行方向に累積和
  for(int j=0;j<=1500;j++){
    for(int i=1;i<=1500;i++){
      imos[i][j]+=imos[i-1][j];
    }
  }
  int ans=0;
  for(int i=0;i<=1500;i++){
    for(int j=0;j<=1500;j++){
      if(imos[i][j]>=1){
        ans++;
      }
    }
  }
  cout<<ans<<'\n';
  return 0;
}