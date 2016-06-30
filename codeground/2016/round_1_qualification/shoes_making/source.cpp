#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <functional>

using namespace std;

#define mp make_pair

typedef pair<int, int> pii;
typedef priority_queue<pii> pq_pii;

void solveCase()
{
	int N, K;
	cin >> N >> K;

	int A[200], F[200], P[200];
	int S[100], E[100];

	priority_queue<pii, vector<pii>, greater<pii>> worker_s, worker_e, job_s, job_critical;

	for (int i = 0; i < N; i++) {
		cin >> A[i] >> F[i] >> P[i];
		job_s.push(mp(A[i], i));
	}
	for (int i = 0; i < K; i++) {
		cin >> S[i] >> E[i];
		worker_s.push(mp(S[i], i));
		worker_e.push(mp(E[i], i));
	}

	int workerCount = 0;
	for (int t = 0; t <= 100; t++) {
		if (job_s.empty() && job_critical.empty()) {
			cout << "1" << endl;
			return;
		}

		while (!worker_s.empty() && worker_s.top().first == t) {
			workerCount++;
			worker_s.pop();
		}
		while (!worker_e.empty() && worker_e.top().first == t) {
			workerCount--;
			worker_e.pop();
		}

		while (!job_s.empty() && job_s.top().first == t) {
			int i = job_s.top().second;
			job_critical.push(mp(F[i] - P[i], i));
			job_s.pop();
		}

		queue<pii> q;
		for (int w = 0; w < workerCount; w++) {
			if (job_critical.empty()) break;
			int i = job_critical.top().second; job_critical.pop();
			P[i]--;
			if (P[i] > 0) {
				q.push(mp(F[i] - P[i], i));
			}
		}
		while (!q.empty()) {
			job_critical.push(q.front());
			q.pop();
		}

		if (!job_critical.empty() && job_critical.top().first <= t) {
			cout << "0" << endl;
			return;
		}
	}
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif 
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << endl;
		solveCase();
	}
	return 0;
}