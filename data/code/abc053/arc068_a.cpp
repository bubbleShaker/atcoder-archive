#include <iostream>
int main(){
  long long x;
  std::cin>>x;
  long long base=x/11LL;
  long long amari=x%11LL;
  base*=2;
  if(1<=amari&&amari<=6){
    base++;
  }else if(6<amari){
    base+=2;
  }
  std::cout<<base<<'\n';
  return 0;
}