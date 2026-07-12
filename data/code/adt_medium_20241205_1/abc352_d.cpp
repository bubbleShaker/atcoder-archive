#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  vector<int> p(n+1);
  vector<int> p_ind(n+1);
  for(int i=1;i<=n;i++) cin>>p[i],p_ind[p[i]]=i;
  set<int> st;
  for(int p=1;p<=k;p++){
    st.insert(p_ind[p]);
  }
  //最大値と最小値を取得
  int mi=*st.begin();
  int ma=*st.rbegin();
  int ans=ma-mi;
  for(int p=k+1;p<=n;p++){
    st.erase(p_ind[p-k]);
    st.insert(p_ind[p]);
    mi=*st.begin();
    ma=*st.rbegin();
    ans=min(ans,ma-mi);
  }
  cout<<ans<<endl;
  return 0;
}