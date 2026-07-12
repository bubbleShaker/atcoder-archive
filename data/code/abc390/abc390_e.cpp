#include <bits/stdc++.h>
using namespace std;

int main(){
  const int INF=2e9;
  const int MAX_X=5000;
  int n,x;
  cin>>n>>x;
  vector<int> V(n+1),A(n+1),C(n+1);
  for(int i=1;i<=n;i++){
    cin>>V[i]>>A[i]>>C[i];
  }
  vector<int> dp1(MAX_X+1,-INF),dp2(MAX_X+1,-INF),dp3(MAX_X+1,-INF);
  dp1[0]=0;
  dp2[0]=0;
  dp3[0]=0;
  for(int i=1;i<=n;i++){
    for(int j=MAX_X;j>=0;j--){
      if(V[i]==1){
        if(j-C[i]>=0)dp1[j]=max(dp1[j-C[i]]+A[i],dp1[j]);
      }
      if(V[i]==2){
        if(j-C[i]>=0)dp2[j]=max(dp2[j-C[i]]+A[i],dp2[j]);
      }
      if(V[i]==3){
        if(j-C[i]>=0)dp3[j]=max(dp3[j-C[i]]+A[i],dp3[j]);
      }
    }
  }
  for(int j=1;j<=MAX_X;j++){
    dp1[j]=max(dp1[j],dp1[j-1]);
    dp2[j]=max(dp2[j],dp2[j-1]);
    dp3[j]=max(dp3[j],dp3[j-1]);
  }
  int ans=0;
  for(int x1=0;x1<=MAX_X;x1++){
    for(int x2=0;x2<=MAX_X;x2++){
      int x3=x-x1-x2;
      if(x3>=0&&x1+x2+x3<=x)ans=max(ans,min({dp1[x1],dp2[x2],dp3[x3]}));
    }
  }
  cout<<ans<<endl;
  return 0;
}