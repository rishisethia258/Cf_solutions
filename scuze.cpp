#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define M 1000000007
int main()
{
    ll t, tm = 0;
    cin >> t;
    while (t--)
    {
        ll n, qu; cin>>n>>qu;
        vector<ll> pref(n), q(qu), mxe(n), ans;
        ll mxx=-1e9;
        vector<pair<ll,ll>>v(n);
        for(ll x=0; x < n; x++) 
        {
            cin>>v[x].first;
            v[x].second=x;
            mxe[x]=max(mxx, v[x].first);
            mxx = max(mxx, v[x].first);
        }
        for(ll x=0; x < qu; x++) cin>>q[x];
        ll mx=v[n-1].second;
        for(ll x=n-2; x>=0;x--)
        {
            if(v[x].first==v[x+1].first)
            {
                v[x].second=max(v[x].second,mx);
                mx = max(v[x].second, mx);
            }
            else
            {
                mx=v[x].second;
            }
        }
        pref[0]=v[0].first;
        for(ll x=1; x<n; x++) pref[x]=pref[x-1]+v[x].first;
        sort(v.begin(),v.end());
        vector<ll> a(n), b(n);
        ll start = v[0].second;
        for (int x = 0; x < n; x++)
        {
            a[x] = v[x].first;
            b[x] = max(v[x].second, start);
            start = max(v[x].second, start);
        }
        for (auto it : q)
        {
            auto itr = lower_bound(a.begin(), a.end(), it);
            ll i = itr - a.begin() < n ? itr - a.begin() : itr - a.begin() - 1;
            ll val = a[i];
            if (val > it)
                --i;
            ll in = b[i];
            if (val > a[i])
                --i;
            if (i < 0 || mxe[in]>it)
                ans.push_back(0);
            else
                ans.push_back(pref[b[i]]);
        }
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
}
