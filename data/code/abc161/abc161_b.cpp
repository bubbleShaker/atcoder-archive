#include <iostream>
#include <vector>
int main(){
  int n;
  double m;
  std::cin>>n>>m;
  std::vector<double> a(n);
  double sum=0;
  for(int i=0;i<n;i++){
    std::cin>>a[i];
    sum+=a[i];
  }
  double cnt=0;
  double rate=sum/(4*m);
  for(int i=0;i<n;i++){
    if(a[i]>=rate){
      cnt++;
    }
  }
  if(cnt>=m){
    std::cout<<"Yes"<<'\n';
  }else{
    std::cout<<"No"<<'\n';
  }
  return 0;
}