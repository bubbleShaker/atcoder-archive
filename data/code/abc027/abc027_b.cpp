#include <iostream>
#include <vector>
#include <numeric>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> a(n);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  int sum=std::accumulate(a.begin(),a.end(),0);//intなら0,long longなら0LLにすることに注意
  if(sum%n){
    std::cout<<-1<<'\n';
    return 0;
  }
  int ave=sum/n;
  int now_sum=0,now_cnt=0,now_bridge=0;
  int ans=0;
  for(int i=0;i<n;i++){
    now_sum+=a[i];
    now_cnt++;
    if(now_sum%now_cnt==0&&now_sum/now_cnt==ave){
      ans+=now_bridge;
      now_sum=0;
      now_cnt=0;
      now_bridge=0;
    }else{
      now_bridge++;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}