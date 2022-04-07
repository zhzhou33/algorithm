/*
 * @Author: zhzhou33
 * @Date: 2022-04-07 13:14:25
 * @LastEditors: zhzhou33
 * @LastEditTime: 2022-04-07 17:29:56
 */
#include <iostream>
#include <vector>
using namespace std;

//有向图
class Graph
{
public:
    Graph(vector<bool> &v, vector<bool> &p, vector<int> &f) : visit(v), path(p), father(f), hasCricle(false) {}
    ~Graph() {}
    //拓扑DFS
    void topuDFS(vector<vector<int>> &graph, int target)
    {
        //存在环
        if (path[target])
        {
            hasCricle = true;
            // print Circle
            int temp = target;
            while (target != father[temp])
            {
                cout << temp << "-";
                temp = father[temp];
            }
            cout << temp << endl;
            return;
        }
        if (hasCricle || visit[target])
            return;
        path[target] = true;
        visit[target] = true;
        // preOrder
        for (auto &val : graph[target])
        {
            father[val] = target;
            topuDFS(graph, val);
        }
        path[target] = false;
        // postOrder
        cout << target << endl;
    }

    void topuDFS2(vector<vector<int>> &graph, int target)
    {
        // preOrder
        visit1[target] = 1;
        for (auto &val : graph[target])
        {
            if (visit1[val] == 2)
                continue;
            // 有环
            // father[target] != val 针对无向图如果 val 是 target 的父节点则不是环
            // 因为 target 是 val 的父节点
            // 有向图则不需要,出现了这种情况就是存在环
            if (visit1[val] == 1 && father[target] != val)
            {
                hasCricle = true;
                // print Circle
                int temp = target;
                while (temp != val)
                {
                    cout << temp << "<->";
                    temp = father[temp];
                }
                cout << temp << endl;
                return;
            }
            else if (visit1[val] == 0)
            {
                father[val] = target;
                topuDFS2(graph, val);
                if (hasCricle)
                    return;
            }
        }
        visit1[target] = 2;
        // postOrder
        //拓扑排序
        cout << target << endl;
    }
    //环检测算法, 出度 /入度
    void
    topuBFS(vector<vector<int>> &graph)
    {
        //入度为 0 的入队,与之关联的节点入度 -1,依次BFS
        //存在环的节点不会入队
    }

private:
    vector<bool> visit;
    vector<int> visit1;
    vector<bool> path;
    //并查集UFS里的数组
    vector<int> father;
    bool hasCricle;
};

int main()
{
    vector<vector<int>> nums = {{1, 2}, {0, 3}, {0, 3}, {1, 2, 4}, {3}};
    vector<bool> visit(nums.size(), false), path(nums.size(), false);
    vector<int> father(nums.size(), -1);
    vector<int> visit1(nums.size(), 0);
    Graph *g = new Graph(visit, path, father);
    g->topuDFS(nums, nums.size() - 1);
}