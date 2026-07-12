#include <bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin>>h>>w;
  vector<vector<int>> x(h+1,vector<int>(w+1));
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      cin>>x[i][j];
    }
  }
  vector<vector<int>> rsw(h+1,vector<int>(w+1));
  //列方向への累積和
  for(int i=0;i<=h;i++){
    for(int j=1;j<=w;j++){
      rsw[i][j]+=x[i][j]+rsw[i][j-1];
    }
  }
  //行方向への累積和
  for(int j=0;j<=w;j++){
    for(int i=1;i<=h;i++){
      rsw[i][j]+=rsw[i-1][j];
    }
  }
  int q;
  cin>>q;
  while(q--){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<rsw[c][d]+rsw[a-1][b-1]-rsw[a-1][d]-rsw[c][b-1]<<'\n';
  }
  return 0;
}