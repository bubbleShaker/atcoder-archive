#include <iostream>
#include <set>
int main(){
  int n;
  std::cin>>n;
  std::set<int> set;
  int add=0;
  for(int i=0;i<n;i++){
    int a;
    std::cin>>a;
    a/=400;
    if(a<=7){
      set.insert(a);
    }else{
      add++;
    }
  }
  std::cout<<((set.size()==0&&add>0)?1:(int)set.size())<<" "<<(int)set.size()+add<<'\n';
  return 0;
}