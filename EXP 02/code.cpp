class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) return n;

        int ans = 0;

        for(int i = 0; i < n; i++) {
            map<pair<int,int>, int> mp;
            int dup = 1;

            for(int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                if(x1 == x2 && y1 == y2) {
                    dup++;
                    continue;
                }

                int dx = x2 - x1;
                int dy = y2 - y1;

                int g = __gcd(dx, dy);
                dx /= g;
                dy /= g;

                mp[{dx, dy}]++;
            }

            int maxi = 0;
            for(auto &it : mp) {
                maxi = max(maxi, it.second);
            }

            ans = max(ans, maxi + dup);
        }

        return ans;
    }
};