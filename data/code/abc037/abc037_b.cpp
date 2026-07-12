#include <iostream>
#include <vector>
int main(){
  int n,q;
  std::cin>>n>>q;
  std::vector<int> a(n);
  for(int i=0;i<q;i++){
    int l,r,t;
    std::cin>>l>>r>>t;
    l--;r--;
    for(int j=l;j<=r;j++){
      a[j]=t;
    }
  }
  for(int i=0;i<n;i++){
    std::cout<<a[i]<<'\n';
  }
  return 0;
}