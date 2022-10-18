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
    string u;
    cin >> u;
    ll w, m;
    cin >> w >> m;

    ll n = sz(u);
    vll a(n + 1);
    fr(i, 1, n + 1) {
        a[i] = u[i - 1] - '0';
    }
    vll pref(n + 1);
    fr(i, 1, n + 1) {
        pref[i] = pref[i - 1] + a[i];
    }
    auto subsum = [&] (ll l, ll r) {
        return (pref[r] - pref[l - 1]) % 9;
    };

    vll vals(n + 1);
    ll x = 0;
    fr(i, 1, w + 1) {
        x += a[i];
    }
    ll lst = 0;
    vals[1] = x;
    fr(i, w + 1, n + 1) {
        x += a[i];
        x -= a[i - w];
        vals[i - w + 1] = x; 
        lst = i - w + 1;
    }
    while(sz(vals) != lst + 1) {
        vals.pop_back();
    }
    ll num = vals.size();
    fr(i, 0, num) {
        vals[i] %= 9;
    }
    vll l1(9, -1);
    fr(i, 1, num) {
        if(l1[vals[i]] == -1) {
            l1[vals[i]] = i;
        }
    }
    vll l2(9, -1);
    fr(i, 1, num) {
        if(l1[vals[i]] != i && l2[vals[i]] == -1) {
            l2[vals[i]] = i;
        }
    }
    // errA(l1);
    while(m--) {
        ll l, r, k;
        cin >> l >> r >> k;
        ll z = subsum(l, r);
        // ((z * l1) + (l2)) % 9 == k
        // cout << "z = " << z << endl; 
        pll ans = {-1, -1};
        fr(i, 0, 9) {
            if(l1[i] != -1) {
                // cout << "i = " << i << " l1 = " << l1[i] << endl; 
                ll x = ((z * i) - k + 9) % 9;
                x *= -1;
                x += 9;
                x %= 9;
                // err1(x);
                if(x == i) {
                    if(l2[x] != -1) {
                        if(ans.F != -1) {
                            ans = min(ans, {l1[i], l2[x]});
                        } else {
                            ans = {l1[i], l2[x]};
                        }
                    }
                } else {
                    if(l1[x] != -1) {
                        if(ans.F != -1) {
                            ans = min(ans, {l1[i], l1[x]});
                        } else {
                            ans = {l1[i], l1[x]};
                        }
                    }
                }
            }
        }
        cout << ans.F << " " << ans.S << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
