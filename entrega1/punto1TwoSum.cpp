#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
public:
    // Solución optimizada O(n) usando hash map
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map; // valor -> índice

        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];

            // Si el complemento existe en el map, encontramos la solución
            if (map.find(complement) != map.end())
            {
                return {map[complement], i};
            }

            // Guardamos el número actual y su índice
            map[nums[i]] = i;
        }

        return {}; // No debería llegar aquí según las restricciones
    }
};

int main()
{
    Solution sol;

    // Ejemplo 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = sol.twoSum(nums1, target1);
    cout << "Ejemplo 1: [" << result1[0] << ", " << result1[1] << "]" << endl;

    // Ejemplo 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = sol.twoSum(nums2, target2);
    cout << "Ejemplo 2: [" << result2[0] << ", " << result2[1] << "]" << endl;

    // Ejemplo 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> result3 = sol.twoSum(nums3, target3);
    cout << "Ejemplo 3: [" << result3[0] << ", " << result3[1] << "]" << endl;

    return 0;
}