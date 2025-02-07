#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll p = 911382323; 
const ll q = 972663749; 

int f(char c) {
  return c - 'a' + 1;  // 'a' -> 1, 'b' -> 2, ..., 'z' -> 26
}

void precompute(const string& s, vector<ll>& ps, vector<ll>& powers) {
  int N = s.size();
  ps.resize(N + 1, 0);
  powers.resize(N + 1, 1);

  for (int i = 0; i < N; ++i) {
    ps[i + 1] = (ps[i] * p + f(s[i])) % q;
    powers[i + 1] = (powers[i] * p) % q;
  }
}

ll substring_hash(int l, int r, const vector<ll>& ps, const vector<ll>& powers) {
  ll hash = (ps[r + 1] - ps[l] * powers[r - l + 1] % q + q) % q;
  return hash;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s = "banana";
  int n = s.size(); 

  vector<ll> ps, powers;
  precompute(s, ps, powers);

  int l = 3, r = 5;
  ll hash = substring_hash(l, r, ps, powers);

  return 0;
}