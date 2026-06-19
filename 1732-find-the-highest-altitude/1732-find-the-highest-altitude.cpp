class Solution 
{
public:
    int largestAltitude(vector<int>& gain) 
    {
        int m = INT_MIN;
        int s = 0;
        for(int i = 0;i < gain.size();i++)
        {
            s += gain[i];
            if(s > m) m = s;
        }
        if(m < 0) return 0;
        else return m;
    }
};