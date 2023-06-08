/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bruteForce(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }

    vector<int> optimizedApproach(vector<int> &nums, int target)
    {
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++)
        {
            int second_number = target - nums[i];
            if (seen.find(second_number) != seen.end())
            {
                return {i, seen[second_number]};
            }
            else
            {
                seen[nums[i]] = i;
            }
        }
        return {-1, -1};
    }
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // return bruteForce(nums, target);
        return optimizedApproach(nums, target);
    }
};
// @lc code=end
