#include <bits/stdc++.h>
using namespace std;
const int INF=2e9;

int main(){
  int N;
  cin>>N;
  vector<int> X(N+1,-INF);
  vector<long long> P(N+1);
  for(int i=1;i<=N;i++) cin>>X[i];
  for(int i=1;i<=N;i++) cin>>P[i];
  vector<long long> rsw(N+1,0);
  for(int i=1;i<=N;i++) rsw[i]=rsw[i-1]+P[i];
  int Q;
  cin>>Q;
  while(Q--){
    int L,R;
    cin>>L>>R;
    int L_ind=lower_bound(X.begin(),X.end(),L)-X.begin();
    int R_ind=lower_bound(X.begin(),X.end(),R)-X.begin();
    if(R_ind==N+1) R_ind--;
    else if(X[R_ind]!=R&&R_ind!=0) R_ind--;
    if(L_ind!=0) L_ind--;
    cout<<rsw[R_ind]-rsw[L_ind]<<endl;
  }
  return 0;
}