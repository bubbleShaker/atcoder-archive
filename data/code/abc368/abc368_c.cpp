#include <iostream>
#include <vector>

long long calc_t(long long h){
  long long ret=0;
  ret+=(h/5)*3;
  if(h%5==1){
    ret++;
  }else if(h%5==2){
    ret+=2;
  }else if(3<=h%5&&h%5<=4){
    ret+=3;
  }
  return ret;
}

int main(){
  int n;
  std::cin>>n;
  std::vector<long long> h(n);
  for(int i=0;i<n;i++){
    std::cin>>h[i];
  }
  long long t=0;
  for(int i=0;i<n;i++){
    if(t%3==0){
      t+=calc_t(h[i]);
    }else if(t%3==1){
      if(h[i]==1){
        t++;
      }else if(h[i]<=4){
        t+=2;
      }else if(h[i]>4){
        h[i]-=4;
        t+=2;
        t+=calc_t(h[i]);
      }
    }else if(t%3==2){
      if(h[i]<=3){
        t++;
      }else if(h[i]>3){
        t++;
        h[i]-=3;
        t+=calc_t(h[i]);
      }
    }
  }
  std::cout<<t<<'\n';
  return 0;
}