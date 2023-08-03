class Solution {
public:
    int minJumps(vector<int>& arr) {
        map<int,vector<int>> mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]].push_back(i);
        }
        queue<int> que;
        vector<bool> vis(arr.size(),false);
        que.push(0);
        vis[0]=true;
        int level=0;
        while(que.size()!=0)
        {
            int n=que.size();
            level++;
            while(n--)
            {
                int elem=que.front();
                que.pop();
                vector<int> &nextt=mp[arr[elem]];
                nextt.push_back(elem+1);
                nextt.push_back(elem-1);
                for(int i=0;i<nextt.size();i++)
                {
                    if( nextt[i]>=0 && nextt[i]<arr.size() && vis[nextt[i]]==false )
                    {
                        que.push(nextt[i]);
                        vis[nextt[i]]=true;
                        if(nextt[i]==arr.size()-1)
                        {
                            return level;
                        }
                       
                    }
                }
                mp[arr[elem]].clear();

            }
        }
        return 0;
    }
};