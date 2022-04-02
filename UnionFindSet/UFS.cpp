/*
 * @Author: zhzhou33
 * @Date: 2022-04-01 17:39:12
 * @LastEditors: zhzhou33
 * @LastEditTime: 2022-04-01 19:17:45
 */
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class UnionFindSet
{
public:
    UnionFindSet() {}
    ~UnionFindSet() {}
    void init(vector<vector<int>> &input_set);
    int find(int x);
    int merge(int a, int b);

private:
    // first = child,second = father
    unordered_map<int, int> child_father;
};

int UnionFindSet::find(int x)
{
    if (x == child_father[x])
        return x;
    child_father[x] = find(child_father[x]);
    return child_father[x];
}

int UnionFindSet::merge(int a, int b)
{
    child_father[a] = find(child_father[b]);
    return child_father[a];
}

void UnionFindSet::init(vector<vector<int>> &input_set)
{
    // n 个关系集合
    for (const auto &vec : input_set)
    {
        // 每个关系集合的处理,指定一个中心,其他所有的都需要指向这个中心
        // 指定中心 vec[0]
        int father = vec[0];
        for (const int &val : vec)
        {
            if (child_father.count(val) == 0)
                child_father[val] = father;
            else
            {
                father = merge(father, child_father[val]);
            }
        }
    }
    for (auto iter = child_father.begin(); iter != child_father.end(); ++iter)
    {
        cout << iter->first << "->" << find(iter->second) << endl;
    }
}

int main()
{
    UnionFindSet *ufs = new UnionFindSet();
    vector<vector<int>> nums = {{1, 2, 3}, {4, 5}, {6, 7}, {4, 6}};
    ufs->init(nums);
}