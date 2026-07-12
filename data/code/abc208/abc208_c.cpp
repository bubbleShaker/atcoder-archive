#include <iostream>
#include <algorithm>
#include <vector>
int main(){
  long long n,k;
  std::cin>>n>>k;
  std::vector<long long> a(n),sorted_a;
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  sorted_a=a;
  std::sort(sorted_a.begin(),sorted_a.end());
  long long base=k/n;
  for(int i=0;i<n;i++){
    int idx=std::lower_bound(sorted_a.begin(),sorted_a.end(),a[i])-sorted_a.begin();
    if(idx+1<=k%n){
      std::cout<<base+1<<'\n';
    }else{
      std::cout<<base<<'\n';
    }
  }  
  return 0;
}