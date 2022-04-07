/*
 * @Author: zhzhou33
 * @Date: 2022-04-02 15:52:20
 * @LastEditors: zhzhou33
 * @LastEditTime: 2022-04-02 15:52:21
 */
#include <vector>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v = 0, TreeNode *l = nullptr, TreeNode *r = nullptr) : val(v), left(l), right(r) {}
};

class SerializeTree
{
public:
    SerializeTree() {}
    ~SerializeTree() {}
    string preOrderSerialize(TreeNode *root);
    pair<TreeNode *, int> preOrderDeserialize(vector<string> &str, int start = 0);

    string postOrderSerialize(TreeNode *root);
    pair<TreeNode *, int> postOrderDeserialize(vector<string> &str, int end);

    string levelOrderSerialize(TreeNode *root);
    TreeNode *levelOrderDeserialize(vector<string> &str);
    vector<string> split(string str, char c = ',');
};

string SerializeTree::preOrderSerialize(TreeNode *root)
{
    if (!root)
        return "#";
    return to_string(root->val) + "," + preOrderSerialize(root->left) + "," + preOrderSerialize(root->right);
}

vector<string> SerializeTree::split(string str, char c)
{
    vector<string> res;
    string temp = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
            res.push_back(temp);
            temp = "";
        }
        else
            temp += str[i];
    }
    if (temp != "")
        res.push_back(temp);
    return res;
}
// preOrder
// pair<node,endIndex>
pair<TreeNode *, int> SerializeTree::preOrderDeserialize(vector<string> &str, int start)
{
    if (str[start] == "#")
        return {nullptr, start};
    TreeNode *root = new TreeNode(stoi(str[start]));
    auto left = preOrderDeserialize(str, start + 1);
    auto right = preOrderDeserialize(str, left.second + 1);
    root->left = left.first;
    root->right = right.first;
    return {root, right.second};
}
// postOrder
// pair<node,startIndex>
pair<TreeNode *, int> SerializeTree::postOrderDeserialize(vector<string> &str, int end)
{
    if (str[end] == "#")
        return {nullptr, end};

    auto right = postOrderDeserialize(str, end - 1);
    auto left = postOrderDeserialize(str, right.second - 1);

    TreeNode *root = new TreeNode(stoi(str[end]));
    root->left = left.first;
    root->right = right.first;
    return {root, left.second};
}

string SerializeTree::postOrderSerialize(TreeNode *root)
{
    return root ? postOrderSerialize(root->left) + "," + postOrderSerialize(root->right) + "," + to_string(root->val) : "#";
}

string SerializeTree::levelOrderSerialize(TreeNode *root)
{
    queue<TreeNode *> q;
    string res = "";
    if (root)
        q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (!node)
                res += ",#";
            else
            {
                res += (res == "" ? "" : ",") + to_string(node->val);
                q.push(node->left);
                q.push(node->right);
            }
        }
    }
    return res;
}

TreeNode *SerializeTree::levelOrderDeserialize(vector<string> &str)
{
    if (str.empty() || str[0] == "#")
        return nullptr;
    TreeNode *root = new TreeNode(stoi(str[0]));
    queue<TreeNode *> q;
    q.push(root);
    int index = 1;
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (str[index] != "#")
            {
                node->left = new TreeNode(stoi(str[index]));
                q.push(node->left);
            }
            index++;
            if (str[index] != "#")
            {
                node->right = new TreeNode(stoi(str[index]));
                q.push(node->right);
            }
            index++;
        }
    }
    return root;
}

int main()
{
    SerializeTree *st = new SerializeTree();
    auto res = st->split("1,2,#,4,#,#,3,#,#");
    auto tree = st->preOrderDeserialize(res);
    auto str = st->preOrderSerialize(tree.first);
    cout << str << endl;

    auto post_res = st->split("#,#,#,4,2,#,#,3,1");
    tree = st->postOrderDeserialize(post_res, post_res.size() - 1);
    str = st->postOrderSerialize(tree.first);
    cout << str << endl;

    auto level_res = st->split("1,2,3,#,4,#,#,#,#");
    TreeNode *root = st->levelOrderDeserialize(level_res);
    str = st->levelOrderSerialize(root);
    cout << str << endl;

    return 0;
}