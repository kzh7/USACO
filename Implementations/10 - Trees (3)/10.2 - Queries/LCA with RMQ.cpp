/**
 * Description: Euler Tour LCA w/ O(1) query
 * Source: own
 * Verification: Debug the Bugs
 * Dependency: RMQ
 */

template<int SZ> struct LCA {
    int N, R = 1;
    vi adj[SZ];

    int depth[SZ], pos[SZ];
    vpi tmp;
    RMQ<pi,2*SZ> r;

    void addEdge(int u, int v) { adj[u].pb(v), adj[v].pb(u); }

    void dfs(int u, int prev){
        pos[u] = sz(tmp); depth[u] = depth[prev]+1;
        tmp.pb({depth[u],u});
        trav(v,adj[u]) if (v != prev) {
            dfs(v, u);
            tmp.pb({depth[u],u});
        }
    }

    void init(int _N) {
    	N = _N; dfs(R, 0);
        r.build(tmp);
    }

    int lca(int u, int v){
        u = pos[u], v = pos[v]; if (u > v) swap(u,v);
        return r.query(u,v).s;
    }

    int dist(int u, int v) {
        return depth[u]+depth[v]-2*depth[lca(u,v)];
    }
};
