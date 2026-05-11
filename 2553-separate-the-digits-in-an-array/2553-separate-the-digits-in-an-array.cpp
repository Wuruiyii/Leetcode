class Solution {
public:
    vector<int> separateDigits(vector<int>& nums)
    {
        vector<int> ans;
        for(int i =  nums.size()-1;i >= 0;i--)
        {
            int temp = nums[i];
            while(temp > 0)
            {
                int t = temp % 10;
                ans.push_back(t);
                temp /= 10;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};