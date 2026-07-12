#include <stdio.h>
#include <string.h>

int main(){
  char str[10];
  char p[10];
  char q[10];
  fgets(str, sizeof(str), stdin);
  char* token = strtok(str, " \n");
  strcpy(p, token);
  token = strtok(NULL, " \n");
  strcpy(q, token);
  
  int p_n;
  int p_v;
  int q_n;
  int q_v;
  
  if(strcmp(p, "A") == 0){
    p_n = 0;
    p_v = 0;
  }else if(strcmp(p, "B") == 0){
    p_n = 1;
    p_v = 3;
  }else if(strcmp(p, "C") == 0){
    p_n = 2;
    p_v = 4;
  }else if(strcmp(p, "D") == 0){
    p_n = 3;
    p_v = 8;
  }else if(strcmp(p, "E") == 0){
    p_n = 4;
    p_v = 9;
  }else if(strcmp(p, "F") == 0){
    p_n = 5;
    p_v = 14;
  }else{
    p_n = 6;
    p_v = 23;
  }
  
  if(strcmp(q, "A") == 0){
    q_n = 0;
    q_v = 0;
  }else if(strcmp(q, "B") == 0){
    q_n = 1;
    q_v = 3;
  }else if(strcmp(q, "C") == 0){
    q_n = 2;
    q_v = 4;
  }else if(strcmp(q, "D") == 0){
    q_n = 3;
    q_v = 8;
  }else if(strcmp(q, "E") == 0){
    q_n = 4;
    q_v = 9;
  }else if(strcmp(q, "F") == 0){
    q_n = 5;
    q_v = 14;
  }else{
    q_n = 6;
    q_v = 23;
  }
  
  int ans;
  
  if(p_n < q_n){
    ans = q_v - p_v;
  }else{
    ans = p_v - q_v;
  }
  printf("%d", ans);
  
  return 0;
}