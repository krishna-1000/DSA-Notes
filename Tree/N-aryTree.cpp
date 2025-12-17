#include <iostream>
#include <queue>
#include<unordered_map>
#include <vector>
using namespace std;

int preStart = 0;
class Node
{
public:
    int val;
    vector<Node *> children;

    Node(int value)
    {
        this->val = value;
        this->children = {};
    }
};

class Ntree
{
public:
    Node *createTree()
    {

        Node *n1 = new Node(1);
        Node *n2 = new Node(2);
        Node *n3 = new Node(3);
        Node *n4 = new Node(4);
        Node *n5 = new Node(5);
        Node *n6 = new Node(6);
        Node *n7 = new Node(7);
        Node *n8 = new Node(8);

        n1->children.push_back(n2);
        n1->children.push_back(n3);
        n1->children.push_back(n4);
        n3->children.push_back(n5);
        n5->children.push_back(n6);
        n6->children.push_back(n7);
        n6->children.push_back(n8);

        return n1;
    }

    vector<vector<int>> LevelOrderTraversal(Node *root)
    {

        vector<vector<int>> AllLevels;
        queue<Node *> NodeQueue;

        NodeQueue.push(root);

        while (!NodeQueue.empty())
        {
            vector<int> level;
            int qsize = NodeQueue.size();

            for (int i = 0; i < qsize; i++)
            {
                Node *currentNode = NodeQueue.front();
                NodeQueue.pop();
                level.push_back(currentNode->val);

                int childrenSize = currentNode->children.size();

                for (int j = 0; j < childrenSize; j++)
                {
                    NodeQueue.push(currentNode->children[j]);
                }
            }

            AllLevels.push_back(level);
        }
        for (int i = 0; i < AllLevels.size(); i++)
        {
            cout << "[ ";
            for (int j = 0; j < AllLevels.at(i).size(); j++)
            {

                cout << AllLevels[i].at(j) << " ";
            }
            cout << " ]";
            cout << endl;
        }

        return AllLevels;
    }

    void HeightOfNTree(Node *root, int &maxDepth, int count)
    {
        if (root == NULL)
        {
            return;
        }
        maxDepth = max(maxDepth, count);
        for (int i = 0; i < root->children.size(); i++)
        {
            HeightOfNTree(root->children[i], maxDepth, count + 1);
        }

        return;
    }
    int CountNodes(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int TotalCount = 1;
        for (Node *child : root->children)
        {

            TotalCount += CountNodes(child);
        }

        return TotalCount;
    }

    int maxHeight(Node *root)
    {

        int maxDepth = 0;

        for (int i = 0; i < root->children.size(); i++)
        {
            maxDepth = max(maxHeight(root->children[i]), maxDepth);
        }

        return maxDepth + 1;
    }

   
};
int main()
{
    Ntree nt;
    int maxdepth = 1;
    Node *root = nt.createTree();
    // nt.LevelOrderTraversal(root);
    // nt.HeightOfNTree(root,maxdepth,1);
    // cout << nt.CountNodes(root);
    cout << nt.maxHeight(root);
    // cout<<maxdepth;
    return 0;
}