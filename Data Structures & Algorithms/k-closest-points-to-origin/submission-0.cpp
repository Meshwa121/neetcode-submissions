class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;
        for(int i=0; i<points.size(); i++){
            pq.push({points[i][0]*points[i][0] + points[i][1]*points[i][1], {points[i][0], points[i][1]}});
        }

        while(pq.size()>k){
            pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            pair<int, int> p= pq.top().second;
            ans.push_back({p.first, p.second});
            pq.pop();
        }
        return ans;
    }
};
