#include <iostream>
#include <vector>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> a(n);
  int bosu=0,cnt=0;
  for(int i=0;i<n;i++){
    std::cin>>a[i];
    bosu+=((a[i]!=0)?1:0);
    cnt+=a[i];
  }
  auto ceili=[&](int a,int b){
    return (a+(b-1))/b;
  };
  std::cout<<ceili(cnt,bosu)<<'\n';
  return 0;
}