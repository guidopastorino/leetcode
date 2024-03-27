/*
  La complejidad de tiempo de esta solución es O(n), ya que solo necesitamos recorrer la matriz una vez.
  La complejidad de espacio es O(n) debido al uso del mapa hash para almacenar los números y sus índices.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target){
  std::unordered_map<int, int> map;
  std::vector<int> result;

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

int main(){
  std::vector<int> nums = {1,2,3,4};
  int target = 3;
  std::vector<int> res = twoSum(nums, target);

  for(int n : res){
    std::cout << n << " ";
  }

  return 0;
}