#include <iostream>
#include <vector>
#include <map>
int main(){
  int n,m;
  std::cin>>n>>m;
  std::vector<int> a(n),b(m);
  std::map<int,int> mp;
  for(int i=0;i<n;i++){
    std::cin>>a[i];
    mp[a[i]]++;
  }
  for(int i=0;i<m;i++){
    std::cin>>b[i];
    if(--mp[b[i]]<0){
      std::cout<<"No"<<'\n';
      return 0;
    }
  }
  std::cout<<"Yes"<<'\n';
  return 0;
}