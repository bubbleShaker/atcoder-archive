#include <iostream>
int main(){
  int k;
  long long a,b;
  std::cin>>k>>a>>b;
  long long aa=0,bb=0;
  long long val=1;
  while(a>0){
    aa+=val*(a%10);
    a/=10;
    val*=k;
  }
  val=1;
  while(b>0){
    bb+=val*(b%10);
    b/=10;
    val*=k;
  }
  std::cout<<aa*bb<<'\n';
  return 0;
}