#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> edges[100000];
int A[100000];
int sum0, sum1, nodes0, nodes1;

void dfs(int i, int color, int par) {
	if (color == 0) {
		nodes0++;
		sum0 += A[i];
	} else {
		nodes1++;
		sum1 += A[i];
	}

	for (int j : edges[i]) {
		if (j != par) {
			dfs(j, 1 - color, i);
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) { cin >> A[i]; }

	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	dfs(0, 0, -1);

	// same mod means you can start anywhere
	if ((sum0 % 12) == (sum1 % 12)) {
		cout << N;
	}
	// if group0 is 1 smaller than group1, we must start from group1
	else if ((sum0 + 1) % 12 == (sum1 % 12)) {
		cout << nodes1;
	}
	// if group1 is 1 smaller than group0, we must start from group0
	else if ((sum0 % 12) == ((sum1 + 1) % 12)) {
		cout << nodes0;
	}
	// no way to get all clocks pointing to 12
	else {
		cout << 0;
	}
}
