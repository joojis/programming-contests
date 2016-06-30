#include <bits/stdc++.h>

using namespace std;

typedef long long unsigned LLU;

const LLU MAX = 0xFFFFFFFFFFFFFFFF;

LLU find_min(LLU num, int step)
{
    if (step == 0) {
        return num == 1 ? MAX : num;
    }

    LLU answer = MAX;
    if (((num-1)&num) > 0) { // power of 2
        answer = min(answer, find_min(num * 2, step - 1));
    }
    if ((num-1)%3 == 0 && (((num-1)/3)&1) == 1) {
        answer = min(answer, find_min((num-1)/3, step - 1));
    }
    return answer;
}

void solveCase()
{
    LLU K, small, large;

    cin >> K;
    small = large = ((LLU)1 << K);
    for (int k=1; k<K; k++) {
        small = min(small, find_min(large >> k, k));
    }

    cout << small << " " << large << endl;
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
