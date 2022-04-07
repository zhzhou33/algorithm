/*
 * @Author: zhzhou33
 * @Date: 2022-04-01 09:35:37
 * @LastEditors: zhzhou33
 * @LastEditTime: 2022-04-01 11:21:38
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define M 10000

void adjustHeap(vector<int> &nums, int start, int end)
{
    int father = start;
    int child = 2 * start + 1;
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

void HeapSort(vector<int> &nums)
{
    //从最后一个父节点开始adjust
    for (int i = nums.size() / 2 - 1; i >= 0; i--)
        adjustHeap(nums, i, nums.size() - 1);
    for (int i = nums.size() - 1; i > 0; i--)
    {
        swap(nums[i], nums[0]);
        adjustHeap(nums, 0, i - 1);
    }
}

//单源最短路径
// start at 1
void dijkstra(vector<vector<int>> &nums, int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
    pq.push({start, 0});
    vector<int> res(nums.size(), M);
    vector<bool> visit(nums.size(), false);
    res[start] = 0;
    while (!pq.empty())
    {
        auto node = pq.top();
        pq.pop();
        int pointIndex = node.first;
        visit[pointIndex] = true;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!visit[i] && res[i] > res[pointIndex] + nums[pointIndex][i])
            {
                res[i] = res[pointIndex] + nums[pointIndex][i];
                pq.push({i, res[i]});
            }
        }
    }
    for (auto &val : res)
        cout << val << " ";
    cout << endl;
}

void Floyd(vector<vector<int>> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            for (int k = 0; k < nums.size(); k++)
            {
                nums[j][k] = min(nums[j][k], nums[j][i] + nums[i][k]);
            }
        }
    }
    for (auto &v : nums)
    {
        for (int &val : v)
            cout << val << " ";
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> nums = {{0, 1, 1, 1, M, M},
                                {1, 0, 1, M, M, M},
                                {1, 1, 0, 1, M, 1},
                                {1, M, 1, 0, 1, M},
                                {M, M, M, 1, 0, M},
                                {M, M, 1, M, M, 0}};
    for (int i = 0; i < nums.size(); i++)
        dijkstra(nums, i);
    cout << "==============================" << endl;
    Floyd(nums);
    cout << "==============================" << endl;

    vector<int> sortNums = {5, 6, 1, 4, 8, 9};
    HeapSort(sortNums);
    for (auto &val : sortNums)
        cout << val << " ";
    cout << endl;
}