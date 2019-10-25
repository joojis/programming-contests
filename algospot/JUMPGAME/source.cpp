#include <iostream>

using namespace std;

void solve() {
    int n; 
    int board[110][110] = {0, };
    int answer[110][110] = {0, };

    cin >> n;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> board[i][j];
        }
    }

    answer[0][0] = 1;
    for (int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int jump = board[i][j];
            answer[i + jump][j] += answer[i][j];
            answer[i][j + jump] += answer[i][j];
        }
    }

    cout << (answer[n-1][n-1] ? "YES" : "NO") << endl;
}

int main() {
    int c;

    cin >> c;

    while (c--) {
        solve();
    }
    
    return 0;
}