#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> a(5);
  for(int i=0;i<4;i++){
    int num;
    cin>>num;
    a[num]++;
  }
  int ans=0;
  for(int i=1;i<=4;i++){
    if(a[i]>=2){
      while(a[i]>=2){
        a[i]-=2;
        ans++;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}