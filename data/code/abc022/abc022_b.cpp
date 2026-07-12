#include <iostream>
#include <vector>
#include <map>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> a(n);
  std::map<int,int> map;
  int ans=0;
  for(int i=0;i<n;i++){
    std::cin>>a[i];
    map[a[i]]++;
    if(map[a[i]]>=2){
      ans++;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}