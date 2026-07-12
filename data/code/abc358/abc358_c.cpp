#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <set>
int main(){
  const int INF=2e9;
  int n,m;
  std::cin>>n>>m;
  std::vector<std::string> s(n);
  for(int i=0;i<n;i++){
    std::cin>>s[i];
  }
  std::vector<int> p(n);
  std::iota(p.begin(),p.end(),0);
  int ans=INF;
  do{
    std::set<int> set;
    for(int i=0;i<n;i++){
      int idx=p[i];
      for(int j=0;j<m;j++){
        if(s[idx][j]=='o'){
          set.insert(j);
        }
      }
      if(set.size()==m){
        ans=std::min(ans,i+1);
        break;
      }
    }
  }while(std::next_permutation(p.begin(),p.end()));
  std::cout<<ans<<'\n';
  return 0;
}