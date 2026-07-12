#include <iostream>
#include <vector>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> a(n),b(n);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  int sum=0;
  for(int i=0;i<n;i++){
    std::cin>>b[i];
    sum+=a[i]*b[i];
  }
  std::cout<<((sum==0)?"Yes":"No")<<'\n';
  return 0;
}