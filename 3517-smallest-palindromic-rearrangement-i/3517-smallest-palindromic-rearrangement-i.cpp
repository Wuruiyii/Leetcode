class Solution {
public:
    string smallestPalindrome(string s)
    {
        int size = s.size();
        vector<int> v(26,0);
        for(int i = 0;i < size / 2;i++)
        {
           v[s[i]-'a']++;
        }
        int index = 0;
        string ans(size,' ');
        for(int i = 0;i < 26;i++)
        {
             for(int j = 0;j < v[i];j++)
            {
                ans[index++] = i + 'a'; 
            }
        }
        if(size % 2) ans[index++]=s[size/2];
        for(int i = 25;i >= 0;i--)
        {
            for(int j = 0;j < v[i];j++)
            {
                ans[index++] = i + 'a'; 
            }
        }
        return ans;
    }
};