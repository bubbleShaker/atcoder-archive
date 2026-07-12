#include <iostream>
#include <vector>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> p(n);
  for(int i=0;i<n;i++){
    std::cin>>p[i];
  }
  int ans=0;
  for(int i=1;i<n-1;i++){
    if(p[i-1]<=p[i]&&p[i]<=p[i+1]||p[i+1]<=p[i]&&p[i]<=p[i-1]){
      ans++;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}