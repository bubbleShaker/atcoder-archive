#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(7 * N);
    
    for (int i = 0; i < 7 * N; ++i) {
        cin >> A[i];
    }
    
    for (int i = 0; i < N; ++i) {
        int sum = 0;
        for (int j = 0; j < 7; ++j) {
            sum += A[i * 7 + j];
        }
        cout << sum;
        if (i < N - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
