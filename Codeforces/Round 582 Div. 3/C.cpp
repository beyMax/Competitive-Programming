#include <algorithm>
#include <bits/stdc++.h>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;

#define int int64_t
#define ll long long
#define FAST                                                                   \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);

const int mod = 1e9 + 7;

template <class T> void read(T &x) {
  int f = 0;
  x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-')
      f = 1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = (x << 3) + (x << 1) + (s ^ 48);
    s = getchar();
  }
  x = f ? -x : x;
}

void solve() {
  ll n, m;
  std::cin >> n;
  std::cin >> m;
  int rn = n / m;
  ll ans = 0;
  for (int i = 0; i < rn; i++) {
    ll a = (i + 1) * m;
    ans = ans + (a % 10);
  }
  std::cout << ans << '\n';
}

inline void test() {
  int T;
  read(T);
  while (T--) {
    solve();
  }
}

signed main() {
  FAST;
  //    freopen("input.txt", "r", stdin);
  // solve();
  test();
  return 0;
}
