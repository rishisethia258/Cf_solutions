#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define pb(a) push_back(a)
#define arr(a) new ll int[a]
#define INF 1000000000000000000
#define MOD 1000000007
#define MOD1 998244353
#define arr1(a) new arra[a]
#define str(a) new string[a]
#define all(v) v.begin(),v.end()
#define mp(a,b) make_pair(a,b)
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<bool> vb;
void yes(){cout<<"YES"<<endl;}
void no(){cout<<"NO"<<endl;}
const int N = 1000008,p=31;
//ll int pw[N],inv_pw[N],hash2[N+1],hash1[N+1],pw1[N],inv_pw1[N],hash1r[N+1],hash2r[N+1];
ll fact[N];
void factorial(ll mod){
    fact[0] = fact[1] = 1;
    for(ll i = 2; i < N; i++)
        fact[i] = (fact[i-1] * i) % mod;
}
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
ll nCr(ll n, ll k, ll mod){
	return (fact[n]*((modular_inverse(fact[k],mod)*modular_inverse(fact[n-k],mod))%mod))%mod;
}
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
//    ll int a,t;
//}arr[200001];
//bool comp1(ll val,struct arra a) //arr.d in increasing order(upperbound comp function
//{
//    return val<a.d;
//}
//bool comp2(struct arra a,ll val) //arr.d in increasing order(lowerbound comp function
//{
//    return a.d<val;
//}
ll bit1[1000001],bit2[1000001];
ll read1(ll idx)
{
    ll res=0;
    idx++;
    while(idx>0)
    {
        res+=bit1[idx];
        idx-=(idx & -idx);
    }
    return res;
}
void update1(ll idx,ll val)
{
    idx++;
    while(idx<1000001)
    {
        bit1[idx]+=val;
        idx+=(idx & -idx);
    }
}
ll read2(ll idx)
{
    ll res=0;
    idx++;
    while(idx>0)
    {
        res+=bit2[idx];
        idx-=(idx & -idx);
    }
    return res;
}
void update2(ll idx,ll val)
{
    idx++;
    while(idx<1000001)
    {
        bit2[idx]+=val;
        idx+=(idx & -idx);
    }
}
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
        ll n,m,k,a,a1,a2,res=0;
        cin>>n>>m>>k;
        vector<ll>v1,v2,t1,t2;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            v1.push_back(a);
        }
        for(int i=0;i<m;i++)
        {
            cin>>a;
            v2.push_back(a);
        }
        vector<pll>v11,v22;
        for(int i=0;i<k;i++)
        {
            cin>>a1>>a2;
            v11.push_back(mp(a1,a2));
            v22.push_back(mp(a2,a1));
        }
        sort(all(v11));
        sort(all(v22));
        int i=0;
        while(i<k)
        {
            a=v11[i].first;
            vector<ll>temp;
//            cout<<i<<endl;
            while(i<k && v11[i].first==a)
            {
//                cout<<i<<endl;
                a1=v11[i].second;
                i++;
                temp.pb(a1);
                if(binary_search(all(v2),a1))continue;
                int a11=lower_bound(all(v2),a1)-v2.begin();
                res+=read1(v2[a11]-1)-read1(v2[a11-1]);
            }
            for(auto j:temp){
                update1(j,1);
                t1.push_back(j);
            }
        }
        i=0;
        while(i<k)
        {
            a=v22[i].first;
            vector<ll>temp;
            while(i<k && v22[i].first==a)
            {
                a1=v22[i].second;
                i++;
                temp.pb(a1);
                if(binary_search(all(v1),a1))continue;
                int a11=lower_bound(all(v1),a1)-v1.begin();
                res+=read2(v1[a11]-1)-read2(v1[a11-1]);
            }
            for(auto j:temp){
                update2(j,1);
                t2.pb(j);
            }
        }
        for(auto j:t1)update1(j,-1);
        for(auto j:t2)update2(j,-1);
        cout<<res<<endl;
    }
    return 0;
}
