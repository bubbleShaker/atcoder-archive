#include <bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  cin>>h>>w;
  vector<string> s(h);
  for(int i=0;i<h;i++){
    cin>>s[i];
  }
  int x_min=2000,y_min=2000;
  int x_max=0,y_max=0;
  for(int j=0;j<w;j++){
    for(int i=0;i<h;i++){
      if(s[i][j]=='#'){
        x_min=min(x_min,i);
        x_max=max(x_max,i);
      }
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s[i][j]=='#'){
        y_min=min(y_min,j);
        y_max=max(y_max,j);
      }
    }
  }
  for(int i=x_min;i<=x_max;i++){
    for(int j=y_min;j<=y_max;j++){
      if(s[i][j]=='.'){
        cout<<"No"<<endl;
        return 0;
      }
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}