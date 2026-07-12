#include <iostream>
#include <vector>
#include <string>
int main(){
  int n;
  std::cin>>n;
  std::vector<std::vector<int>> s(n+1);
  s[1].push_back(1);
  for(int i=2;i<=n;i++){
    for(int j=0;j<s[i-1].size();j++){
      s[i].push_back(s[i-1][j]);
    }
    s[i].push_back(i);
    for(int j=0;j<s[i-1].size();j++){
      s[i].push_back(s[i-1][j]);
    }
  }
  for(int i=0;i<s[n].size();i++){
    std::cout<<s[n][i]<<((i!=s[n].size()-1)?' ':'\n');
  }
  return 0;
}