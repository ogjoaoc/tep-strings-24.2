// O(N) -> N é o tamanho da string.
// Z[i] é o tamanho do maior prefixo de s que também é um prefixo da substring s[i..n-1].
// Tags: Padrões, bordas e compressão.

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