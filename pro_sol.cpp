 
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
		cin>>tt;
		while(tt--)
		{
			int n;cin>>n;
			char x;cin>>x;
			string s;
			cin>>s;
			int c=-1;
			for(int i=0;i<n;i++)
			{
				if(s[i]!=x)
					c++;
			}
			if(c==-1)
				{cout<<0<<endl;continue;}
			vector<int> v;
			for(int i=n-1;i>=0;i--)
			{
				if(s[i]==x)
					{v.pb(i);}
			}
			int f=-1;
			for(int i=0;i<v.size();i++)
			{
				int x=v[i]+1;
				int j=2;
				int c=0;
				while(j*x<=n)
				{
					if(s[j*x-1]!=x)
						c++;
					j++;
				}
				if(c==0)
				{
					f=0;
					cout<<1<<endl;
					cout<<x<<endl;
					break;
				}
			}
			if(f==-1)
			{
			cout<<2<<endl;
			cout<<n-1<<" "<<n<<endl;}
			
		}
	return 0;
