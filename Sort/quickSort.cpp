/*
 * @Author: zhzhou33
 * @Date: 2022-04-06 14:46:16
 * @LastEditors: zhzhou33
 * @LastEditTime: 2022-04-06 14:57:15
 */
#include <vector>
#include <iostream>
using namespace std;

void quickSort(vector<int> &nums, int low, int high)
{
    if (low >= high)
        return;
    int l = low, h = high;
    while (l < h)
    {
        while (l < h && nums[h] >= nums[low])
            h--;
        while (l < h && nums[l] <= nums[low])
            l++;
        swap(nums[l], nums[h]);
    }
    swap(nums[low], nums[l]);
    quickSort(nums, low, l - 1);
    quickSort(nums, l + 1, high);
}

void quickSort(vector<int> &nums)
{
    quickSort(nums, 0, nums.size() - 1);
    for (const int &val : nums)
        cout << val << " ";
    cout << endl;
}

//基于快排的数组划分方法
void quickSort(vector<int> &nums, int k, int low, int high)
{
    if (low >= high)
        return;
    int l = low, h = high;
    while (l < h)
    {
        while (l < h && nums[h] >= nums[low])
            h--;
        while (l < h && nums[l] <= nums[low])
            l++;
        swap(nums[l], nums[k]);
    }

    swap(nums[low], nums[l]);
    if (l < k)
        quickSort(nums, k, l + 1, high);
    else if (l > k)
        quickSort(nums, k, low, l - 1);
    // l == k
    else
    {
        // TODO
    }
}
int main()
{
    vector<int> nums = {4, 5, 1, 6, 7, 0, 9};
    quickSort(nums);
    return 0;
}