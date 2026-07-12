#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s;
  cin>>n>>s;
  int x=0,y=0;
  vector<int> dx={0,1,0,-1};
  vector<int> dy={1,0,-1,0};
  int idx=1;
  for(int i=0;i<n;i++){
    if(s[i]=='S'){
      x+=dx[idx];
      y+=dy[idx];
    }else{
      idx++;
      idx%=4;
    }
  }
  cout<<x<<" "<<y<<endl;
  return 0;
}