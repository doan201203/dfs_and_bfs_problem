#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;
int get(int x, int i) { return (x >> i) & 1; }
void off(int x, int i) { x = x & (!(1 << i)); }
void on(int x, int i) { x = x | (1 << i); }
long long mu2[20], s, t;
vector<int> visit, d;
queue<long long> q;
char a;
void up(int x, int i) {
  int v = x - mu2[16 - i] + mu2[16 - i - 4];

  if (!visit[v]) {
    q.push(v);
    d[v] = d[x] + 1;
    visit[v] = 1;
  }
}
void down(int x, int i) {
  int v = x - mu2[16 - i] + mu2[16 - i + 4];

  if (!visit[v]) {
    q.push(v);
    d[v] = d[x] + 1;
    visit[v] = 1;
  }
}
void left(int x, int i) {
  int v = x - mu2[16 - i] + mu2[16 - i - 1];

  if (!visit[v]) {
    q.push(v);
    d[v] = d[x] + 1;
    visit[v] = 1;
  }
}
void right(int x, int i) {
  int v = x - mu2[16 - i] + mu2[16 - i + 1];
  if (!visit[v]) {
    q.push(v);
    d[v] = d[x] + 1;
    visit[v] = 1;
  }
}
void bfs() {
  q.push(s);
  visit[s] = 1;
  while (!q.empty()) {
    long long p = q.front();
    if (p == t) {
      cout << d[p];
      return;
    }
    q.pop();
    for (int i = 0; i < 16; i++) {
      if (get(p, i) == 1) {
        if (i < 12 && get(p, i + 4) == 0)
          up(p, i);
        if (i > 3 && get(p, i - 4) == 0)
          down(p, i);
        if (i % 4 != 3 && get(p, i + 1) == 0)
          left(p, i);
        if (i % 4 != 0 && get(p, i - 1) == 0)
          right(p, i);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  mu2[16] = 1;
  for (int i = 15; i > 0; i--)
    mu2[i] = mu2[i + 1] * 2;
  visit.assign(mu2[1] * 2 + 2, 0);
  d.assign(mu2[1] * 2 + 2, 0);

  for (int i = 1; i <= 16; i++) {
    cin >> a;
    if (a == 'A')
      s += mu2[i];
  }
  for (int i = 1; i <= 16; i++) {
    cin >> a;
    if (a == 'B')
      t += mu2[i];
  }
  bfs();
}
