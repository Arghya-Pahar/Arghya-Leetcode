class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>,vector<string>> bigmap;
        for(int i=0;i<strs.size();i++)
        {
            string val=strs[i];
            vector<string> store;
            store.push_back(val);
            map<char,int> smallmap;
            for(int j=0;j<val.size();j++)
            {
                smallmap[val[j]]++;
            }
            if(bigmap.find(smallmap)==bigmap.end())
            {
                bigmap.insert({smallmap,store});
            }
            else
            {
                bigmap[smallmap].push_back(val);
            }
        }
        vector<vector<string>> ans;
        for(auto i=bigmap.begin();i!=bigmap.end();i++)
        {
            ans.push_back(i->second);
        }
        return ans;
        
        
    }
};