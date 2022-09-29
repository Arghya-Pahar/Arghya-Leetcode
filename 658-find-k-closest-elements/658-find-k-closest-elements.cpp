class comp{
    public:
    bool operator()(const pair<int,int> &a,const pair<int,int> &b)
    {
        if(a.second==b.second)
        {
            return a.first<b.first;
        }
        return a.second<b.second;
    }
};
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue <pair<int,int>,vector<pair<int,int>>,comp> pq;
        vector<int> ans;
        for(int i=0;i<arr.size();i++)
        {
            int ab=abs(arr[i]-x);
            if(pq.size()<k)
            {
                pq.push({arr[i],ab});
            }
            else
            {
                if(ab<pq.top().second)
                {
                    pq.pop();
                    pq.push({arr[i],ab});
                }
                else if(ab==pq.top().second)
                {
                    if(arr[i]<pq.top().first)
                    {
                        pq.pop();
                        pq.push({arr[i],ab});
                        
                    }
                }
                
            }
            
        }
        while(!pq.empty())
        {
            ans.push_back(pq.top().first);
            pq.pop();
            
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};