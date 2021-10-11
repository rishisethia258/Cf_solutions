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
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
int main()
{
	rapido
	// ll i,j,k,tt,n,m,x,y;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		string s,t;int k;
		cin>>s>>t>>k;
		int n=s.size();
		vector<int> v(n);
		set<string> se;
// 		cout<<s<<" ";
		for(int i=0;i<n;i++)
		{
			string a;
			int u=0;
			for(int j=i;j>=0;j--)
			{
			    int m=s[j]-'a';
			 //   cout<<m<<" ";
				if(t[m]=='0')
					u++;
				if(u<=k)
				{
					a.pb(s[j]);
				// 	cout<<a<<" ";
					se.insert(a);
				}
				else
					break;
			}
		}
// 		for(auto i:se)
// 		cout<<i<<" ";
		cout<<se.size();
 
	return 0;
}
