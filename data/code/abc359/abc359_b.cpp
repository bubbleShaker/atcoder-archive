#include <iostream>
#include <vector>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> a(2*n);
  for(int i=0;i<2*n;i++){
    std::cin>>a[i];
  }
  int ans=0;
  for(int i=1;i<2*n-1;i++){
    if(a[i-1]==a[i+1]){
      ans++;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}