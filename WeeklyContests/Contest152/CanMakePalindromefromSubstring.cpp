#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>
#define ll long long int

class Solution
{
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>> &q)
    {
        int n = s.length();
        vector<bool> v;                                    // Boolean Vector To store answers
        vector<vector<int>> dp(n + 1, vector<int>(26, 0)); // Dp vector to calculate the
        for (int i = 1; i <= n; i++)        // Store the frequency of each character 
        {
            dp[i][s[i - 1] - 'a']++;
        }
        for (int i = 1; i <= n; i++)        // add the previous character occurence to the current one
        {
            for (int j = 0; j < 26; j++)
            {
                dp[i][j] += dp[i - 1][j];
            }
        }

        for (int i = 0; i < q.size(); i++)
        {
            int x = 0;    // x is a variable to count the number of numbers which are not identical
            for (int j = 0; j < 26; j++)
            {
                if ((dp[q[i][1] + 1][j] - dp[q[i][0]][j]) % 2 != 0) 
                // dp[q[1]] stores the count of 'a' + i in 0 to q1 
                // dp[q[0]] stores the count of 'a' + i in 0 to q0 
                // subtraction of these 2 will result in the count of 'a' + i in q0 to q1 
                {
                    x++;
                }
            }
            v.push_back(x / 2 <= q[i][2]);   //     check if count of non identical numbers / 2 is less then or equal to required changes
        }
        return v;
    }
};

void testcase()
{
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    testcase();
    return 0;
}
