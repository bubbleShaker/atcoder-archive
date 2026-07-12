#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
int main(){
  int n;
  std::cin>>n;
  std::multiset<double> set;
  for(int i=0;i<n;i++){
    double v;
    std::cin>>v;
    set.insert(v);
  }
  while(set.size()>1){
    double v1=*set.begin();
    double v2=*(++set.begin());
    set.erase(set.find(v1));
    set.erase(set.find(v2));
    set.insert((v1+v2)/2);
  }
  std::cout<<std::fixed<<std::setprecision(10);
  std::cout<<*set.begin()<<'\n';
  return 0;
}