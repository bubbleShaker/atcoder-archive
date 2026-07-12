#include <iostream>
#include <vector>
int main(){
  const long long INF=4e18;
  long long d;
  std::cin>>d;
  std::vector<long long> vec;
  for(long long i=0;i<=(int)1e7;i++){
    vec.push_back(i*i);
  }
  long long ans=INF;
  for(long long i=0;i<(int)1e7;i++){
    long long x=vec[i];
    long long y1_idx=std::lower_bound(vec.begin(),vec.end(),d-x)-vec.begin();
    long long y2_idx;
    if(y1_idx==0){
      y2_idx=y1_idx;
    }else{
      y2_idx=y1_idx-1;
    }
    long long y1=vec[y1_idx];
    long long y2=vec[y2_idx];
    ans=std::min(ans,std::abs(x+y1-d));
    ans=std::min(ans,std::abs(x+y2-d));
  }
  std::cout<<ans<<'\n';
  return 0;
}