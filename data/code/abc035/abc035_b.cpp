#include <iostream>
#include <vector>
#include <string>
#include <cmath>
int main(){
  const std::vector<int> dx={-1,0,1,0};
  const std::vector<int> dy={0,1,0,-1};
  std::string s;
  int t;
  std::cin>>s>>t;
  int x=0,y=0;
  int hatena_cnt=0;
  for(int i=0;i<s.size();i++){
    int val;
    if(s[i]=='L'){
      val=0;
    }else if(s[i]=='R'){
      val=2;
    }else if(s[i]=='U'){
      val=1;
    }else if(s[i]=='D'){
      val=3;
    }else{
      hatena_cnt++;
      continue;
    }
    x+=dx[val];
    y+=dy[val];
  }
  int dist=std::abs(x)+std::abs(y);
  if(t==1){
    std::cout<<dist+hatena_cnt<<'\n';
  }else if(t==2){
    if(hatena_cnt<=dist){
      std::cout<<dist-hatena_cnt<<'\n';
    }else{
      if(hatena_cnt%2==dist%2){
        std::cout<<0<<'\n';
      }else{
        std::cout<<1<<'\n';
      }
    }
  }
  return 0;
}