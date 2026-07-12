#include <bits/stdc++.h>
using namespace std;

int main(){
  int h1,h2,h3,w1,w2,w3;
  cin>>h1>>h2>>h3>>w1>>w2>>w3;
  int ans=0;
  for(int a_00=1;a_00<=h1;a_00++){
    for(int a_01=1;a_01<=h1;a_01++){
      for(int a_10=1;a_10<=h2;a_10++){
        for(int a_11=1;a_11<=h2;a_11++){
          int a_02=h1-(a_00+a_01);
          int a_12=h2-(a_10+a_11);
          int a_20=w1-(a_00+a_10);
          int a_21=w2-(a_01+a_11);
          int a_22=w3-(a_02+a_12);
          if(a_20+a_21+a_22!=h3) continue;
          if(a_02>0&&a_12>0&&a_20>0&&a_21>0&&a_22>0){
            ans++;
          }
        }
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}