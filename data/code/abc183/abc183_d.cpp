#include <iostream>
#include <vector>
int main(){
  int n,w;
  std::cin>>n>>w;
  std::vector<long long> imos((int)2e6+10);
  for(int i=0;i<n;i++){
    long long l,r,p;
    std::cin>>l>>r>>p;
    imos[l]+=p;
    imos[r]-=p;
  }
  for(int i=1;i<=(int)2e5;i++){
    imos[i]+=imos[i-1];
  }
  for(int i=0;i<=(int)2e5;i++){
    if(imos[i]>w){
      std::cout<<"No"<<'\n';
      return 0;
    }
  }
  std::cout<<"Yes"<<'\n';
  return 0;
}