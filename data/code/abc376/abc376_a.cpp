#include <iostream>
#include <vector>
int main(){
  int n,c;
  std::cin>>n>>c;
  std::vector<int> t(n);
  for(int i=0;i<n;i++){
    std::cin>>t[i];
  }
  int ans=1;
  int now_t=t[0];
  for(int i=1;i<n;i++){
    if(t[i]-now_t<c){
      continue;
    }
    ans++;
    now_t=t[i];
  }
  std::cout<<ans<<'\n';
  return 0;
}