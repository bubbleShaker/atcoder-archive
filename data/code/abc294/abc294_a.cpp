#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N;
    cin >> N;
    vector<int> ans;
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        if(!(tmp%2)){
            ans.push_back(tmp);
        }
    }
    
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " \n"[i+1 == ans.size()];
    }
    return 0;
}