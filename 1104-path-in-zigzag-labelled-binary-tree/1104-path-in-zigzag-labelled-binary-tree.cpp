class Solution {
public:
    vector<int> pathInZigZagTree(int n) {
        vector<int> ans;
        int llv=1;
        int cv=0;
        while(cv<n)
        {
            cv+=llv;
            llv=llv*2;
        }
        llv=llv/2;
        while(n!=1)
        {
            ans.push_back(n);
            int comp=(3*llv-n-1);
            n=comp/2;
            llv=llv/2;
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};