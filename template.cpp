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

ll modInv(ll b , ll mod){
    return binpow(b , mod-2 , mod);
}

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
