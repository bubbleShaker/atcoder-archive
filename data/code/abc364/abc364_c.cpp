#include <iostream>
#include <algorithm>
#include <vector>
int main(){
  int n;
  long long x,y;
  std::cin>>n>>x>>y;
  std::vector<long long> a(n),b(n);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  for(int i=0;i<n;i++){
    std::cin>>b[i];
  }
  std::sort(a.rbegin(),a.rend());
  std::sort(b.rbegin(),b.rend());
  int cnt_a=0,cnt_b=0;
  long long sum_a=0,sum_b=0;
  for(int i=0;i<n;i++){
    sum_a+=a[i];
    cnt_a++;
    if(sum_a>x){
      break;
    }
  }
  for(int i=0;i<n;i++){
    sum_b+=b[i];
    cnt_b++;
    if(sum_b>y){
      break;
    }
  }
  std::cout<<std::min(cnt_a,cnt_b)<<'\n';
  return 0;
}