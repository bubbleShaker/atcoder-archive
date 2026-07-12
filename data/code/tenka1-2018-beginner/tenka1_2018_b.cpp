#include <iostream>
int main(){
  long long a,b,k;
  std::cin>>a>>b>>k;
  for(int i=0;i<k;i++){
    if(i%2==0){//高橋君
      if(a%2){
        a--;
      }
      a/=2;
      b+=a;
    }else{//青木君
      if(b%2){
        b--;
      }
      b/=2;
      a+=b;
    }
  }
  std::cout<<a<<" "<<b<<'\n';
  return 0;
}