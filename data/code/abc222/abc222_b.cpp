#include <iostream>
int main(){
  int n,p;
  std::cin>>n>>p;
  int ans=0;
  for(int i=0;i<n;i++){
    int a;
    std::cin>>a;
    if(a<p){
      ans++;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}