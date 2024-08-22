#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

vector<int> edge[maxn];
int f[maxn];
bool visited[maxn];

void dfs(int u) {
  visited[u] = true;
  f[u] = 1;
  for (int v : edge[u]) {
    if (!visited[v]) {
      dfs(v);
      f[u] += f[v];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  vector<int> components;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      dfs(i);
      components.push_back(f[i]);
    }
  }
  int res = components.front();
  int rest = 0;
  for (int i = 1; i < components.size(); i++) {
    rest = max(rest, components[i]);
  }
  cout << res + rest << endl;
}
