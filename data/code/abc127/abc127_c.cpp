#include <iostream>
#include <vector>
int main(){
  int n,m;
  std::cin>>n>>m;
  std::vector<int> id(n+2);
  for(int i=0;i<m;i++){
    int l,r;
    std::cin>>l>>r;
    id[l]++;
    id[r+1]--;
  }
  for(int i=1;i<=n;i++){
    id[i]+=id[i-1];
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    if(id[i]==m){
      ans++;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}