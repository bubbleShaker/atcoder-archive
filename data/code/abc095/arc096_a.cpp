#include <iostream>
#include <algorithm>
int main(){
  const long long INF=1e18;
  long long a,b,c,x,y;
  std::cin>>a>>b>>c>>x>>y;
  long long ans=INF;
  //AピザとBピザだけで注文する
  ans=std::min(ans,a*x+b*y);
  //ABピザだけで注文する
  ans=std::min(ans,std::max(x,y)*2*c);
  if(x>y){//ABピザ+Aピザで注文する
    ans=std::min(ans,y*2*c+(x-y)*a);
  }else{//ABピザ+Bピザで注文する
    ans=std::min(ans,x*2*c+(y-x)*b);
  }
  std::cout<<ans<<'\n';
  return 0;
}