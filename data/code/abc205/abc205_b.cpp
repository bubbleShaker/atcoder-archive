#include <iostream>
#include <vector>
#include <algorithm>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> a(n),per(n);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
    per[i]=i+1;
  }
  std::cout<<((std::is_permutation(a.begin(),a.end(),per.begin()))?"Yes":"No")<<'\n';
  return 0;
}