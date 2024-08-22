#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug20.h"
#else
#define debug(...) 42
#endif

using namespace std;
using i64 = int64_t;

const int dir[] = {0, -1, 0, 1, 0};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
//   cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    int mn = 1e9, mx = -1e9;
    int was[101][101];

    for (auto &i : a)
      for (auto &j : i) {
        cin >> j;
        mn = min(mn, j);
        mx = max(mx, j);
      }

    auto isValid = [&](int i, int j) {
      return min(i, j) >= 0 and i < n and j < m and !was[i][j];
    };
    auto isBorder = [&](int i, int j) {
      return i == 0 || j == 0 || i == n - 1 || j == m - 1;
    };

    int ans = 0;
    for (int lim = mn; lim <= mx; lim++) {
      memset(was, 0, sizeof was);
      debug(lim);
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (!was[i][j] and a[i][j] < lim) {
            queue<pair<int, int>> q;
            int cnt = 0, ok = 1;
            q.push({i, j});
            was[i][j] = 1;
            debug(i, j);
            while (!q.empty()) {
              cnt++;
              auto [x, y] = q.front();
              q.pop();
              debug(x, y);
              if (isBorder(x, y))
                ok = 0;

              for (int k = 0; k < 4; k++) {
                int dx = dir[k] + x;
                int dy = dir[k + 1] + y;
                if (!isValid(dx, dy) || a[dx][dy] >= lim)
                  continue;
                was[dx][dy] = 1;
                q.push({dx, dy});
              }
            }
            if (ok)
              ans += cnt;
          }
        }
      }
    }

    cout << ans << '\n';
  }
  return 0;
}
