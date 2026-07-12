#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main(){
  const int INF=2e9;
  int n;
  std::string s;
  std::cin>>n>>s;
  std::vector<int> rsw_west(n+2),rsw_east(n+2);
  for(int i=1;i<=n;i++){
    if(s[i-1]=='W'){
      rsw_west[i]++;
    }
    rsw_west[i]+=rsw_west[i-1];
  }
  for(int i=n;i>=1;i--){
    if(s[i-1]=='E'){
      rsw_east[i]++;
    }
    rsw_east[i]+=rsw_east[i+1];
  }
  int min=INF;
  for(int i=1;i<=n;i++){
    min=std::min(min,rsw_west[i-1]+rsw_east[i+1]);
  }
  std::cout<<min<<'\n';
  return 0;
}