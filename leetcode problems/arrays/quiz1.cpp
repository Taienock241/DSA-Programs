/* You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1]. */
#include <iostream>
#include <utility>
using namespace std;

pair<int, int> findIndexes(const int nums[], int size, int target) {
for(int i = 0; i < size; i++) {
    for(int j = i + 1; j < size; j++) {
        if(nums[i] + nums[j] == target) {
            return {i, j};
        }
    }
}
  return {-1, -1};
}

int main() {
int nums[] = {2, 7, 11, 15};
int target = 13;
int size = sizeof(nums) / sizeof(nums[0]);
pair<int, int> indexes = findIndexes(nums, size, target);

cout << "[" << indexes.first << ", " << indexes.second << "]" << endl;
return 0;
}