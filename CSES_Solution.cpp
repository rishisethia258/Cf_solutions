//Solution to 1639 Problem DP

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<chrono>
#include<complex>
//#include<sysinfoapi.h>
using namespace std;
using namespace __gnu_pbds;
using namespace std::chrono;
using ll = long long;
using ull = unsigned long long ;
using lli = long long int;
using ulli = unsigned long long int ;
#define fastio { ios_base::sync_with_stdio(false); cin.tie(NULL);}
#define pb push_back
#define mp make_pair
#define endl "\n"
const double pi2=acos(-1);
//typedef complex<double> point;
typedef tree<ll  , null_type,less < ll >,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

template < typename T1> 
void print_vec1(vector < T1 > v){
    for(auto i:v)cout<<i<<" ";
    cout<<endl;
    return;
}
template < typename T2 > 
void print_vec2(vector < T2 > v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}
void solve(){
    string a;
    string b;
    cin>>a>>b;
    
    // cout<<a<<" "<<b<<endl;
    int n = a.size();
    int m = b.size();
    vector < vector < int > > dp(n+2,vector < int > (m+2,0));
    a = "0"+a;
    b = "0"+b;
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            if(a[i]==b[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
                // printf("dper %c %i %i",a[i],i,j);
            }
            else{
                dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    int cons = dp[1][1];
    cout<<"lcs val "<<cons<<endl;
    string lcs = "";
    int i = 1;
    int j = 1;
    int x_greatest = 1;
    while(i<=n or j<=m){
        if(cons==0)break;
        if(j==m+1){
            j=x_greatest;i++;
        }
        if(cons == dp[i][j] and a[i]==b[j]){
            cout<<i<<" "<<j<<endl;
            lcs += a[i];
            i++;
            j++;
            x_greatest = max(x_greatest,j);
            cons--;
        }
        else{
            j++;
        }
    }
    // cout<<lcs<<endl;
    cout<<max(n,m)-dp[n][m]-1<<endl;
    return;
}

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // fastio
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

//g++ -O2 -Wall -Wl,--stack=268435456 -Wextra -std=c++14 -pedantic -Wshadow -Wformat=2 -Wfloat-equal
