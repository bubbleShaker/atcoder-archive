#include <iostream>
#include <vector>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> a(n),b(n);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  for(int i=0;i<n;i++){
    std::cin>>b[i];
  }
  int ans_1=0,ans_2=0;
  for(int i=0;i<n;i++){
    if(a[i]==b[i]){
      ans_1++;
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i!=j&&a[i]==b[j]){
        ans_2++;
      }
    }
  }
  std::cout<<ans_1<<'\n';
  std::cout<<ans_2<<'\n';
  return 0;
}