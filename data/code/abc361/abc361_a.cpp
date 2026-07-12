#include <iostream>
#include <vector>
int main(){
  int n,k,x;
  std::cin>>n>>k>>x;
  std::vector<int> b;
  for(int i=1;i<=n;i++){
    int a;
    std::cin>>a;
    b.push_back(a);
    if(i==k){
      b.push_back(x);
    }
  }
  for(int i=0;i<b.size();i++){
    std::cout<<b[i]<<((i!=b.size()-1)?' ':'\n');
  }
  return 0;
}