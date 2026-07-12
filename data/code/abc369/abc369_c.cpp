#include <iostream>
#include <vector>
int main(){
  long long n;
  std::cin>>n;
  std::vector<int> a(n);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  long long ans=2*n-1; //初期解
  int prev_d;
  long long len=0;
  for(int i=0;i<n-1;i++){
    if(i==0){
      prev_d=a[i+1]-a[i];
      len=2;
    }else{
      if(a[i+1]-a[i]==prev_d){
        len++;
      }else{
        if(len>=3){
          len-=2;
          ans+=(len*(len+1))/2;
        }
        prev_d=a[i+1]-a[i];
        len=2;
      }
    }
  }
  if(len>=3){
    len-=2;
    ans+=(len*(len+1))/2;
  }
  std::cout<<ans<<'\n';
  return 0;
}