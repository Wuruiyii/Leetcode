class Solution {
public:
    string smallestPalindrome(string s)
    {
        int size = s.size();
        sort(s.begin(),s.begin()+size/2);
        sort(s.begin()+size/2+size%2,s.end(),greater<char>());
        return s;
    }
};