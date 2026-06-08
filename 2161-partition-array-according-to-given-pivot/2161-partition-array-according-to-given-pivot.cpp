class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        vector<int> small,equal,big;
        for(int i = 0;i < nums.size();i++)
        {
              if(pivot > nums[i]) small.push_back(nums[i]);
              else if(pivot < nums[i]) big.push_back(nums[i]);
              else equal.push_back(nums[i]);
        }
        small.insert(small.end(),equal.begin(),equal.end());
        small.insert(small.end(),big.begin(),big.end());
        return small;
    }
};