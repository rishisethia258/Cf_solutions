/**   
 * Author     : Greedy_Man
 * From       : BUP(CSE)
 * Created on : 01/11/22  
**/
/**
 * One day You'll leave this world
 * behind, So live a life you'll
 * remember!
**/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll           long long
#define db           double
#define pb           push_back
#define pi           acos(-1.0)
#define fast         ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define nl           "\n"
#define all(v)       v.begin(),v.end()
#define precision(x) cout.setf(ios::fixed); cout.precision(x);
#define tc(t)        ll tt; cin >> tt; while (tt--)
#define clean        cout.flush()
#define tree <ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
using namespace __gnu_pbds;
using namespace std;
/**
 *  ||\\  //||    //\\    |\\  //|| ||    || |\\  ||
 *  || \\// ||   //==\\   ||\\// || ||    || ||\\ ||
 *  ||      ||  //    \\  ||     || ||====|| || \\||
**/ 
void solve(){
    ll k;
    cin>>k;
    string str;
    cin>>str;
    map<char,ll>mpp;
    for (ll i = 0; i < str.size(); ++i) { mpp[str[i]]++;}
    for (ll i = 0; i < str.size(); ++i)
    {
        if (mpp[str[i]]%k)
        {
            cout<<-1<<nl;
            return;
        }
    }
    set<char>st;
    for(auto it:str){
        st.insert(it);
    }
    string ans;
    for(auto it:st){
        ans.pb(it);
    }
    for (ll i = 0; i < k/2; ++i)
    {
        ans+=ans;
    }
    cout<<ans<<nl;
}
int main(int argc, char const *argv[]){
    fast;
    /*tc(t){
    solve();
    }*/
   solve();
   return 0;
}
