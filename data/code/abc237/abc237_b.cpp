#include <iostream>
#include <vector>
int main(){
  int h,w;
  std::cin>>h>>w;
  std::vector<std::vector<int>> a(h,std::vector<int>(w));
  std::vector<std::vector<int>> b(w,std::vector<int>(h));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      std::cin>>a[i][j];
      b[j][i]=a[i][j];
    }
  }
  for(int i=0;i<w;i++){
    for(int j=0;j<h;j++){
      std::cout<<b[i][j]<<((j!=h-1)?' ':'\n');
    }
  }
  return 0;
}