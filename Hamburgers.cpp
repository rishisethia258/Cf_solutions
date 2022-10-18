#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define rapido ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Ff(i,j,n)  for (i = j ; i < n; i++)
#define Fb(i,j,n)  for (i = n-1 ; i >= j; i--)
#define ll long long
#define pb push_back
#define infi 1000006
#define ve vector<int>
#define m1(v) *max_element(v.begin(),v.end())
#define m2(v) *min_element(v.begin(),v.end())
#define sv(v) sort(v.begin(),v.end())
#define sa(a,n) sort(a,a+n)
#define svd(v) sort(v.begin(),v.end(), greater<ll>())
#define sad(a,n) sort(a,a+n,greater<ll>())
#define MOD 1000000007
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second
#define all(v) (v).begin(),(v).end()
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vll> vvll;
typedef vector<vi> vvi;
typedef vector<pll> vpll;
#define MAX 300001
vector<bool> prime(MAX, true);
void SieveOfEratosthenes()
{
    prime[1] = false; prime[0] = false;
    for (int p = 2; p * p <= MAX; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= MAX; i += p)
                prime[i] = false;
        }
    }
}
ll power(ll a, ll b, ll c)
{
    ll res = 1;
    while (b)
    {
        if (b % 2 == 1)
        {res = (res * a) % c; b--;}
        else
        {a = (a * a) % c; b /= 2;}
    }
    return res;
}
int main()
{
    rapido
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif
    string s; cin >> s;
    ll B = 0, S = 0, C = 0;
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] == 'B')
            B++;
        else if (s[i] == 'S')
            S++;
        else if (s[i] == 'C')
            C++;
    }
    ll a, b, c; cin >> a >> b >> c;
    ll x, y, z; cin >> x >> y >> z;
    ll r; cin >> r;
    ll ans;
    ll i = 0, j = 1ll * 1e15;
    while (i <= j)
    {
        ll mid = i + (j - i) / 2;
        ll cost = x * max(mid * B - a, 1ll * 0) + y * max(mid * S - b, 1ll * 0) + z * max(mid * C - c, 1ll * 0);
        // cout << mid << " " << cost << endl;
        if (cost > r)
            j = mid - 1;
        else if (cost <= r)
        {ans = mid; i = mid + 1;}
 
    }
    cout << ans;
}
