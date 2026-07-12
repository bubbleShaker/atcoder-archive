#include <iostream>
#include <vector>
#include <numeric>
int main(){
  int n,k;
  std::cin>>n>>k;
  std::vector<int> r(n);
  for(int i=0;i<n;i++){
    std::cin>>r[i];
  }
  std::vector<std::vector<int>> ans;
  auto dfs=[&](auto dfs,std::vector<int> vec)->void{
    if(vec.size()==n){
      int sum=std::accumulate(vec.begin(),vec.end(),0);
      if(sum%k==0){
        ans.push_back(vec);
      }
    }else{
      int idx=vec.size();
      for(int i=1;i<=r[idx];i++){
        vec.push_back(i);
        dfs(dfs,vec);
        vec.pop_back();
      }
    }
  };
  std::vector<int> vec;
  dfs(dfs,vec);
  int m=ans.size();
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      std::cout<<ans[i][j]<<((j!=n-1)?' ':'\n');
    }
  }
  return 0;
}