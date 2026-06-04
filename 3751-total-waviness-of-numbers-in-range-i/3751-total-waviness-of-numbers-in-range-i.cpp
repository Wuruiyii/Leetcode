class Solution 
{
public:
    int totalWaviness(int num1, int num2) 
    {
        int total = 0;
        for(int i = num1;i <= num2;i++)
        {
            string s = to_string(i);
            int len = s.size();
            if(len >= 3)
            {
                for(int j = 1;j < s.size()-1;j++)
                {
                    if(((s[j]-'0') > (s[j-1]-'0') && (s[j]-'0') > (s[j+1]-'0')) || ((s[j]-'0') < (s[j-1]-'0') && (s[j]-'0') < (s[j+1]-'0')))
                     total++;
                }
            }
        }
        return total;
    }
};