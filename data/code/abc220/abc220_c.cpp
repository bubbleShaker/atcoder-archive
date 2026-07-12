#include <iostream>
#include <numeric>
#include <vector>
int main(){
  int n;
  std::cin>>n;
  std::vector<long long> a(n);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  long long x;
  std::cin>>x;
  long long sum=std::accumulate(a.begin(),a.end(),0LL);
  long long q=x/sum;
  x=x%sum;
  long long now_sum=0;
  for(long long i=0;i<n;i++){
    now_sum+=a[i];
    if(now_sum>x){
      std::cout<<q*n+i+1<<'\n';
      return 0;
    }
  }
  return 0;
}