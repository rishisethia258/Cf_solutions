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
 
int main()
{
	rapido
	ll i,j,k,tt,n,m,x,y;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		cin>>n;
		vector<ll> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		vector<ll> a(n);
		a=v;
		sv(a);
		vector<pair<int,int> > p;
		for(int i=0;i<n;i++)
		{
			int x=a[i];
			if(v[i]==x)
				continue;
			for(int j=i+1;j<n;j++)
			{
				if(v[j]==x)
				{
					p.pb(make_pair(i,j));
					int y=v[i];
					v[i]=x;
					v[j]=y;
					break;
				}
			}
			// for(int  i=0;i<n;i++)
			// 	cout<<v[i]<<" ";
			// cout<<endl;
		}
		cout<<p.size()<<endl;
		for(int i=0;i<p.size();i++)
			cout<<p[i].ff<<" "<<p[i].ss<<endl;
	return 0;
}
