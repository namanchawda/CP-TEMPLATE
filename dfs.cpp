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


// ---------DFS CODE---------
// const ll N = 1e5+10;
// vector<ll> g[N];
// bool vis[N];
// // time complexity : O(V + E)


// *This will show ki DFS kaise chal rha*
// void dfs(ll vertex){
//     cout << vertex << endl;
//     vis[vertex] = true; 
//     for(ll child : g[vertex]){
//         cout << "par " << vertex << ", child " << child << endl;
//         if(vis[child]) continue;
//         dfs(child);
//     }
// }
// ---------DFS CODE---------



const ll N = 1e5+10;
vector<ll> g[N];
bool vis[N];
// time complexity : O(V + E)


// Graph dfs
void dfs(ll vertex){
    vis[vertex] = true;
    for(ll child : g[vertex]){
        if(vis[child]) continue;
        dfs(child);
    }
}

// 13
// 1 2
// 1 3
// 1 13
// 2 5
// 3 4
// 5 6
// 5 7
// 5 8
// 8 12
// 4 9
// 4 10
// 10 11


// Returns True if Loop Exists in Graph
bool dfs(ll vertex, ll par=0) {
    vis[vertex] = 1;
    bool isLoopExists = false;
    for(ll child: g[vertex]) {
        if(vis[child] && child == par) continue;
        if(vis[child]) return true;
        isLoopExists |= dfs(child, vertex);
    }
    return isLoopExists;
}
/*bool isLoopExists = false;
    for(int i=1; i<=n; i++) {
        if(!vis[i]){
            if(dfs(i)){
                isLoopExists = true;
                break;
            }
        }
    }
    if(!isLoopExists) cout << "IMPOSSIBLE" << endl;
*/




ll height[N], depth[N];
// Depth and Height of tree dfs
void dfst(ll vertex, ll par=0){
    for(ll child: g[vertex]){
        if(child == par) continue;
        depth[child] = depth[vertex] + 1;
        dfst(child, vertex);
        height[vertex] = max(height[vertex], height[child]+1);
    }
}



ll subTreeSum[N];
ll subTreeEvenCnt[N];
// SubTreeSum of lower nodes and SubTreeEvenCnt number of even nodes in lower nodes
void dfsSubtree(ll vertex, ll par=0){
    if(vertex % 2 == 0){
        subTreeEvenCnt[vertex]++;
    }
    subTreeSum[vertex] += vertex;
    for(ll child: g[vertex]){
        if(child == par) continue;
        dfsSubtree(child, vertex);
        subTreeSum[vertex] += subTreeSum[child];
        subTreeEvenCnt[vertex] += subTreeEvenCnt[child];
    }
}



// Diameter of a Tree - longest path that exists between two nodes
void dfsDiameter(ll vertex, ll par=0){
    for(ll child: g[vertex]){
        if(child == par) continue;
        depth[child] = depth[vertex] + 1;
        dfsDiameter(child, vertex);
    }
}
/*dfsDiameter(1);
    ll max_diameter = -1;
    ll max_dia_node;
    for(ll i=1; i<=n; i++){
        if(max_diameter < depth[i]){
            max_diameter = depth[i];
            max_dia_node = i;
        }
        depth[i] = 0;
    }
    dfsDiameter(max_dia_node);
    max_diameter = -1;
    for(ll i=1; i<=n; i++){
        if(max_diameter < depth[i]){
            max_diameter = depth[i];
            max_dia_node = i;
        }
        depth[i] = 0;
    }
    cout << max_diameter << endl;*/




ll parent[N];
// This finds the Least Common Ancestor of any two nodes
// Alternative Optimized algo name - Binary Uptlifting
void dfsLCA(ll vertex, ll par=-1){
    parent[vertex] = par;
    for(ll child: g[vertex]){
        if(child == par) continue;
        dfsLCA(child, vertex);
    }
}
vector<ll> path(ll x){
    vector<ll> ans;
    while(x != -1){
        ans.push_back(x);
        x = parent[x];
    }
    reverse(all(ans));
    return ans;
}
/*dfsLCA(1);
ll x, y;
cin >> x >> y;
vector<ll> pathX = path(x), pathY = path(y);
ll lca = -1;
for(int i=0; i<MIN2(pathX.size(), pathY.size()); i++){
    if(pathX[i] == pathY[i]) lca = pathX[i];
    else break;
}
cout << lca << endl;*/




// Edge Deletion Problem - requires Precomputation of SubTreeSum of each node
const int mod = 1e9 + 7;
// fill val of each node from input
ll val[N];
void dfsEdgeDelPrecom(ll vertex, ll par=0){
    subTreeSum[vertex] += val[vertex];
    for(ll child: g[vertex]){
        if(child == par) continue;
        dfsEdgeDelPrecom(child, vertex);
        subTreeSum[vertex] += subTreeSum[child]; 
    }
}
/*dfsEdgeDelPrecom(1, 0);
ll ans = 0;
for(int i=2; i<=n; i++){
    int part1 = subTreeSum[i];
    int part2 = subTreeSum[1] - part1;
    ans = max(ans, (part1 * 1LL * part2));
}
cout << ans%mod << endl;*/





ll col[N];
// Checking whether a graph is bipartite or not, Building Teams - CSES
bool dfsBipartite(ll vertex, ll color) {
    vis[vertex] = 1;
    col[vertex] = color;

    for(ll child: g[vertex]) {
        if(!vis[child]) {
            if(!dfsBipartite(child, color ^ 1)) {
                return false;
            }
        }
        else if(col[vertex] == col[child]){
            return false;
        }
    }
    return true;
}
/*  dfsBipartite(1, 0);

    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            if(!dfsBipartite(i, 0)){
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }
    for(int i=1; i<=n; i++) {
        if(col[i] == 1) cout << 1 << " ";
        else cout << 2 << " ";
    }
    cout << endl;
*/



void solve(){
 
    ll n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        ll v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    

    
    

    
   



    
    

    

 
 
 
}
 




int main() {
    fastio();
    // ll t;
    // cin >> t;
    // while(t--){
    //     solve();
    // }
    solve();
    
    
    return 0;
}
