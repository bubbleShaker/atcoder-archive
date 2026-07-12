#include <iostream>
int main(){
  int n;
  std::cin>>n;
  for(int i=n;;i++){
    int ret=i;
    int a=ret%10;
    ret/=10;
    int b=ret%10;
    ret/=10;
    int c=ret%10;
    if(a==b&&b==c){
      std::cout<<i<<'\n';
      return 0;
    }
  }
  return 0;
}