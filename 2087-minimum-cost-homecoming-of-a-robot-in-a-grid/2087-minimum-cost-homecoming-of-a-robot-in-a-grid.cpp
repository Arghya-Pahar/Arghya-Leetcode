class Solution {
public:
    int minCost(vector<int>& startpos, vector<int>& homepos, vector<int>& rowCost, vector<int>& colCost) {
        int cost=0;
        if(startpos[0]<=homepos[0])
        {
            for(int i=startpos[0]+1;i<=homepos[0];i++)
            {
                cost+=rowCost[i];
            }
        }
        else
        {
            for(int i=startpos[0]-1;i>=homepos[0];i--)
            {
                cost+=rowCost[i];
            }
            
        }
        if(startpos[1]<=homepos[1])
        {
            for(int i=startpos[1]+1;i<=homepos[1];i++)
            {
                cost+=colCost[i];
            }
        }
        else
        {
            for(int i=startpos[1]-1;i>=homepos[1];i--)
            {
             
                cost+=colCost[i];
            }
            
        }
        return cost;
        
    }
};