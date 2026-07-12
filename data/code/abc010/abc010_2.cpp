#include <iostream>
#include <vector>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> a(n);
  int ans=0;
  for(int i=0;i<n;i++){
    std::cin>>a[i];
    while(1){
      if(a[i]==1||a[i]==3||a[i]==7||a[i]==9){
        break;
      }
      a[i]--;
      ans++;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}