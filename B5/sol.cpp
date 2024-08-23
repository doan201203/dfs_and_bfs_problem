#include <bits/stdc++.h>
using namespace std;

int mp[201][201];
int n, m;
int in[211], vis[211];
int st[211], ans[211];

void tp() {
  int top = 0;
  int tot = 0;
  int i, j;
  while (1) {
    if (tot >= n) {
      break;
    }
    for (i = n; i >= 1; i--) {
      if (!in[i] && !vis[i]) {
        vis[i] = 1;
        st[++top] = i;
        break;
      }
    }
    if (!top) {
      printf("-1\n");
      return;
    }
    while (top) {
      int u = st[top--];
      for (j = 1; j <= n; j++) {
        if (mp[u][j]) {
          in[j]--;
        }
      }
      ans[u] = ++tot;
    }
  }
  for (i = 1; i <= n; i++) {
    printf("%d%c", n + 1 - ans[i], i == n ? '\n' : ' ');
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        mp[i][j] = 0;
      }
    }

    memset(in, 0, sizeof(in));
    memset(vis, 0, sizeof(vis));
    memset(st, 0, sizeof(st));

    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      if (!mp[b][a]) {
        mp[b][a] = 1;
        in[a]++;
      }
    }

    tp();
  }
}
