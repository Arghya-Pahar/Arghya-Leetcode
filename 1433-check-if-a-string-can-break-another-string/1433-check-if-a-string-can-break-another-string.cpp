class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        bool check1=true;
        bool check2=true;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]<s2[i])
            {
                check1=false;
            }
            if(s2[i]<s1[i])
            {
                check2=false;
            }
        }
        return check1 || check2;
    }
};