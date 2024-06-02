#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN = 1e5+5;
//m moves, n items, size w window
ll arr[mxN], n, m, w;
bool can(ll t){
    ll curM = 0;
    ll added = 0;
    vector<ll> az(n);
    for(int i = 0; i<w; i++){
        curM += max((t-arr[i]-added), 0LL);
        az[i] = arr[i] +max(t-arr[i]-added, 0LL);
        added += max((t-arr[i]-added), 0LL);
    }


    for(int i = w; i<n; i++){
        added -= max(az[i-w]-arr[i-w],0LL);
        curM += max((t-arr[i]-added), 0LL);
        az[i] = arr[i] +max(t-arr[i]-added, 0LL);
        added += max((t-arr[i]-added), 0LL);

    }
    return (m>=curM);
}
int main(){
    cin>>n>>m>>w;
    ll smallest = INT_MAX;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
        smallest = min(smallest, arr[i]);
    }
    ll l = smallest;
    ll r = smallest+m; //if we like use all our moves on the smallest 1 and every other ones is smallest +m the best we can do is smallest+m;
    ll x = 0;
    while(l<=r){
        ll mid = (l+r)/2;
        if(can(mid)){
            l = mid+1;
            x = mid;
        }else{
            r = mid-1;
        }
    }
    cout<<x;



}
