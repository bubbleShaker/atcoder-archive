#include <iostream>
int main(){
  int n,x;
  std::cin>>n>>x;
  int sum=0;
  for(int i=1;i<=n;i++){
    int a;
    std::cin>>a;
    sum+=((i%2)?a:a-1);
  }
  std::cout<<((sum<=x)?"Yes":"No")<<'\n';
  return 0;
}