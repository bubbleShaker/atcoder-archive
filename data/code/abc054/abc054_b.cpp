#include <iostream>
#include <string>
#include <vector>
int main(){
  int n,m;
  std::cin>>n>>m;
  std::vector<std::string> a(n),b(m);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  for(int i=0;i<m;i++){
    std::cin>>b[i];
  }
  for(int si=0;si<=n-m;si++){
    for(int sj=0;sj<=n-m;sj++){
      bool is_same=true;
      for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
          if(a[si+i][sj+j]!=b[i][j]){
            is_same=false;
          }
        }
      }
      if(is_same){
        std::cout<<"Yes"<<'\n';
        return 0;
      }
    }
  }
  std::cout<<"No"<<'\n';
  return 0;
}