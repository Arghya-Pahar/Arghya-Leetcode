class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,vector<string>> mp;
        int m=beginWord.size();
        for(int i=0;i<wordList.size();i++)
        {
            string str=wordList[i];
            for(int j=0;j<str.size();j++)
            {
                string x=str.substr(0,j)+"*"+str.substr(j+1,m-j-1);
                mp[x].push_back(str);
            }
        }
        string str=beginWord;
        for(int j=0;j<m;j++)
        {
            string x=str.substr(0,j)+"*"+str.substr(j+1,m-j-1);
            mp[x].push_back(str);
        }
        set<string> visited;
        queue<string> que;
        que.push(beginWord);
        visited.insert(beginWord);
        int level=1;
        while(que.size()!=0)
        {
            int n=que.size();
            level++;
            while(n--)
            {
                string str=que.front();
                for(int j=0;j<m;j++)
                {
                    string x=str.substr(0,j)+"*"+str.substr(j+1,m-j-1);
                    vector<string> v=mp[x];
                    for(int i=0;i<v.size();i++)
                    {
                        if(visited.find(v[i])==visited.end())
                        {
                            que.push(v[i]);
                            visited.insert(v[i]);
                        }
                        if(v[i]==endWord)
                            return level;
                    }
                }
                que.pop();
            }
        }
        return 0;
    }
};