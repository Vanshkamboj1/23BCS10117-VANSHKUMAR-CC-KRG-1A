class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n+1);

        for(int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v, w});
        }

        vector<int> dis(n+1, INT_MAX);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0, k});
        dis[k] = 0;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int currDist = top.first;
            int node = top.second;

            if(currDist > dis[node]) continue;

            for(auto neigh : adj[node]){
                int next = neigh.first;
                int weight = neigh.second;

                if(currDist + weight < dis[next]){
                    dis[next] = currDist + weight;
                    pq.push({dis[next], next});
                }
            }
        }

        int ans = 0;

        for(int i=1;i<=n;i++){
            if(dis[i]==INT_MAX) 
                return -1;
            ans = max(ans,dis[i]);
        }

        return ans;
    }
};