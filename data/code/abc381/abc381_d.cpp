#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int l=-1;
  int r=-1;
  int ans=0;
  set<int> st;
  while(l<n&&r<n){
    r+=2;
    if(r>=n){
      break;
    }
    if(a[r-1]==a[r]){//条件2を満たしているか
      if(st.count(a[r])==false){//条件3を満たしているか
        st.insert(a[r]);
      }else{//条件3を満たしていないならば
        l+=2;
        while(a[l]!=a[r]){
          st.erase(a[l]);
          l+=2;
        }
      }
    }else{//条件2を満たしていないならば
      while(l!=r){//数字の集合の管理
        l+=2;
        if(st.count(a[l])){//区間が部分列の条件を満たしているならば削除
          st.erase(a[l]);
        }
      }
      //場所の初期化
      l--;
      r--;
      if(r-1>=0&&r>=0){
        if(a[r-1]==a[r]){
          l-=2;
          r-=2;
        }
      }
    }
    ans=max(ans,r-l);
    // cout<<"ans:"<<ans<<", (l,r):"<<l<<","<<r<<endl;
  }
  cout<<ans<<endl;
  return 0;
}