class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
        for(int i=0;i<points.size();i++)
        {
            que.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],i});
        }
        int i=0;
        int n=que.size();
        while(i<n && i<k )
        {
            //cout<<i<<" ";
            ans.push_back(points[que.top().second]);
            que.pop();
            i++;
        }
        return ans;
    }
};