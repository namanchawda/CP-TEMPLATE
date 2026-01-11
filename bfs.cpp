#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long double
void print(vector<ll>&v){for(auto it: v){cout << it << " ";}cout << endl;}
#define MOD (ll) (1e9+7)
#define all(x) (x).begin(), (x).end()
#define rall(n) n.rbegin(), n.rend()
#define MAX_OF_THREE(a, b, c) ((a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c))
#define MIN_OF_THREE(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
#define MAX4(a, b, c, d) max(max(a, b), max(c, d))
#define MIN4(a, b, c, d) min(min(a, b), min(c, d))
#define set_bits __builtin_popcountll
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
ll mod_add(ll a, ll b, ll mod) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
template<typename T> T maxVal(T a, T b) {return (a > b) ? a : b;}
#define MAX2 maxVal<ll>
template<typename T> T minVal(T a, T b) { return (a < b) ? a : b;}
#define MIN2 minVal<ll>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;



const ll N = 1e5 + 10;
const ll INF = 1e9 + 10;
vector<ll> g[N];
ll vis[N];
// ll level[N];
vector<ll> level01(N, INF);

// Breadth First Search 
// Time Complexity - O(V + E)
void bfs(ll source) {
    queue<ll> q;
    q.push(source);
    vis[source] = 1;

    while(!q.empty()) {
        ll curr_v = q.front();
        q.pop();
        for(ll child: g[curr_v]) {
            if(!vis[child]) {
                q.push(child);
                vis[child] = 1;
                level[child] = level[curr_v] + 1;
            }
        }
    }
}
/*
    bfs(1);
    for(int i = 1; i <= n; i++) {
        cout << i << " " << level[i] << endl;
    }
*/


// 0/1 BFS - using a Deque 
void BFS01() {
    deque<ll> q;
    q.push_back(1);
    level[1] = 0;

    while(!q.empty()) {
        ll vertex = q.front();
        q.pop_front();

        for(auto child : g[vertex]) {
            ll child_v = child.first;
            ll wt = child.second;
            if(level[vertex] + wt < level[child]) {
                level[child] = level[vertex] + wt;
                if(wt == 0) {
                    q.pop_front(wt);
                }
                else {
                    q.push_back(wt);
                }
            }
        }
    }
}


void solve() {

    ll n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        ll x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }


    bfs(1);
    for(int i = 1; i <= n; i++) {
        cout << i << " " << level[i] << endl;
    }
    
    


}

int main() {

    solve();
}
