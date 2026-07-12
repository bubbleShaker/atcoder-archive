#include <iostream>
#include <algorithm>
#include <vector>
int main(){
  long long n;
  std::cin>>n;
  std::vector<long long> ans;
  for(long long i=1;i*i<=n;i++){
    if(n%i==0){
      if(i*i!=n){
        ans.push_back(i);
        ans.push_back(n/i);
      }else{
        ans.push_back(i);
      }
    }
  }
  std::sort(ans.begin(),ans.end());
  for(int i=0;i<ans.size();i++){
    std::cout<<ans[i]<<'\n';
  }
  return 0;
}