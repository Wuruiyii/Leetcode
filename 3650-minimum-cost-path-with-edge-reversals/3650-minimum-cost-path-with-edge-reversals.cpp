class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        // 邻接表：2n个节点（每个节点拆为未使用/已使用开关两个状态）
        vector<vector<pair<int, int>>> adj(2 * n);
        
        // 1. 添加原始正向边
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            // u0 -> v0，代价w（未使用开关的u到未使用开关的v）
            adj[2 * u].emplace_back(2 * v, w);
            // u1 -> v0，代价w（已使用开关的u到未使用开关的v）
            adj[2 * u + 1].emplace_back(2 * v, w);
        }
        
        // 2. 添加反转边（处理每个节点的入边）
        for (auto& e : edges) {
            int v = e[0], u = e[1], w = e[2]; // 原边v→u是u的入边
            // u0 -> v0，代价2w（激活u的开关，反转入边并遍历）
            adj[2 * u].emplace_back(2 * v, 2 * w);
        }
        
        // 距离数组：用long long避免溢出，初始为无穷大
        vector<long long> dist(2 * n, LLONG_MAX);
        dist[0] = 0; // 起点是0号节点的未使用开关状态（编号0）
        
        // 优先队列（最小堆）：存储（当前代价，节点编号）
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.emplace(0, 0);
        
        // Dijkstra算法核心
        while (!pq.empty()) {
            auto [cur_cost, u] = pq.top();
            pq.pop();
            
            // 剪枝：当前代价已大于已知最短距离，无需处理
            if (cur_cost > dist[u]) continue;
            
            // 遍历所有邻接边
            for (auto& [v, w] : adj[u]) {
                long long new_cost = cur_cost + w;
                // 更新最短距离并加入队列
                if (new_cost < dist[v]) {
                    dist[v] = new_cost;
                    pq.emplace(new_cost, v);
                }
            }
        }
        
        // 终点是n-1，取其两个状态的最小值
        long long res = min(dist[2*(n-1)], dist[2*(n-1)+1]);
        return res == LLONG_MAX ? -1 : res;
    }
};