#include <iostream>
#include <vector>
#include <algorithm>
int main(){
  int n;
  std::cin>>n;
  std::vector a(2*n,std::vector<int>(2*n));
  for(int i=0;i<2*n;i++){
    for(int j=i+1;j<2*n;j++){
      std::cin>>a[i][j];
    }
  }
  std::vector<bool> is_used(2*n);
  long long sum=0;
  long long ans=0;
  auto dfs=[&](auto dfs,int first,int second)->void{
    // std::cout<<first<<" "<<second<<"/";
    is_used[first]=true;
    is_used[second]=true;
    sum^=a[first][second];
    bool finised=true;
    for(int i=0;i<2*n;i++){
      if(is_used[i]==false){
        finised=false;
      }
    }
    if(finised){
      ans=std::max(ans,sum);
      // std::cout<<'\n';
    }else{
      int nfirst;
      for(int i=0;i<2*n;i++){
        if(is_used[i]==false){
          nfirst=i;
          break;
        }
      }
      for(int nsecond=nfirst+1;nsecond<2*n;nsecond++){
        if(is_used[nsecond]==false){
          dfs(dfs,nfirst,nsecond);
        }
      }
    }
    is_used[first]=false;
    is_used[second]=false;
    sum^=a[first][second];
  };
  for(int i=1;i<2*n;i++){
    dfs(dfs,0,i);
  }
  std::cout<<ans<<'\n';
  return 0;
}