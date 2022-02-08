#include <bits/stdc++.h>

using namespace std;

struct edge {
    int v, w, idx;
    edge() {}
    edge(int _v, int _w, int _idx): v(_v), w(_w), idx(_idx) {}
};

const int N = 100005, L = 22;
int test, vertex;
vector < edge > G[N];
int table[L][N], depth[N], tree[N << 2], two[L];
int chainNo, chainHead[N], chainSize[N];
int nodeInWhichChain[N], indexInBaseArray[N];
int BaseArray[N], indexNo, edgeIndex[N], subtreeSize[N];

void dfs(int u = 1, int par = -1, int level = 0) {
    table[0][u] = par; 
    depth[u] = level;
    subtreeSize[u] = 1;
    for (int i = 0; i < (int) G[u].size(); i++) {
        int v = G[u][i].v;
        if (v != par) {
            dfs(v, u, level + 1);
            subtreeSize[u] += subtreeSize[v];
        }
    }
}

void sparseTable() {
    for (int i = 1; two[i] <= vertex; i++) {
        for (int j = 1; j <= vertex; j++) {
            if (table[i - 1][j] != -1) {
                table[i][j] = table[i - 1][table[i - 1][j]];
            }
        }
    }
}

void hld(int node = 1, int par = -1, int cost = 0) {
    indexNo++;
    indexInBaseArray[node] = indexNo;
    BaseArray[indexNo] = cost;
    if (chainHead[chainNo] == -1) chainHead[chainNo] = node;
    nodeInWhichChain[node] = chainNo;
    chainSize[chainNo]++;
    int specialChild = -1, maxSubtreeSize = -1;
    int specialCost, specialIndex;

    for (int i = 0; i < (int) G[node].size(); i++) {
        int v = G[node][i].v, w = G[node][i].w;
        int idx = G[node][i].idx;
        if (v != par && subtreeSize[v] > maxSubtreeSize) {
            maxSubtreeSize = subtreeSize[v];
            specialChild = v, specialCost = w;
            specialIndex = idx;
        }
    }

    if (specialChild != -1) {
        edgeIndex[specialIndex] = indexNo + 1;
        hld(specialChild, node, specialCost);
    }

    for (int i = 0; i < (int) G[node].size(); i++) {
        int v = G[node][i].v, w = G[node][i].w;
        int idx = G[node][i].idx;
        if (v != par && v != specialChild) {
            chainNo++;
            edgeIndex[idx] = indexNo + 1;
            hld(v, node, w);
        }
    }
}

void build(int lo = 1, int hi = vertex, int node = 1) {
    if (lo == hi) {
        tree[node] = BaseArray[lo];
        return;
    }
    int mid = (lo + hi) / 2, l = node << 1, r = l | 1;
    build(lo, mid, l);
    build(mid + 1, hi, r);
    tree[node] = max(tree[l], tree[r]);
}

void modify(int id, int v, int lo = 1, int hi=vertex,int node= 1) {
    if (lo == hi && lo == id) {
        tree[node] = v;
        return;
    }
    int mid = (lo + hi) / 2, l = node << 1, r = l | 1;
    if (id <= mid) modify(id, v, lo, mid, l);
    else modify(id, v, mid + 1, hi, r);
    tree[node] = max(tree[l], tree[r]);
}

int get(int x, int y, int lo = 1, int hi = vertex, int node = 1) {
    if (lo > hi || y < lo || hi < x) return 0;
    if (x <= lo && hi <= y) return tree[node];
    int mid = (lo + hi) / 2, l = node << 1, r = l | 1;
    int le = get(x, y, lo, mid, l);
    int ri = get(x, y, mid + 1, hi, r);
    return max(le, ri);
}

void build_hld() {
    indexNo = 0, chainNo = 1;
    for (int i = 1; i <= vertex; i++) {
        chainHead[i] = -1;
        chainSize[i] = -1;
    }
    for (int i = 0; two[i] <= vertex; i++) {
        for (int j = 1; j <= vertex; j++)
            table[i][j] = -1;
    }
    dfs();
    sparseTable();
    hld();
    build();
}

int lca(int x, int y) {
    if (x == y) return x;
    if (depth[x] < depth[y]) swap(x, y);
    for (int i = 20; i >= 0; i--) {
        if (depth[x] - two[i] >= depth[y])
            x = table[i][x];
    }
    if (x == y) return x;
    for (int i = 20; i >= 0; i--) {
        if (table[i][x] != table[i][y] && table[i][x] != -1) {
            x = table[i][x];
            y = table[i][y];
        }
    }
    return table[0][x];
}

int hldQuery(int u, int v) {
    int ret = 0;
    while (true) {
        if (nodeInWhichChain[u] == nodeInWhichChain[v]) {
            int L = indexInBaseArray[u];
            int R = indexInBaseArray[v];
            if (L < R) ret = max(ret, get(L + 1, R));
            return ret;
        }
        int head = chainHead[nodeInWhichChain[v]];
        int L = indexInBaseArray[head];
        int R = indexInBaseArray[v];
        ret = max(ret, get(L, R));
        v = table[0][head];
    }
}

int query(int x, int y) {
    int l = lca(x, y);
    return max(hldQuery(l, x), hldQuery(l, y));
}

void update(int i, int val) {
    modify(edgeIndex[i], val);
}

int main() {
    scanf("%d", & test);
    two[0] = 1;
    for (int i = 1; i <= 20; i++)
        two[i] = two[i - 1] << 1;
    while (test--) {
        scanf("%d", & vertex);
        for (int i = 1; i <= vertex - 1; i++) {
            int x, y, z;
            scanf("%d %d %d", & x, & y, & z);
            G[x].push_back(edge(y, z, i));
            G[y].push_back(edge(x, z, i));
        }
        build_hld();
        char str[10];
        while (scanf(" %s", str) && str[0] != 'D') {
            int x, y;
            scanf("%d %d", & x, & y);
            if (str[0] == 'Q') {
                printf("%d\n", query(x, y));
            } else {
                update(x, y);
            }
        }
        for (int i = 1; i <= vertex; i++) {
            G[i].clear();
        }
    }
}
