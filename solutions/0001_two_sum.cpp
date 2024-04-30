#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> result;
        for(int i = 0; i<nums.size(); ++i){
            int complement = target - nums[i];
            if(map.find(complement) != map.end()){
                result.push_back(map[complement]);
                result.push_back(i);
                break;
            }
            map[nums[i]] = i;
        }

        return result;
    }
};