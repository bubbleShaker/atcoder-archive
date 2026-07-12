#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

bool is_ok(int n,std::vector<int> a,std::vector<int> b,int mid){
  b.push_back(mid);
  std::sort(b.begin(),b.end());
  for(int i=0;i<n;i++){
    if(b[i]<a[i]){
      return false;
    }
  }
  return true;
}

int main(){
  const int INF=1e9;
  int n;
  std::cin>>n;
  std::vector<int> a(n),b(n-1);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  for(int i=0;i<n-1;i++){
    std::cin>>b[i];
  }
  std::sort(a.begin(),a.end());
  int ok=INF;
  int ng=0;
  while(std::abs(ok-ng)>1){
    int mid=(ok+ng)/2;
    if(is_ok(n,a,b,mid)){
      ok=mid;
    }else{
      ng=mid;
    }
  }
  if(ok==INF&&is_ok(n,a,b,ok)==false){
    std::cout<<-1<<'\n';
  }else{
    std::cout<<ok<<'\n';
  }
  return 0;
}