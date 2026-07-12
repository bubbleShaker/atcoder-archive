#include <bits/stdc++.h>
using namespace std;
int main(){
  int x,y;
  cin>>x>>y;
  vector<pair<int,int>> ans;
  ans.push_back({x,y});
  while(!(x==1&&y==1)){
    if(x>y){
      x=x-y;
    }else{
      y=y-x;
    }
    ans.push_back({x,y});
  }
  reverse(ans.begin(),ans.end());
  int n=ans.size();
  cout<<n-1<<endl;
  for(int i=1;i<n;i++){
    auto [x,y]=ans[i];
    cout<<x<<" "<<y<<endl;
  }
  return 0;
}