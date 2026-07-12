#include <iostream>
#include <vector>
int main(){
  int n,k,q;
  std::cin>>n>>k>>q;
  std::vector<int> a(k);
  std::vector<bool> masu(n+1);
  for(int i=0;i<k;i++){
    std::cin>>a[i];
    masu[a[i]]=true;
  }
  while(q--){
    int l;
    std::cin>>l;
    l--;
    if(a[l]!=n&&masu[a[l]+1]==false){
      masu[a[l]]=false;
      a[l]++;
      masu[a[l]]=true;
    }
  }
  for(int i=0;i<k;i++){
    std::cout<<a[i]<<((i!=k-1)?' ':'\n');
  }
  return 0;
}