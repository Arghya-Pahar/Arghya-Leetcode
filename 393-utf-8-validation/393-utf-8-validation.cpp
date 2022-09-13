class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int rmbytes=0;
        for(int i=0;i<data.size();i++)
        {
            if(rmbytes==0)
            {
                if((data[i]>>7)==0)
                {
                    rmbytes=0;
                }
                else if((data[i]>>5)==6)
                {
                    rmbytes=1;
                }
                else if((data[i]>>4)==14)
                {
                    rmbytes=2;
                }
                else if((data[i]>>3)==30)
                {
                    rmbytes=3;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if((data[i]>>6)==2)
                {
                    rmbytes--;
                }
                else
                {
                    return false;
                }
            }
            
        }
        if(rmbytes==0)
            return true;
        else
            return false;
        
    }
};