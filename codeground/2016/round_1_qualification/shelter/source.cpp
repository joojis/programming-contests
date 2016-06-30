#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

#define mp make_pair

typedef pair<int, int> pii;
typedef priority_queue<pii> pq_pii;

struct _Candidate {
	int fullcost;
	int dest;
	int shelter;
	_Candidate(int cost, int dest, int shelter) {
		this->fullcost = cost;
		this->dest = dest;
		this->shelter = shelter;
	}
	bool operator<(const _Candidate& other) const {
		if (this->fullcost == other.fullcost) {
			return this->shelter > other.shelter;
		}
		return this->fullcost > other.fullcost;
	}
} typedef Candidate;

void solveCase()
{
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> costs(N+1, -1), shelters(N+1, -1);
	vector<vector<pii> > edges(N + 1);
	for (int i = 0; i < M; i++) {
		int s, e, cost;
		cin >> s >> e >> cost;
		edges[s].push_back(mp(e, cost));
		edges[e].push_back(mp(s, cost));
	}

	int unknownCount = N;
	queue<int> added;
	for (int i = 0; i < K; i++) {
		int s;
		cin >> s;
		shelters[s] = s;
		costs[s] = 0;
		unknownCount--;
		added.push(s);
	}

	priority_queue<Candidate> candidates;
	while (unknownCount > 0) {
		while (!added.empty()) {
			int s = added.front();
			for (int i = 0; i < edges[s].size(); i++) {
				int e = edges[s][i].first;
				int cost = edges[s][i].second;
				if (shelters[e] != -1) continue;
				candidates.push(Candidate(costs[s] + cost, e, shelters[s]));
			}
			added.pop();
		}

		Candidate c = candidates.top();
		candidates.pop();

		if (shelters[c.dest] != -1) continue;

		costs[c.dest] = c.fullcost;
		shelters[c.dest] = c.shelter;
		unknownCount--;
		added.push(c.dest);
	}

	long long int cost_sum = 0, shelter_sum = 0;
	for (int i = 1; i <= N; i++) {
		cost_sum += costs[i];
		shelter_sum += shelters[i];
	}

	cout << cost_sum << endl << shelter_sum << endl;
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