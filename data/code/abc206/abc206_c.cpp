#include <iostream>
#include <map>
int main(){
  int n;
  std::cin>>n;
  std::map<int,int> map;
  long long ans=0;
  for(int i=0;i<n;i++){
    int a;
    std::cin>>a;
    if(i==0){
      map[a]++;
    }else{
      ans+=(long long)(i-map[a]);
      map[a]++;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}