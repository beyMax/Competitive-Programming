#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  int n;
  cin >> n;
  int a = 1e9, b = 0;
  priority_queue<pair<int, int>> st;
  for (register int i = 0, l, r; i < n; i++) {
    cin >> l >> r;
    a = min(r, a);
    b = max(l, b);
    st.push(make_pair(-1 * l, -1 * r));
  }
  if (a >= b) return cout << -1 << "\n", 0;

  priority_queue<int> end;
  int cnt = 1, s, e;
  end.push(st.top().second);
  st.pop();
  int ans = 1e5;
  while (!st.empty()) {
    s = (-1) * st.top().first;
    e = (-1) * end.top();
    if (s < e) {
      end.push(st.top().second);
      st.pop();
      if (s > a and s < b and ans > cnt) ans = cnt;
      cnt++;
    } else if (s > e) {
      end.pop();
      cnt--;
      if (e >= a and e < b and ans > cnt) ans = cnt;
      if (end.empty() and !st.empty()) {
        end.push(st.top().second);
        st.pop();
        cnt++;
      }
    } else {
      int tmp = cnt + 1;
      end.pop();
      end.push(st.top().second);
      st.pop();
      if (e > a and e < b and ans > cnt) ans = cnt;
    }
    if (ans == 0) return cout << 0 << "\n", 0;
  }

  cout << ans << '\n';
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif

  register int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}