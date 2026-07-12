#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  double now_x=0,now_y=0;
  double ans=0;
  for(int i=0;i<n;i++){
    double x,y;
    cin>>x>>y;
    ans+=sqrt((now_x-x)*(now_x-x)+(now_y-y)*(now_y-y));
    now_x=x;
    now_y=y;
  }
  ans+=sqrt(now_x*now_x+now_y*now_y);
  cout<<fixed<<setprecision(10);
  cout<<ans<<endl;
  return 0;
}