// https://codeforces.com/contest/432/problem/D
// Author: joaoc.
// 28/01/2024.

#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> Zfunction(const string &s) {
  int n = s.size();
  vector<int> Z(n, 0);
  int L = 0, R = 0;
  for(int i = 1; i < n; i++) {
    if(i > R) {
      L = R = i;
      while(R < n && s[R - L] == s[R]) R++;
      Z[i] = R - L;
      R--;
    } else {
      int k = i - L;
      if(Z[k] < R - i + 1) {
        Z[i] = Z[k];
      } else {
        L = i;
        while(R < n && s[R - L] == s[R]) R++;
        Z[i] = R - L;
        R--;
      }
    }
  }
  return Z;
}

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> Z = Zfunction(s);
  vector<int> borda;
  borda.push_back(n);
  for(int i = 0; i < n; i++) {
    if(Z[i] == n - i) {
      borda.push_back(Z[i]);
    }
  }  
  map<int,int> cnt;
  cnt[n]++;
  for(auto &x : Z) cnt[x] ++;
  for(int i = n - 1; i >= 0; i--) {
    cnt[i] += cnt[i + 1];
  }
  vector<pair<int,int>> ans;
  cout << borda.size() << '\n';
  for(auto &l : borda) {
    ans.push_back({l, cnt[l]});
  }
  sort(ans.begin(), ans.end());
  for(auto &[l, c] : ans) {
    cout << l << ' ' << c << '\n';
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);

  int t; //cin >> t;
  t=1;
  while(t--) {
    solve();
  }

  return 0;
}