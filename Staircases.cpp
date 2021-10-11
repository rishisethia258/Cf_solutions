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
 
#define ll         long long
#define ld         long double
#define endl       "\n"
#define pb         push_back
#define vll        vector<ll>
#define vvll       vector<vll>
#define pll        pair<ll,ll>
#define vbool      vector<bool>
#define vvbool     vector<vbool>
#define vstr       vector<string>
#define vpair      vector<pll>
#define F          first
#define S          second
#define mp(x,y)    make_pair(x,y)
#define all(a)     a.begin(),a.end()
#define rall(a)    a.rbegin(),a.rend()
#define rev(a)     reverse(all(a))
#define unq(a)     a.erase(std::unique(all(a)),a.end());
#define fr(i,a,b)  for(ll i = a ; i < b ; i++)
#define rf(i,a,b)  for(ll i = a ; i >= b; i--)
#define yes()      cout << "YES" << endl
#define no()       cout << "NO" << endl
#define err()      cout << "===========\n";
#define errA(A)    for(auto i : A) cout << i << " "; cout << "\n";
#define err1(a)    cout << #a <<" "<< a << "\n"
#define err2(a,b)  cout << #a <<" "<< a <<" "<< #b <<" "<< b << "\n"
 
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
    ll n, m, q;
    cin >> n >> m >> q;
    vvll a(n + 1, vll(m + 1, 0));
    vvll l(n + 1, vll(m + 1, 0));
    vvll u(n + 1, vll(m + 1, 0));
    fr(i, 1, n + 1) {
        fr(j, 1, m + 1) {
            l[i][j] = u[i][j - 1] + 1;
            u[i][j] = l[i - 1][j] + 1;
        }
    }
    ll ans = 0, cnt = (n * m);
    fr(i, 1, n + 1) {
        fr(j, 1, m + 1) {
            ans += l[i][j] + u[i][j];
        }
    }
 
    function<void(ll, ll)> upd = [&] (ll i, ll j) {
        if(i > n || j > m) {
            return;
        }
        ll up = 0, lf = 0;
        if(a[i][j] == 0) {
            up = l[i - 1][j] + 1;
            lf = u[i][j - 1] + 1; 
        }
        if(l[i][j] == lf && u[i][j] == up) {
            return;
        }
        ans += (up - u[i][j]) + (lf - l[i][j]);
        u[i][j] = up; l[i][j] = lf;
        upd(i + 1, j);
        upd(i, j + 1);
    };
 
    while(q--) {
        ll x, y;
        cin >> x >> y;
        if(!a[x][y]) {
            cnt--;
        } else {
            cnt++;
        }
        a[x][y] ^= 1;
        upd(x, y);
        cout << ans - cnt << endl;
    }
}
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll t = 1; 
    while(t--) solve();
    return 0;
}
