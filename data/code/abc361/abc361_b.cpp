#include <iostream>
#include <utility>
int main(){
  int a,b,c,d,e,f,g,h,i,j,k,l;
  std::cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l;
  if(g<a){
    std::swap(a,g);
    std::swap(d,j);
  }
  if(h<b){
    std::swap(b,h);
    std::swap(e,k);
  }
  if(i<c){
    std::swap(c,i);
    std::swap(f,l);
  }
  if((a<g&&g<d||a<j&&j<d)&&(b<h&&h<e||b<k&&k<e)&&(c<i&&i<f||c<l&&l<f)){
    std::cout<<"Yes"<<'\n';
  }else{
    std::cout<<"No"<<'\n';
  }
  return 0;
}