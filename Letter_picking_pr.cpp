// Author : rs258
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 

template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, 
tree_order_statistics_node_update>;
template <typename T>
using omultiset = tree<T, null_type, less_equal<T>, rb_tree_tag, 
tree_order_statistics_node_update>; 

#define ll            long long
#define ld            long double
#define endl          "\n"
#define pb            push_back
#define vll           vector<ll>
#define vvll          vector<vll>
#define pll           pair<ll,ll>
#define vbool         vector<bool>
#define vpair         vector<pll>
#define F             first
#define S             second
#define sz(a)         ((ll)(a.size()))
#define all(a)        a.begin(),a.end()
#define rall(a)       a.rbegin(),a.rend()
#define rev(a)        reverse(all(a))
#define unq(a)        a.erase(std::unique(all(a)),a.end());
#define fr(i,a,b)     for(ll i = a ; i < b ; i++)
#define rf(i,a,b)     for(ll i = a ; i >= b; i--)

#define yes()         cout << "YES" << endl
#define no()          cout << "NO" << endl
#define err()         cout << "===========\n";
#define errA(A)       for(auto i : A) cout << i << " "; cout << "\n";
#define err1(a)       cout << a << "\n"
#define err2(a,b)     cout << a << " " << b << "\n"
#define err3(a,b,c)   cout << a << " " << b << " " << c <<  "\n"

const ll mod1 =    1000000007;
const ll mod2 =    998244353;
const ll infi =    1e18;
const ld eps  =    1e-9;

ll test_case = 0;
void google() {
    test_case++;
    cout << "Case #" << test_case << ": ";
}

ll pwr(ll a, ll b) {
    ll res = 1;
    while (b > 0) { 
        if (b & 1) res = (res * a);   
        a = (a * a); b >>= 1;
    }
    return res;
}

ll modpwr(ll a, ll b, ll x = mod1) {
    ll res = 1; 
    while (b > 0) { 
        if (b & 1) res = (res * a) % x;
        a = (a * a) % x; b >>= 1;
    } 
    return res;
}

ll modInverse(ll n, ll p = mod1) { 
    return modpwr(n, p - 2, p); 
}

void solve() {
    string s;
    cin >> s;
    ll n = s.size();
    vvll dp(n, vll(n, 0));
    fr(i, 0, n - 1) {
        if(s[i] == s[i + 1]) {
            dp[i][i + 1] = 1;
        }
    }
    for(ll len = 3 ; len <= n ; len += 2) {
        fr(l, 0, n) {
            ll r = l + len;
            if(r >= n) {
                break;
            }
            if((dp[l + 2][r] == 1 && s[l] == s[l + 1]) && (dp[l][r - 2] == 1 && s[r] == s[r - 1])) {
                dp[l][r] = 1;
            } else if(dp[l + 1][r - 1] == 1 && s[l] == s[r]) {
                dp[l][r] = 1;
            }
        }
    }
    if(dp[0][n - 1] == 1) {
        cout << "Draw" << endl;
    } else {
        cout << "Alice" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
