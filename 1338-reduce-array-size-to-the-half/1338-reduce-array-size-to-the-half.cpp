class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        map<int,int> mp;
        priority_queue<int,vector<int>,less<int>> que;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            que.push(it->second);
        }
        int count=0;
        int k=0;
        while(k<n/2)
        {
            k+=que.top();
            //cout<<que.top()<<" ";
            count++;
            que.pop();
        }
        return count;
    }
};