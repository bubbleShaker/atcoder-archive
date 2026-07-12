#include <iostream>
#include <string>
#include <vector>
int main(){
  int h,w,x,y;
  std::cin>>h>>w>>x>>y;
  std::vector<std::string> s(h);
  for(int i=0;i<h;i++){
    std::cin>>s[i];
  }
  int now_x=--x,now_y=--y;
  int ans=0;
  while(now_x>=0&&s[now_x][y]!='#'){
    ans++;
    now_x--;
  }
  now_x=x;
  while(now_x<h&&s[now_x][y]!='#'){
    ans++;
    now_x++;
  }
  while(now_y>=0&&s[x][now_y]!='#'){
    ans++;
    now_y--;
  }
  now_y=y;
  while(now_y<w&&s[x][now_y]!='#'){
    ans++;
    now_y++;
  }
  ans-=3;
  std::cout<<ans<<'\n';
  return 0;
}