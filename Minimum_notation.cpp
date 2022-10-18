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
    vll cnt(10);
    string ans = "";
    fr(num, 0, 10) {
    	ll pos = -1;
    	fr(j, 0, cnt[num]) {
    		ans += (char)(num + '0');
    	}
    	cnt[num] = 0;
    	fr(i, 0, sz(s)) {
    		if(s[i] - '0' == num) {
    			pos = i;
    			ans += (char)(num + '0');
    		}
    	}
    	if(pos == -1) {
    		continue;
    	}
    	string t = "";
    	fr(i, 0, pos + 1) {
    		if(s[i] - '0' != num) {
    			ll x = s[i] - '0';
    			x = min(9ll, x + 1);
    			cnt[x]++;
    		}
    	}
    	fr(i, pos + 1, sz(s)) {
    		t += s[i];
    	}
    	s = t;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
