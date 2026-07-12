#include <iostream>
int main(){
  const int INF=1e9;
  long long a,b,c,d;
  std::cin>>a>>b>>c>>d;
  long long cyan=a;
  long long red=0;
  int ans=0;
  do{
    if(ans==INF){
      break;
    }
    cyan+=b;
    red+=c;
    ans++;
  }while(cyan>red*d);
  std::cout<<((ans!=INF)?ans:-1)<<'\n';
  return 0;
}