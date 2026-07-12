#include <iostream>
#include <vector>
int main(){
  int n,x;
  std::cin>>n>>x;
  std::vector<int> a(n+1);
  for(int i=1;i<=n;i++){
    std::cin>>a[i];
  }
  std::vector<bool> is_checked(n+1);
  int ans=0;
  int now=x;
  while(!is_checked[now]){
    ans++;
    is_checked[now]=true;
    now=a[now];
  }
  std::cout<<ans<<'\n';
  return 0;
}