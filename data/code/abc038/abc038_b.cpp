#include <iostream>
#include <set>
int main(){
  int h1,w1,h2,w2;
  std::cin>>h1>>w1>>h2>>w2;
  std::set<int> set1,set2;
  set1.insert(h1);
  set1.insert(w1);
  set2.insert(h2);
  set2.insert(w2);
  if(set2.count(h1)||set2.count(w1)){
    std::cout<<"YES"<<'\n';
  }else{
    std::cout<<"NO"<<'\n';
  }
  return 0;
}