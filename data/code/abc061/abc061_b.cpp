#include <iostream>
#include <vector>
int main(){
  int n,m;
  std::cin>>n>>m;
  std::vector<int> deg(n);
  for(int i=0;i<m;i++){
    int a,b;
    std::cin>>a>>b;
    deg[--a]++;
    deg[--b]++;
  }
  for(int i=0;i<n;i++){
    std::cout<<deg[i]<<'\n';
  }
  return 0;
}