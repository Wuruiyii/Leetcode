class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) 
    {
        const long long INF = 1e18;
        
        // 1. 邻接表存储（保留原逻辑）
        vector<vector<pair<int, long long>>> adj(n);
        for (auto& e : edges)
        {
            int u = e[0];    // 改用int更合理（节点编号是int）
            int v = e[1];
            long long w = e[2];
            adj[u].emplace_back(v, w);     // 正向边：u→v，权w
            adj[v].emplace_back(u, 2 * w); // 反转边：v→u，权2w（原逻辑）
        }

        // 2. 距离数组：初始化为无穷大，起点0的距离为0
        vector<long long> min_dist(n, INF);
        min_dist[0] = 0; 

        // 3. 优先队列（最小堆）：存储 (当前距离, 节点)，按距离升序排列
        // 注意：C++优先队列默认是最大堆，需用greater<>改为最小堆
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.emplace(0, 0); // 起点入堆

        // 4. 优先队列版Dijkstra核心逻辑
        while (!pq.empty())
        {
            // 取出当前距离最小的节点
            auto [cur_cost, cur] = pq.top();
            pq.pop();

            // 剪枝：当前状态是过时的（已有更短路径），直接跳过
            if (cur_cost > min_dist[cur])
                continue;

            // 遍历当前节点的所有邻接边
            for (auto& edge : adj[cur])
            {
                int next = edge.first;    // 邻接节点
                long long w = edge.second;// 边权
                // 计算新距离，更新最短路径
                if (min_dist[cur] + w < min_dist[next])
                {
                    min_dist[next] = min_dist[cur] + w;
                    // 新状态入堆（即使next已入堆，后续会通过剪枝跳过无效状态）
                    pq.emplace(min_dist[next], next);
                }
            }
        }

        // 5. 返回结果：不可达返回-1，否则返回最短距离
        return min_dist[n - 1] == INF ? -1 : (int)min_dist[n - 1];
    }
};