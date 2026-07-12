#include <bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  cin>>h>>w;
  vector<string> s(h);
  for(int i=0;i<h;i++) cin>>s[i];
  int mi_x=1e9,ma_x=-1e9;
  int mi_y=1e9,ma_y=-1e9;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s[i][j]=='#'){
        mi_y=min(mi_y,j);
        ma_y=max(ma_y,j);
      }
    }
  }
  for(int j=0;j<w;j++){
    for(int i=0;i<h;i++){
      if(s[i][j]=='#'){
        mi_x=min(mi_x,i);
        ma_x=max(ma_x,i);
      }
    }
  }
  for(int i=mi_x;i<=ma_x;i++){
    for(int j=mi_y;j<=ma_y;j++){
      if(s[i][j]!='#'){
        cout<<i+1<<" "<<j+1<<endl;
        return 0;
      }
    }
  }
  return 0;
}