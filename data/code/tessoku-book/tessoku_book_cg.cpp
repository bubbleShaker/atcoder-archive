#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<vector<int>> grid(1510+1,vector<int>(1510+1));
  for(int i=0;i<n;i++){
    int x,y;
    cin>>x>>y;
    grid[x][y]++;
  }
  vector<vector<int>> rsw(1510+1,vector<int>(1510+1));
  //列方向への累積和
  for(int i=0;i<=1510;i++){
    for(int j=1;j<=1510;j++){
      rsw[i][j]+=grid[i][j]+rsw[i][j-1];
    }
  }
  //行方向への累積和
  for(int j=0;j<=1510;j++){
    for(int i=1;i<=1510;i++){
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