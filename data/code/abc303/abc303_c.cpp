#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

int main(void){
    int N, M, H, K;
    cin >> N >> M >> H >> K;
    string S;
    cin >> S;
    
    map<int, vector<int>> item;
    for(int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        item[x].push_back(y);
        sort(item[x].begin(), item[x].end());
    }
    
    int x = 0;
    int y = 0;
    
    for(int i = 0; i < N; i++){
        if(S[i] == 'R'){
            x = x + 1;
        }else if(S[i] == 'L'){
            x = x - 1;
        }else if(S[i] == 'U'){
            y = y + 1;
        }else{
            y = y - 1;
        }
        H--;
        if(H < 0){
            cout << "No" << endl;
            return 0;
        }
        
        int ind = lower_bound(item[x].begin(), item[x].end(), y) - item[x].begin();
        
        if(ind != item[x].size()){
            if(item[x][ind] == y){
                if(H < K){
                    H = K;
                    item[x].erase(remove(item[x].begin(), item[x].end(), y), item[x].end());
                }
            }
        }
    }
    
    cout << "Yes" << endl;
    
    return 0;
}