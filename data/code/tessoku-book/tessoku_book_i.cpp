#include <bits/stdc++.h>
using namespace std;
int main(){
  int h,w,n;
  cin>>h>>w>>n;
  vector<vector<int>> imos(h+2,vector<int>(w+2));
  for(int i=0;i<n;i++){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    imos[a][b]++;
    imos[a][d+1]--;
    imos[c+1][b]--;
    imos[c+1][d+1]++;
  }
  //列方向に累積和
  for(int i=0;i<=h;i++){
    for(int j=1;j<=w;j++){
      imos[i][j]+=imos[i][j-1];
    }
  }
  //行方向に累積和
  for(int j=0;j<=w;j++){
    for(int i=1;i<=h;i++){
      imos[i][j]+=imos[i-1][j];
    }
  }
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      cout<<imos[i][j]<<((j!=w)?' ':'\n');
    }
  }
  return 0;
}