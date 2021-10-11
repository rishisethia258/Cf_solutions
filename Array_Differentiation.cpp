 #include <bits/stdc++.h>
 #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define pb(a) push_back(a)
#define arr(a) new ll int[a]
#define INF 100000000000000000
#define MOD 1000000007
#define MOD1 998244353
#define MOD2 31607
#define arr1(a) new arra[a]
#define str(a) new string[a]
#define all(v) v.begin(),v.end()
#define mp(a,b) make_pair(a,b)
#define F first
#define S second
#define PI 3.14159265
#define oset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<bool> vb;
void yes(){cout<<"YES"<<endl;}
void no(){cout<<"NO"<<endl;}
//const int N = 300001,p=31;
//////ll int pw[N],inv_pw[N],hash2[N+1],hash1[N+1],pw1[N],inv_pw1[N],hash1r[N+1],hash2r[N+1];
//ll fact[N];
//void factorial(ll mod){
//    fact[0] = fact[1] = 1;
//    for(ll i = 2; i < N; i++)
//        fact[i] = (fact[i-1] * i) % mod;
//}
 ll power(ll a, ll b, ll mod){
 	ll x = 1, y = a;
 	while (b > 0){
 		if (b%2){
 			x = (x*y)%mod;
 		}
 		y = (y*y)%mod;
 		b /= 2;
 	}
 	return x%mod;
 }
//////
ll modular_inverse(ll n, ll mod){
	return power(n, mod-2, mod);
}
//void precal()
//{
//    pw[0]=1;
//    pw1[0]=1;
//    inv_pw1[0]=1;
//    inv_pw[0]=1;
//    ll int temp=modular_inverse(p,MOD),temp1=modular_inverse(p,MOD1);
//    for(ll int i=1;i<N;i++)
//    {
//        pw[i]=(pw[i-1]*p)%MOD;
//        pw1[i]=(pw1[i-1]*p)%MOD1;
//        inv_pw1[i]=(inv_pw1[i-1]*temp1)%MOD1;
//        inv_pw[i]=(inv_pw[i-1]*temp)%MOD;
//    }
//}
//void build(string& s,ll int hash1[],ll int pw[],ll int mod)
//{
//    ll int n=s.size();
//    for(ll int i=1;i<=n;i++)
//    {
//        hash1[i]=(hash1[i-1]+(pw[i-1]*(s[i-1]-'a'+1))%mod)%mod;
//    }
//}
//ll int get_hash(ll int hash1[],ll int inv_pw[],ll int mod,ll int l,ll int r)
//{
//    if(l>r)return 0;
//    ll int res=(hash1[r]-hash1[l-1]+mod)%mod;
//    res=(res*inv_pw[l-1])%mod;
//    return res;
//}
//ll nCr(ll n, ll k, ll mod){
//	return (fact[n]*((modular_inverse(fact[k],mod)*modular_inverse(fact[n-k],mod))%mod))%mod;
//}
//typedef struct node{
//    node* left;
//    node* right;
//    ll d;
//}node;
//node* create(ll int i)
//{
//    node* temp=new node;
//    temp->d=i;
//    temp->left=NULL;
//    temp->right=NULL;
//    return temp;
//}
//struct arra{
//    ll a,b,c,d;
//}arr[103];
//bool comp(struct arra a,struct arra b)
//{
//    return (a.d<b.d);
//}
//bool comp1(struct arra a,struct arra b)
//{
//    return (a.h<b.h);
//}
//bool comp1(ll val,struct arra a) //arr.d in increasing order(upperbound comp function
//{
//    return val<a.d;
//}
//bool comp3(struct arra a,ll val) //arr.d in increasing order(lowerbound comp function
//{
//    return a.h<val;
//}
//const int N=32000;
//int composite[N];
//vector<int>p;
//void sieve()
//{
//    for(ll int i=2;i<N;i++)
//    {
//        if(!composite[i])
//        {
//            composite[i]=i;
//            p.pb(i);
//            for(ll j=i*i;j<N;j+=i)
//            {
//                if(!composite[j])composite[j]=i;
//            }
//        }
//    }
//}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    #endif
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vi v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        bool res=0;
        map<int,int>mp;
        for(int k=0;k<pow(2,n);k++)
        {
            int sum=0,a=1;
            for(int i=0;i<n;i++)
            {
                if((k&a)!=0)sum+=v[i];
                a*=2;
            }
            if(mp.find(sum)!=mp.end())
            {
                res=1;
                break;
            }
            mp[sum]++;
        }
        if(res)yes();
        else no();
    }
    return 0;
}
