#include <iostream>
#include <vector>
int main(){
  const int MOD=10007;
  int n;
  std::cin>>n;
  std::vector<int> a(n+1);
  a[3]=1;
  for(int i=4;i<=n;i++){
    a[i]=a[i-1]+a[i-2]+a[i-3];
    a[i]%=MOD;
  }
  std::cout<<a[n]<<'\n';
  return 0;
}