#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N, Q;
    cin >> N >> Q;
    
    vector<vector<int>> box(N+1);
    vector<set<int>> card(200010);
    
    for(int i = 0; i < Q; i++){
        int n;
        cin >> n;
        if(n == 1){
            int i, j;
            cin >> i >> j;
            box[j].push_back(i);
            card[i].insert(j);
        }else if(n == 2){
            int i;
            cin >> i;
            sort(box[i].begin(), box[i].end());
            for(int j = 0; j < box[i].size(); j++){
                cout << box[i][j];
                if(j != box[i].size() - 1) cout << " ";
                else cout << endl;
            }
        }else{
            int i;
            cin >> i;
            int c = 0;
            for(int t : card[i]){
                c++;
                cout << t;
                if(c != card[i].size()){
                    cout << " ";
                }else cout << endl;
            }
        }
    }
    
    return 0;
}