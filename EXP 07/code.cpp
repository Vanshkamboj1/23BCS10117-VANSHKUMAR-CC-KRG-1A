class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto &it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n, INT_MAX);
        queue<pair<int, pair<int,int>>> q;

        q.push({src, {0, 0}});
        dist[src] = 0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int node = it.first;
            int stops = it.second.first;
            int cost = it.second.second;

            if(stops > k) continue;

            for(auto &nbr : adj[node]){
                int next = nbr.first;
                int price = nbr.second;

                if(cost + price < dist[next] && stops <= k){
                    dist[next] = cost + price;
                    q.push({next, {stops + 1, cost + price}});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};