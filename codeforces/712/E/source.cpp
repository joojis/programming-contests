#include <vector>
#include <cstdio>

using namespace std;

double merge(double probDominateA, double probReverseDominateA, double probDominateB)
{
	return probDominateA * probDominateB / (1 - (1 - probDominateB) * (1 - probReverseDominateA));
}

void solveCase()
{
	int N, Q;
	double P[100000];
	const int X = 400;
	vector<double> dominateReverse(400, 1);
	vector<double> dominate(400, 1);

	scanf("%d %d", &N, &Q);
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		P[i] = (double)a / b;
	}
	for (int i = 0, ri = N - 1; i < N; i++, ri--) {
	  dominate[ri/X] = merge(P[ri], 1-P[ri], dominate[ri/X]);
	  dominateReverse[i/X] = merge(1-P[i], P[i], dominateReverse[i/X]);
	}
	while (Q--) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			int i, a, b;
			scanf("%d %d %d", &i, &a, &b);
			i--;
			P[i] = (double)a / b;
			dominate[i/X] = dominateReverse[i/X] = 1;
			int l = i - (i%X);
			int r = min(N, i - (i%X) + X) - 1;
			for (int j = l, rj = r; j <= r; j++, rj--) {
				dominate[rj/X] = merge(P[rj], 1-P[rj], dominate[rj/X]);
				dominateReverse[j/X] = merge(1-P[j], P[j], dominateReverse[j/X]);
			}
		}
		else {
			int l, r;
			scanf("%d %d", &l, &r);
			l--;
			r--;
			double answer = 1;
			for (int i = r; i >= l; i--) {
			  if (i%X == X-1 && (i - i%X) >= l) {
			    answer = merge(dominate[i/X], dominateReverse[i/X], answer);
			    i -= X - 1;
        } else {
          answer = merge(P[i], 1-P[i], answer);
        }
      }
			printf("%.8lf\n", answer);
		}
	}
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	solveCase();
	return 0;
}
