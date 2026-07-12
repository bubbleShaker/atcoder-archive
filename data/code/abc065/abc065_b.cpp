#include <iostream>
#include <vector>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> a(n+1);
  for(int i=1;i<=n;i++){
    std::cin>>a[i];
  }
  std::vector<bool> is_visited(n+1);
  int now_botton=1;
  int now_cnt=0;
  while(1){
    if(is_visited[now_botton]){
      std::cout<<-1<<'\n';
      return 0;
    }
    is_visited[now_botton]=true;
    now_cnt++;
    now_botton=a[now_botton];
    if(now_botton==2){
      std::cout<<now_cnt<<'\n';
      return 0;
    }
  }
  return 0;
}