#include <bits/stdc++.h>
using namespace std;

int main(){
  int q;
  cin>>q;
  vector<long long> height(q+1);
  height[0]=0;
  queue<int> que;
  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==1){
      height[i+1]=height[i];
      que.push(i);
    }
    if(t==2){
      long long add;
      cin>>add;
      height[i+1]=height[i]+add;
    }
    if(t==3){
      height[i+1]=height[i];
      long long h;
      cin>>h;
      int ans=0;
      while(!que.empty()){
        if(height[i+1]-height[que.front()]>=h){
          ans++;
          que.pop();
        }else{
          break;
        }
      }
      cout<<ans<<endl;
    }
  }
}