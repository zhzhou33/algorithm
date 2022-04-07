/*
 * @Author: zhzhou33
 * @Date: 2022-04-06 14:58:21
 * @LastEditors: zhzhou33
 * @LastEditTime: 2022-04-06 15:14:21
 */
#include <vector>
#include <iostream>
using namespace std;

//大根堆
void adjustHeap(vector<int> &nums, int start, int end)
{
    int father = start;
    int child = father * 2 + 1;
    while (child <= end)
    {
        if (child + 1 <= end && nums[child] < nums[child + 1])
            child++;
        if (nums[father] > nums[child])
            return;
        swap(nums[father], nums[child]);
        father = child;
        child = 2 * father + 1;
    }
}
void heapSort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        adjustHeap(nums, i, nums.size() - 1);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(nums[i], nums[0]);
        adjustHeap(nums, 0, i - 1);
    }
}

class priority_queue
{
};

int main()
{
    vector<int> nums = {4, 5, 1, 8, 9, 0};
    heapSort(nums);
    for (const int &val : nums)
        cout << val << " ";
    cout << endl;
    return 0;
}