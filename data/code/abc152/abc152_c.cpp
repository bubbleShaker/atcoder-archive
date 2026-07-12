#include <iostream>
int main(){
  const int INF=2e9;
  int n;
  std::cin>>n;
  int min=INF;
  int ans=0;
  for(int i=0;i<n;i++){
    int p;
    std::cin>>p;
    if(min>=p){
      ans++;
      min=p;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}