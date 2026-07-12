#include <bits/stdc++.h>
using namespace std;

int win(char c){
  if(c=='R') return 2;
  if(c=='S') return 0;
  if(c=='P') return 1;
}

int aiko(char c){
  if(c=='R') return 0;
  if(c=='S') return 1;
  if(c=='P') return 2;
}

int lose(char c){
  if(c=='R') return 1;
  if(c=='S') return 2;
  if(c=='P') return 0;
}

int main(){
  int n;
  string s;
  cin>>n>>s;
  vector dp(3,vector<int>(n)); //dp[0][i]:'R',dp[1][i]:'S',dp[2][i]:'P'
  dp[win(s[0])][0]=1;
  for(int i=1;i<n;i++){
    for(int han=0;han<=2;han++){
      if(han==win(s[i])){
        for(int pre=0;pre<=2;pre++){
          if(han==pre)continue;
          dp[han][i]=max(dp[han][i],dp[pre][i-1]+1);
        }
      }
      if(han==aiko(s[i])){
        for(int pre=0;pre<=2;pre++){
          if(han==pre)continue;
          dp[han][i]=max(dp[han][i],dp[pre][i-1]);
        }
      }
      if(han==lose(s[i])){
        dp[han][i]=-1e9;
      }
    }
  }
  cout<<max({dp[0][n-1],dp[1][n-1],dp[2][n-1]})<<endl;
  return 0;
}