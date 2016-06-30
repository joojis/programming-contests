#include <bits/stdc++.h>

using namespace std;

typedef long long int LLI;
typedef vector<LLI> VLLI;

const LLI Z = 1000000009;

void solveCase()
{
    int N, K, L;
    cin >> N >> K >> L;

    vector<bool> trap = vector<bool>(N+1, false);
    for (int i=0; i<L; i++) {
        int l;
        cin >> l;
        trap[l] = true;
    }

    vector<LLI> sum = VLLI(N+1, 0);
    sum[0] = 1;
    vector<VLLI> cases = vector<VLLI>(N+1);
    for (int i=0; i<=N; i++) {
        cases[i] = VLLI(K+1, 0);
    }

    for (int n=1; n<=N; n++) {
        if (trap[n]) continue;
        for (int k=1; k<=K; k++) {
            if (n - k < 0) break;
            // assert(n-k >= 0);
            cases[n][k] = (sum[n-k] + Z - cases[n-k][k]) % Z;
            sum[n] += cases[n][k];
        }
        sum[n] %= Z;
    }
    cout << sum[N] << endl;
}

int main()
{
    int T;

    cin >> T;
    for (int t=1; t<=T; t++) {
        cout << "Case #" << t << endl;
        solveCase();
    }

    return 0;
}
