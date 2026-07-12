#include <bits/stdc++.h>
using namespace std;

int powi(int a,int b){
  int ret=1;
  for(int i=0;i<b;i++){
    ret*=a;
  }
  return ret;
}

int solve(int a,int b,int c){
  map<int,int> mp;
  mp[a]++;
  mp[b]++;
  mp[c]++;
  if(mp[0]>mp[1])return 0;
  else return 1;
}

int main(){
  int n;
  cin>>n;
  int A[powi(3,n)+10];
  for(int i=1;i<=powi(3,n);i++){
    char c;
    cin>>c;
    A[i]=c-'0';
  }
  int a[n+10][powi(3,n)+10];
  for(int i=1;i<=powi(3,n);i++){
    a[0][i]=A[i];
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=powi(3,n-i);j++){
      a[i][j]=solve(a[i-1][3*j-2],a[i-1][3*j-1],a[i-1][3*j]);
    }
  }
  int dp[n+10][powi(3,n)+10];
  for(int j=1;j<=powi(3,n);j++){
    dp[0][j]=1;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=powi(3,n-i);j++){
      if(a[i-1][3*j-2]==a[i-1][3*j-1]&&a[i-1][3*j-1]==a[i-1][3*j]){
        vector<int> koho;
        koho.push_back(dp[i-1][3*j-2]);
        koho.push_back(dp[i-1][3*j-1]);
        koho.push_back(dp[i-1][3*j]);
        sort(koho.begin(),koho.end());
        dp[i][j]=koho[0]+koho[1];
      }else{
        vector<int> koho;
        for(int k=3*j-2;k<=3*j;k++){
          if(a[i][j]==a[i-1][k]){
            koho.push_back(dp[i-1][k]);
            sort(koho.begin(),koho.end());
            dp[i][j]=koho[0];
          }
        }
      }
    }
  }
  cout<<dp[n][1]<<endl;
  return 0;
}