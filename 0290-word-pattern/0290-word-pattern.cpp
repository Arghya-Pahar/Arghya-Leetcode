class Solution {
public:
    bool wordPattern(string p, string s) {
        map<char,string> mp1;
        map<string,char> mp2;
        vector<string> words;
        istringstream ss(s);
        string word;
        while (ss >> word)
        {
            words.push_back(word);
        }
        if(words.size()!=p.size())
            return false;
        for(int i=0;i<p.size();i++)
        {
            mp1.insert({p[i],words[i]});
            mp2.insert({words[i],p[i]});
        }
        for(int i=0;i<p.size();i++)
        {
            if(mp1[p[i]]!=words[i] || mp2[words[i]]!=p[i])
                return false;
        }
        return true;
    }
};