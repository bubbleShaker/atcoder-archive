#include <iostream>
#include <string>
#include <vector>
int main(){
  const std::vector<int> dx={-1,0,1,0};
  const std::vector<int> dy={0,1,0,-1};
  int h,w,si,sj;
  std::cin>>h>>w>>si>>sj;
  si--;sj--;
  std::vector<std::string> c(h);
  for(int i=0;i<h;i++){
    std::cin>>c[i];
  }
  std::string x;
  std::cin>>x;
  int xx=si,yy=sj;
  for(int i=0;i<x.size();i++){
    int val;
    if(x[i]=='U'){
      val=0;
    }else if(x[i]=='R'){
      val=1;
    }else if(x[i]=='D'){
      val=2;
    }else{
      val=3;
    }
    int nx=xx+dx[val];
    int ny=yy+dy[val];
    if(nx<0||nx>=h||ny<0||ny>=w||c[nx][ny]=='#'){
      continue;
    }
    xx=nx;
    yy=ny;
  }
  std::cout<<xx+1<<" "<<yy+1<<'\n';
  return 0;
}