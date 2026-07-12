#include <iostream>
#include <vector>
int main(){
  int n,k;
  std::cin>>n>>k;
  std::vector<int> snuke(n);
  for(int i=0;i<k;i++){
    int d;
    std::cin>>d;
    for(int i=0;i<d;i++){
      int a;
      std::cin>>a;
      snuke[a-1]++;
    }
  }
  int ans=0;
  for(int i=0;i<n;i++){
    if(snuke[i]==0){
      ans++;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}