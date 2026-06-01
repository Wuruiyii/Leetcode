class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int mini = 0;
        int j = cost.size()-1;
        int cnt = 0;
        while(j >= 0)
        { 
            if(cnt==2) 
            {
                j--;
                cnt=0;
            }
            else
            {
                mini+=cost[j];
                j--;
                cnt++;
            }
           
        }
        return mini;
    }
};