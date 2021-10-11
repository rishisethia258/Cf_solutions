#include <bits/stdc++.h>
using namespace std;
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
 
void dfs(vector<ll> &r,vector<ll> list[], ll node, ll arrival)
{
    // Printing traversed node
    
    r.pb(node);
    // Traversing adjacent edges
    for (ll i = 0; i < list[node].size(); i++) {
 
        // Not traversing the parent node
        if (list[node][i] != arrival)
            dfs(r,list, list[node][i], node);
    }
}
 
int main()
{
	rapido
	ll i,j,k,tt,n,m,x,y;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		cin>>tt;
		while(tt--)
		{
			ll n,k;cin>>n>>k;
			vector<ll> v(n);
			for(ll i=0;i<n;i++)
				cin>>v[i];
			vector<ll> list[n+1];
			for(ll i=0;i<n-1;i++)
			{
				ll a,b;
				cin>>a>>b;
				list[a].pb(b);
				list[b].pb(a);
			}
			vector<ll> r;
			dfs(r,list, 1, 0);
			for(ll i=0;i<n;i++)
				{r[i]=v[r[i]-1];}
			for(ll i=1;i<n;i++)
				{r[i]=(r[i]^r[i-1]);}
			if(r[n-1]==0)
				{cout<<"YES"<<endl;continue;}
			ll f=-1;
			for(ll i=0;i<n;i++)
			{
				if(r[i]==0)
				{f=i;break;}
			}
			if(f==-1)
				{cout<<"NO"<<endl;continue;}
			if(k==2)
				{cout<<"NO"<<endl;continue;}
			int x=-1;
			for(ll i=0;i<f;i++)
			{
				if(r[i]==r[n-1])
					{x=1;break;}
			}
			if(x==1)
				{cout<<"YES"<<endl;continue;}
			{cout<<"NO"<<endl;continue;}
		}
	return 0;
}
