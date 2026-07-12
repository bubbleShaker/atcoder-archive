#include <iostream>
#include <vector>
int main(){
  int n,t;
  std::cin>>n>>t;
  std::vector<int> a(n);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  int ans=0;
  for(int i=0;i<n-1;i++){
    if(a[i]+t>=a[i+1]){
      ans+=a[i+1]-a[i];
    }else{
      ans+=t;
    }
  }
  ans+=t;
  std::cout<<ans<<'\n';
  return 0;
}