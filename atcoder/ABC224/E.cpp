#include <bits/stdc++.h>
// #include<bits/extc++.h>
// #define int long long//__int128
#define mmst0(x) memset(x, 0, sizeof(x))
#define mmst3f(x) memset(x, 0x3f, sizeof(x))
#define si(x) scanf("%d", &x)  // scanf("%lld",&x) // When define int ll
#define pb(x) emplace_back(x)
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
#define YESS printf("Yes\n")
#define NOO printf("No\n")
#define fori(a, b, c, d) for (int a = (b); a <= (c); a += (d))
#define ford(a, b, c, d) for (int a = (b); a >= (c); a -= (d))
using namespace std;
// using namespace __gnu_pbds; // If using pbds don't using std!
using ll = long long;
// typedef long double rld; // use double pls!
using ull = unsigned long long;

const double eps = 1e-6;
const int INF = 0x3f3f3f3f;  // 0x3f3f3f3f3f3f3f3f; // LLINF
const int MAXN = (int)2e3 + 3;

inline char nc() { return getchar(); }
inline int read() {
  int s = 0, w = 1;
  char ch = nc();
  while (!isdigit(ch)) {
    if (ch == '-') w = -1;
    ch = nc();
  }
  while (isdigit(ch)) {
    s = (s << 3) + (s << 1) + (ch ^ 48);
    ch = nc();
  }
  return s * w;
}
// inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
//  inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9'))
//  ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} //
//  根据参数个数自动选择 void prt(int
//  x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}
int n, m, k, S, T, x;
vector<int> gr[MAXN];
const int mod = 998244353;
ll dp[MAXN][MAXN][2];
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> n >> m >> k >> S >> T >> x;
  int u, v;
  while (m--) {
    cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }
  dp[1][S][0] = 1;
  for (int i = 2; i <= k + 1; i++) {
    for (int j = 1; j <= n; j++) {
      if (dp[i - 1][j][0] || dp[i - 1][j][1]) {
        for (auto l : gr[j]) {
          if (l == x) {
            dp[i][l][1] = (dp[i][l][1] + dp[i - 1][j][0]) % mod;
            dp[i][l][0] = (dp[i][l][0] + dp[i - 1][j][1]) % mod;
          } else {
            dp[i][l][0] = (dp[i][l][0] + dp[i - 1][j][0]) % mod;
            dp[i][l][1] = (dp[i][l][1] + dp[i - 1][j][1]) % mod;
          }
        }
      }
    }
  }

  cout << dp[k + 1][T][0] % mod;
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  // //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
  signed T = 1;  //(signed)read();//scanf("%d",&T);//cin>>T;
  for (signed CASE = 1; CASE <= T; CASE++) {  //
    // printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case
    // #%d: \n",CASE); //printf("Case %d: \n",CASE); while(cin>>n) work(n);
    work(CASE, CASE == T);
  }
  return 0;
}