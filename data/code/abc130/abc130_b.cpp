#include <iostream>
int main(){
  int n,x;
  std::cin>>n>>x;
  int d=0;
  int ans=1;
  for(int i=0;i<n;i++){
    int l;
    std::cin>>l;
    d+=l;
    if(d<=x){
      ans++;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}