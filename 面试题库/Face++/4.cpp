// leetcode 452. Minimum Number of Arrows to Burst Balloons
//
#define fi first
#define se second
typedef pair<int, int> pii;
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        priority_queue<pii, vector<pii>, greater<pii>>pq;
        while(!pq.empty())pq.pop();
        int n = points.size();
        for(int i = 0; i < n; ++i){
            int l = points[i].fi, r = points[i].se;
            pq.push({r, l});
        }
        int res = 0;
        while(!pq.empty()){
            pii tmp = pq.top();
            pq.pop();
            while(!pq.empty()){
                if(tmp.fi < pq.top().se)break;
                pq.pop();
            }
            res ++;
        }
        return res;
    }
};
