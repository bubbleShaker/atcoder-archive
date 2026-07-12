#include <iostream>
#include <vector>
int main(){
  int n;
  std::cin>>n;
  std::vector<std::vector<int>> g(n+1);
  for(int i=0;i<n-1;i++){
    int a,b;
    std::cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int d_1=0;
  int d_2=0;
  for(int i=1;i<=n;i++){
    if(g[i].size()==1){
      d_1++;
    }else if(g[i].size()==n-1){
      d_2++;
    }
  }
  std::cout<<((d_1==n-1&&d_2==1)?"Yes":"No")<<'\n';
  return 0;
}