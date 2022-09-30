class Solution {
public:
    int largestarea(vector<int> &heights)
    {
       stack<int> st;
        stack<int> st1;
        st.push(heights.size()-1);
        st1.push(0);
        int nsr[heights.size()];
        int nsl[heights.size()];
        nsr[heights.size()-1]=heights.size();
        nsl[0]=-1;
        for(int i=heights.size()-2;i>=0;i--)
        {
            while(st.size()!=0 && heights[i]<=heights[st.top()])
            {
                st.pop();
            }
            if(st.size()==0)
            {
                nsr[i]=heights.size();
            }
            else
            {
                nsr[i]=st.top();
            }
            st.push(i);
            
        }
        for(int i=1;i<heights.size();i++)
        {
            while(st1.size()!=0 && heights[i]<=heights[st1.top()])
            {
                st1.pop();
            }
            if(st1.size()==0)
            {
                nsl[i]=-1;
            }
            else
            {
                nsl[i]=st1.top();
                
            }
            st1.push(i);
        }
        int maxi=INT_MIN;
        for(int i=0;i<heights.size();i++)
        {
            int area=abs((nsr[i]-nsl[i]-1)*heights[i]);
            maxi=max(maxi,area);
            
        }
        return maxi;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> heights(matrix[0].size(),0);
        int area=INT_MIN;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]=='1')
                {
                    heights[j]+=1;
                }
                else
                {
                    heights[j]=0;
                }
            }
            for(int f=0;f<heights.size();f++)
            {
                cout<<heights[f]<<" ";
            }
            cout<<endl;
            int k=largestarea(heights);
            area=max(area,k);
        }
        return area;
    }
};