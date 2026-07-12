#include <iostream>
#include <vector>
int main(){
  int n,x;
  std::cin>>n>>x;
  std::vector<int> a;
  for(int i=0;i<n;i++){
    int val;
    std::cin>>val;
    if(val!=x){
      a.push_back(val);
    }
  }
  for(int i=0;i<a.size();i++){
    std::cout<<a[i]<<((i!=a.size()-1)?' ':'\n');
  }
  return 0;
}