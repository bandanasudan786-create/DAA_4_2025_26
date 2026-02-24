#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    class DSU {
    public:
        vector<int> parent, rank;
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        
        void unite(int x, int y) {
            int rx = find(x);
            int ry = find(y);
            if (rx == ry) {
                return;
            }
            if (rank[rx] < rank[ry]) {
                swap(rx, ry);
            }
            parent[ry] = rx;
            if (rank[rx] == rank[ry]) {
                rank[rx]++;
            }
        }
    };

    int kruskalsMST(int V, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });
        
        DSU dsu(V);
        int minCost = 0;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            if (dsu.find(u) != dsu.find(v)) {
                dsu.unite(u, v);
                minCost += w;
            }
        }
        return minCost;
    }
};
