#include <iostream>
#include <vector>
#include <algorithm>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> a(n+1),b(n);
  for(int i=0;i<n+1;i++){
    std::cin>>a[i];
  }
  for(int i=0;i<n;i++){
    std::cin>>b[i];
  }
  long long ans=0;
  for(int i=0;i<n;i++){
    int val1=std::min(a[i],b[i]);
    a[i]-=val1;
    ans+=(long long)val1;
    b[i]-=val1;
    int val2=std::min(a[i+1],b[i]);
    a[i+1]-=val2;
    ans+=(long long)val2;
    b[i]-=val2;
  }
  std::cout<<ans<<'\n';
  return 0;
}