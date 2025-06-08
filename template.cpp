// JAY SHREE RAM
// ChineseBheL

#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define allr(v)          v.rbegin(),v.rend()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll>
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;

//for handling mod operations
const int MOD = 998244353;
template <const int mod>
struct mint {
  int val;
  constexpr mint(long long x = 0) : val((x % mod + mod) % mod) {}
  explicit operator int() const { return val; }
  mint &operator+=(const mint &b) {
    val += b.val;
    val -= mod * (val >= mod);
    return *this;
  }
  mint &operator-=(const mint &b) {
    val -= b.val;
    val += mod * (val < 0);
    return *this;
  }
  mint &operator*=(const mint &b) {
    val = 1ll * val * b.val % mod;
    return *this;
  }
  mint &operator/=(const mint &b) { return *this *= b.inv(); }
  mint inv() const {
    int x = 1, y = 0, t;
    for (int a = val, b = mod; b; swap(a, b), swap(x, y))
      t = a / b, a -= t * b, x -= t * y;
    return mint(x);
  }
  mint power(int b) const {
    mint a = *this, res(1);
    for (; b; a *= a, b /= 2)
      if (b & 1) res *= a;
    return res;
  }
  mint operator-() const { return val == 0 ? 0 : mod - val; }
  mint &operator++() {
    val = val == mod - 1 ? 0 : val + 1;
    return *this;
  }
  mint &operator--() {
    val = val == 0 ? mod - 1 : val - 1;
    return *this;
  }
  mint operator++(int32_t) {
    mint before = *this;
    ++*this;
    return before;
  }
  mint operator--(int32_t) {
    mint before = *this;
    --*this;
    return before;
  }
  friend mint operator+(const mint &a, const mint &b) { return mint(a) += b; }
  friend mint operator-(const mint &a, const mint &b) { return mint(a) -= b; }
  friend mint operator*(const mint &a, const mint &b) { return mint(a) *= b; }
  friend mint operator/(const mint &a, const mint &b) { return mint(a) /= b; }
  friend bool operator==(const mint &a, const mint &b) {
    return a.val == b.val;
  }
  friend bool operator!=(const mint &a, const mint &b) {
    return a.val != b.val;
  }
  friend bool operator<(const mint &a, const mint &b) { return a.val < b.val; }
  friend istream &operator>>(istream &in, mint &a) { return in >> a.val; }
  friend ostream &operator<<(ostream &os, const mint &a) { return os << a.val; }
};
using Mint = mint<MOD>;

//dsu
class DisjointSets {
  private:
	vector<int> parents;
	vector<int> sizes;

  public:
	DisjointSets(int size) : parents(size), sizes(size, 1) {
		for (int i = 0; i < size; i++) { parents[i] = i; }
	}

	/** @return the "representative" node in x's component */
	int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }

	/** @return whether the merge changed connectivity */
	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) { return false; }

		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
		return true;
	}

	/** @return whether x and y are in the same connected component */
	bool connected(int x, int y) { return find(x) == find(y); }
};

//seive
vector<bool> findprime(ll N){
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

//seive to find all factors
vector<vector<ll>> factors(1e6+1);
void findfactors(){
    for (int i = 1; i <= 1e6+1; i++) {
        for(int j = i ; j <= 1e6+1 ; j+=i){
            factors[j].push_back(i);
        }
    }
}

//binexpo
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

//modinv
ll modInv(ll b , ll mod){
    return binpow(b , mod-2 , mod);
}

//nCr
ll nCr(ll n , ll r){
    if(n < r) return 0;
    if(r == 0) return 1;
    vector<ll> fact(n+1 , 1);
    for(int i = 1 ; i <= n ; i++){
        fact[i] = fact[i-1]*i;
        fact[i]%=MM;
    }
    ll res = 1;
    res*=fact[n];
    res%=MM;
    res*=modInv(fact[r] , MM);
    res%=MM;
    res*=modInv(fact[n-r] , MM);
    res%=MM;
    return res;
}

//dijkstra algo
void dijkstra(int k ,vector<vector<pair<int,int>>>& graph ,vector<int>& distance ,vector<int>& vis){
    set<pair<int,int>> st;
    st.insert({0 , k});
    distance[k] = 0;
    while(st.size() > 0){
        int node = (*st.begin()).second;
        int wt = (*st.begin()).first;
        st.erase(st.begin());
        if(vis[node]) continue;
        vis[node] = 1;
        for(auto& child : graph[node]){
            int ch = child.first;
            int chwt = child.second;
            if(wt + chwt < distance[ch]){
                distance[ch] = wt + chwt;
                st.insert({distance[ch] , ch});
            }
        }
    }
}

void ChineseBheL()
{
  
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        ChineseBheL();
    return 0;
}
