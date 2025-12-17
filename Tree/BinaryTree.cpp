#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <math.h>
using namespace std;

class DDLNode
{
public:
    int data;
    DDLNode *prev;
    DDLNode *next;

    DDLNode(int data, DDLNode *prev, DDLNode *next)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
    DDLNode(int data)
    {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val, Node *left, Node *right)
    {
        this->val = val;
        this->right = right;
        this->left = left;
    }
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Traversal
{
public:
    vector<Node *> createTree(int val)
    {
        vector<Node *> rootArr;

        Node *root1 = new Node(val);
        Node *n2 = new Node(2);
        Node *n3 = new Node(3);
        Node *n4 = new Node(4);
        Node *n5 = new Node(5);
        Node *n6 = new Node(6);
        Node *n7 = new Node(7);
        Node *n8 = new Node(8);
        Node *n9 = new Node(9);
        Node *n10 = new Node(10);
        Node *n11 = new Node(11);

        Node *root2 = new Node(val);
        Node *n22 = new Node(2);
        Node *n33 = new Node(3);
        Node *n44 = new Node(4);
        Node *n55 = new Node(5);
        // Node *n6 = new Node(6);
        // Node *n7 = new Node(7);
        // Node *n8 = new Node(8);
        // Node *n9 = new Node(9);
        // Node *n10 = new Node(10);
        // Node *n11 = new Node(11);
        root1->left = n2;
        root1->left->left = n4;
        root1->left->left->right = n5;
        Node *node5 = root1->left->right = n10;
        node5->left = n8;
        node5->right = n9;
        Node *node3 = root1->right = n3;
        node3->left = n6;
        node3->right = n7;
        node3->right->left = n11;

        root2->left = n22;
        root2->left->left = n44;
        Node *node55 = root2->left->right = n33;
        Node *node33 = root2->right = n55;
        // node5->left = n6;
        // node5->left->left = n7;
        // node3->right = n8;
        // node3->right->right = n9;
        // node3->right->right->right = n10;
        // node3->right->right->right->right = n11;
        rootArr.push_back(root1);
        rootArr.push_back(root2);
        return rootArr;
    }
    void PrintTree(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->val << " ";
        PrintTree(root->left);
        PrintTree(root->right);
    }

    int Height(Node *root)
    {

        if (root == NULL)
        {
            return 0;
        }

        return 1 + max(Height(root->left), Height(root->right));
    }

    int NodeCount(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        return 1 + NodeCount(root->left) + NodeCount(root->right);
    }

    int leftMaxHeight(Node *root, int count, int &leftHeight)
    {
        if (root == NULL)
        {
            return leftHeight - 1;
        }
        leftHeight = max(count, leftHeight);
        leftMaxHeight(root->left, count + 1, leftHeight);
        leftMaxHeight(root->right, count + 1, leftHeight);
    }
    int rightMaxHeight(Node *root, int count, int &rightHeight)
    {
        if (root == NULL)
        {
            return rightHeight - 1;
        }
        rightHeight = max(count, rightHeight);
        rightMaxHeight(root->left, count + 1, rightHeight);
        rightMaxHeight(root->right, count + 1, rightHeight);
    }

    int Diameter(Node *root)
    {
        int leftHeight = 1;
        int rightHeight = 1;
        return leftMaxHeight(root, 1, leftHeight) + rightMaxHeight(root, 1, rightHeight) - 1;
    }

    vector<int> EveryNodeDiameter(Node *root, vector<int> &arr)
    {
        if (root == NULL)
        {
            return arr;
        }

        EveryNodeDiameter(root->left, arr);
        int leftheight = 1;
        int rightheight = 1;
        int resultDiameter = leftMaxHeight(root, 1, leftheight) + rightMaxHeight(root, 1, rightheight) - 1;
        arr.push_back(resultDiameter);
        EveryNodeDiameter(root->right, arr);
    }

    void MirrorTree(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        swap(root->left, root->right);
        MirrorTree(root->left);
        MirrorTree(root->right);
    }

    bool CheckIdentical(Node *root1, Node *root2)
    {
        if (root1 == NULL && root2 == NULL)
        {
            return true;
        }
        if (root1 == NULL || root2 == NULL)
        {
            return false;
        }
        if (root1->val != root2->val)
        {
            return false;
        }

        return CheckIdentical(root1->left, root2->left) && CheckIdentical(root1->right, root2->right);
    }

    void BreathFirstSearch(Node *root)
    {
        if (root == NULL)
            return;
        queue<Node *> queueOfNode;
        queueOfNode.push(root);
        vector<vector<int>> arr;

        while (!queueOfNode.empty())
        {
            int levelSize = queueOfNode.size();
            vector<int> level;

            for (int i = 0; i < levelSize; i++)
            {
                Node *currentNode = queueOfNode.front();
                queueOfNode.pop();
                level.push_back(currentNode->val);
                if (currentNode->left)
                {

                    queueOfNode.push(currentNode->left);
                }
                if (currentNode->right)
                {
                    queueOfNode.push(currentNode->right);
                }
            }
            arr.push_back(level);
        }

        for (int i = 0; i < arr.size(); i++)
        {
            cout << "[ ";
            for (int j = 0; j < arr.at(i).size(); j++)
            {

                cout << arr[i].at(j) << ", ";
            }
            cout << " ]";
        }
    }
    void ReverseBFS(Node *root)
    {
        if (root == NULL)
            return;
        queue<Node *> queueOfNode;
        stack<int> st;

        queueOfNode.push(root);

        while (!queueOfNode.empty())
        {
            int levelSize = queueOfNode.size();

            for (int i = 0; i < levelSize; i++)
            {
                Node *currentNode = queueOfNode.front();
                queueOfNode.pop();
                st.push(currentNode->val);
                if (currentNode->right)
                {

                    queueOfNode.push(currentNode->right);
                }
                if (currentNode->left)
                {
                    queueOfNode.push(currentNode->left);
                }
            }
        }
        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
    }
    vector<vector<int>> ZigZagTraversal(Node *root)
    {

        vector<vector<int>> level;
        if (root == NULL)
            return level;

        bool flag = true;

        queue<Node *> NodeQueue;
        NodeQueue.push(root);

        while (!NodeQueue.empty())
        {
            int queueSize = NodeQueue.size();
            vector<int> tempLevel;

            for (int i = 0; i < queueSize; i++)
            {
                Node *frontNode = NodeQueue.front();
                NodeQueue.pop();
                tempLevel.push_back(frontNode->val);
                if (flag)
                {
                    if (frontNode->left)
                    {
                        NodeQueue.push(frontNode->left);
                    }
                    if (frontNode->right)
                    {
                        NodeQueue.push(frontNode->right);
                    }
                    flag = false;
                }
                else
                {

                    if (frontNode->right)
                    {
                        NodeQueue.push(frontNode->right);
                    }
                    if (frontNode->left)
                    {
                        NodeQueue.push(frontNode->left);
                    }
                    flag = true;
                }
            }

            level.push_back(tempLevel);
        }

        for (int i = 0; i < level.size(); i++)
        {
            cout << "[ ";
            for (int j = 0; j < level[i].size(); j++)
            {
                cout << level[i].at(j) << " ";
            }
            cout << " ]";
        }
    }

    vector<int> LeftBoundary(Node *root, vector<int> &arrNode)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return arrNode;
        }

        arrNode.push_back(root->val);

        if (root->left != NULL)
        {

            return LeftBoundary(root->left, arrNode);
        }
        else
        {
            return LeftBoundary(root->right, arrNode);
        }
    }
    vector<int> RightBoundary(Node *root, vector<int> &arrNode)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return arrNode;
        }

        arrNode.push_back(root->val);

        if (root->right != NULL)
        {
            return RightBoundary(root->right, arrNode);
        }
        else
        {
            return RightBoundary(root->left, arrNode);
        }
    }
    vector<int> LeafeNodes(Node *root, vector<int> &arrNode)
    {

        if (root == NULL)
        {
            return arrNode;
        }

        queue<Node *> NodeQueue;
        NodeQueue.push(root);

        while (!NodeQueue.empty())
        {
            int queueSize = NodeQueue.size();
            for (int i = 0; i < queueSize; i++)
            {
                Node *currentNode = NodeQueue.front();
                NodeQueue.pop();

                if (currentNode->left == NULL && currentNode->right == NULL)
                {
                    arrNode.push_back(currentNode->val);
                }

                if (currentNode->left != NULL)
                {
                    NodeQueue.push(currentNode->left);
                }
                if (currentNode->right != NULL)
                {
                    NodeQueue.push(currentNode->right);
                }
            }
        }
        return arrNode;
    }
    void BoundaryTraversal(Node *root)
    {

        vector<int> arrNode;
        LeftBoundary(root, arrNode);
        LeafeNodes(root, arrNode);
        RightBoundary(root->right, arrNode);

        for (int i = 0; i < arrNode.size(); i++)
        {
            cout << arrNode[i] << " ";
        }
    }

    void VerticalTraversal(Node *root, int column, map<int, vector<int>> &nodemap)
    {

        if (root == NULL)
        {
            return;
        }

        int nodeValue = root->val;
        auto it = nodemap.find(column);
        if (it != nodemap.end())
        {
            it->second.push_back(nodeValue);
        }
        else
        {
            vector<int> temp;
            temp.push_back(nodeValue);
            nodemap.insert({column, temp});
        }

        VerticalTraversal(root->left, column - 1, nodemap);
        VerticalTraversal(root->right, column + 1, nodemap);
    }
};

class RootToLeaf
{
public:
    bool TargetPathSum2(Node *root, int target, int path_sum)
    {
        if (root == NULL)
        {
            if (path_sum == target)
            {
                return true;
            }
            return false;
        }

        bool ans = TargetPathSum2(root->left, target, path_sum + root->val);
        if (ans)
        {
            return ans;
        }
        bool ans2 = TargetPathSum2(root->right, target, path_sum + root->val);
        if (ans2)
        {
            return ans2;
        }
    }
    bool TargetPathSum(Node *root, int path_sum, int &target_path_sum, bool &status, int &maximum_path_sum)
    {
        if (root == NULL)
        {
            return status;
        }

        // cout<<"path_sum_pernode = "<<path_sum<<"Node Val = "<<root->val<<endl;
        TargetPathSum(root->left, path_sum + root->val, target_path_sum, status, maximum_path_sum);

        if (root->left == NULL && root->right == NULL)
        {

            // cout<<"path_sum = "<<path_sum<<endl;
            int result = path_sum + root->val;
            maximum_path_sum = max(result, maximum_path_sum);
            //    cout<<"Result = "<<result<<endl;
            if (result == target_path_sum)
            {

                status = true;
                return status;
            }
            // cout<<"Maximum = "<<maximum_path_sum<<endl;
        }
        TargetPathSum(root->right, path_sum + root->val, target_path_sum, status, maximum_path_sum);
    }

    void SumOfLeftChild(Node *root, int &left_sum)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->left != NULL)
        {
            cout << "SUm = " << left_sum << endl;
            left_sum += root->left->val;

            SumOfLeftChild(root->left, left_sum);
        }
        SumOfLeftChild(root->right, left_sum);
    }

    int SumOfLeftLeaves(Node *root, int &left_sum)
    {

        if (root == NULL)
        {
            return left_sum;
        }
        if (root->left != NULL)
        {

            if (root->left->left == NULL && root->left->right == NULL)
            {
                left_sum = left_sum + root->left->val;
                cout << "Left_Sum = " << left_sum << endl;
            }
        }
        SumOfLeftLeaves(root->left, left_sum);

        SumOfLeftLeaves(root->right, left_sum);
    }
    int SumOfAllLeaves(Node *root, int &leaves_sum)
    {

        if (root == NULL)
        {
            // cout<<" AYA"<<endl;
            return leaves_sum;
        }

        SumOfAllLeaves(root->left, leaves_sum);
        if (root->left == NULL && root->right == NULL)
        {
            leaves_sum = leaves_sum + root->val;
            // cout << "Left_Sum = " << leaves_sum << endl;
        }
        SumOfAllLeaves(root->right, leaves_sum);
    }

    void LeftViewOfTree(Node *root, int &max_height, int height)
    {

        if (root == NULL)
        {
            return;
        }

        if (height > max_height)
        {
            cout << root->val << " ";
            max_height = max(height, max_height);
        }

        LeftViewOfTree(root->left, max_height, height + 1);
        LeftViewOfTree(root->right, max_height, height + 1);
    }

    bool childrenSum(Node *root, bool &status)
    {

        if (root == NULL || !status)
        {
            return status;
        }

        int rootVal = root->val;
        int childrenVal = ((root->left ? root->left->val : 0) + (root->right ? root->right->val : 0));
        bool check = rootVal != childrenVal;
        if (root->left == NULL && root->right == NULL)
        {
            return status;
        }

        else
        {
            if (check)
            {
                status = false;
                cout << rootVal << " - " << childrenVal << " status " << status << endl;
                return status;
            }
        }
        childrenSum(root->left, status);
        childrenSum(root->right, status);
        return status;
    }

    bool IsTreeBalamced(Node *root, bool &status)
    {
        Traversal tv;
        if (root == NULL || !status)
        {

            return status;
        }

        int left_height = 0;
        int right_height = 0;
        left_height = tv.leftMaxHeight(root, 0, left_height);
        right_height = tv.rightMaxHeight(root, 0, right_height);

        int check = abs(left_height - right_height);

        if (check > 1)
        {
            status = false;
            return status;
        }

        IsTreeBalamced(root->left, status);
        IsTreeBalamced(root->right, status);
        return status;
    }

    // vector<map<Node*,vector<int>>> (Node* root){
    //      if(root == NULL){
    //         return;
    //      }
};

class BST
{
public:
    Node *insertNodeInBst(Node *root, int val)
    {

        if (root == NULL)
        {
            new Node(val);
        }

        if (val < root->val)
        {
            root->left = insertNodeInBst(root->left, val);
        }
        else if (val > root->val)
        {
            root->right = insertNodeInBst(root->right, val);
        }

        return root;
    }
    // Node *InsertNode(Node *root, int val)
    // {
    //     if (root == NULL)
    //     {
    //         return new Node(val);
    //     }

    //     if (val > root->val)
    //     {
    //         root->right = InsertNode(root->right, val);
    //     }
    //     else
    //     {
    //         root->left = InsertNode(root->left, val);
    //     }
    //     return root;
    // }
    Node *ArrayToBstByRecursion(vector<int> arr)
    {
        Node *root = insertNodeInBst(NULL, arr[0]);

        for (int i = 1; i < arr.size(); i++)
        {
            insertNodeInBst(root, arr[i]);
        }
        return root;
    }
    Node *ArrayToBST(vector<int> arr)
    {
        Node *root = new Node(arr[0]);

        for (int i = 1; i < arr.size(); i++)
        {
            Node *temproot = root;

            Node *newNode = new Node(arr[i]);

            while (temproot != NULL)
            {
                if (newNode->val > temproot->val)
                {
                    if (temproot->right == NULL)
                    {
                        temproot->right = newNode;
                        break;
                    }
                    temproot = temproot->right;
                }
                else
                {
                    if (temproot->left == NULL)
                    {
                        temproot->left = newNode;
                        break;
                    }
                    temproot = temproot->left;
                }
            }
        }
        return root;
    }
    Node *CreateBST(int val)
    {
        Node *root = new Node(val);
        Node *tn3 = new Node(3);
        Node *tn2 = new Node(2);
        Node *tn5 = new Node(5);
        Node *tn7 = new Node(7);
        Node *tn8 = new Node(8);
        Node *tn13 = new Node(13);
        Node *tn20 = new Node(20);
        Node *tn30 = new Node(30);
        Node *tn25 = new Node(25);
        Node *tn29 = new Node(29);
        Node *tn50 = new Node(50);
        Node *tn70 = new Node(70);
        Node *tn75 = new Node(75);
        Node *tn80 = new Node(80);

        root->left = tn7;
        Node *node5 = root->left->left = tn5;
        node5->left = tn3;
        node5->left->left = tn2;

        root->right = tn30;
        root->right->left = tn20;
        root->right->left->right = tn25;
        root->right->left->right->right = tn29;
        root->right->left->left = tn13;
        root->right->right = tn50;
        root->right->right->right = tn80;
        root->right->right->right->left = tn70;
        root->right->right->right->left->right = tn75;

        return root;
    }

    void LevelOrderTraversalBST(Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        vector<vector<int>> levelOrder;
        queue<Node *> nodeQueue;

        nodeQueue.push(root);

        while (!nodeQueue.empty())
        {
            vector<int> level;
            int size = nodeQueue.size();

            for (int i = 0; i < size; i++)
            {

                Node *temp = nodeQueue.front();
                nodeQueue.pop();
                level.push_back(temp->val);

                if (temp->left)
                {
                    nodeQueue.push(temp->left);
                }
                if (temp->right)
                {
                    nodeQueue.push(temp->right);
                }
            }
            levelOrder.push_back(level);
        }
        for (int i = 0; i < levelOrder.size(); i++)
        {

            for (int j = 0; j < levelOrder.at(i).size(); j++)
            {
                cout << levelOrder.at(i).at(j) << " ";
            }
        }
    }

    Node *InsertInBST(Node *root, Node *insertNode)
    {
        if (root == NULL)
        {
            return insertNode;
        }

        if (root->val > insertNode->val)
        {

            root->left = InsertInBST(root->left, insertNode);
        }
        else if (root->val < insertNode->val)
        {

            root->right = InsertInBST(root->right, insertNode);
        }
        return root;
    }

    bool searchInBst(Node *root, int target)
    {
        if (root == NULL)
        {
            cout << "come here ";
            return false;
        }

        if (target > root->val)
        {
            return searchInBst(root->right, target);
        }
        else if (target < root->val)
        {
            return searchInBst(root->left, target);
        }
        else
        {
            return true;
        }
    }
    // void SearchInBST(Node *root, int target, bool &status)
    // {
    //     if (root == NULL)
    //     {
    //         return;
    //     }

    //     if (target == root->val)
    //     {
    //         status = true;
    //         return;
    //     }
    //     else if (target > root->val)
    //     {
    //         SearchInBST(root->right, target, status);
    //     }
    //     else
    //     {
    //         SearchInBST(root->left, target, status);
    //     }
    // }

    // Node *DeleteLeafNodeInBST(Node *root, int delete_node)
    // {

    //     if (root == NULL)
    //     {

    //         return root;
    //     }

    //     if (root->val < delete_node)
    //     {
    //         root->right = DeleteLeafNodeInBST(root->right, delete_node);
    //     }
    //     else if (root->val > delete_node)
    //     {
    //         root->left = DeleteLeafNodeInBST(root->left, delete_node);
    //     }
    //     else
    //     {
    //         if (!root->left && !root->right)
    //         {
    //             return NULL;
    //         }
    //     }
    // }
    Node *deleteLeafNodeInBst(Node *root, int delete_node)
    {

        if (root == NULL)
        {
            root;
        }

        if (delete_node > root->val)
        {
            root->right = deleteLeafNodeInBst(root->right, delete_node);
        }

        else if (delete_node < root->val)
        {
            root->left = deleteLeafNodeInBst(root->left, delete_node);
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                return NULL;
            }
        }
        return root;
    }
    Node *InOrderSuccessor(Node *root)
    {
        Node *currentNode = root;

        while (root != NULL)
        {
            root = root->right;
            if (root != NULL)
            {

                currentNode = root;
            }
        }
        return currentNode;
    }
    Node *PreOrderSuccessor(Node *root)
    {
        Node *currentNode = root;
        if (root == NULL)
        {
            return currentNode;
        }

        while (root != NULL)
        {
            root = root->left;
            if (root != NULL)
            {
                currentNode = root->left;
            }
        }
        return currentNode;
    }
    int successorOfTree(Node* root){
        if(root->left == NULL){
            return root->val;
        }

        return successorOfTree(root->left);

    }
    Node *deleteNode(Node *root, int delete_node)
    {

        if (root == NULL)
        {
            return root;
        }

        if (delete_node > root->val)
        {
            root->right = deleteNode(root->right, delete_node);
        }
        else if (delete_node < root->val)
        {
            root->left = deleteNode(root->left, delete_node);
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                return NULL;
            }
            else if(root->left != NULL && root->right == NULL){
                return root->left;
            }
            else if(root->left == NULL && root->right != NULL){
                return root->right;
            }
            else{
                int successor = successorOfTree(root->right);
                root->val = successor;
                root->right = deleteNode(root->right,successor);
            }
        }
        return root;
    }

    Node *DeleteNode(Node *root, int delete_node)
    {

        if (root == NULL)
        {
            return root;
        }

        if (root->val > delete_node)
        {
            root->left = DeleteNode(root->left, delete_node);
        }
        else if (root->val < delete_node)
        {

            root->right = DeleteNode(root->right, delete_node);
        }
        else
        {
            if (!root->left && !root->right)
            {
                return NULL;
            }
            else if (root->left != NULL && root->right == NULL)
            {
                return root->left;
            }
            else if (root->left == NULL && root->right != NULL)
            {
                return root->right;
            }
            else
            {

                Node *Successor = InOrderSuccessor(root->left);
                root->val = Successor->val;
                root->left = DeleteNode(root->left, Successor->val);
                return root;
            }
        }
        return root;
    }
    bool Valid(Node *root, int minVal, int maxVal)
    {
        if (root == NULL)
            return true;

        if (root->val <= minVal || root->val >= maxVal)
        {
            return false;
        }
        return Valid(root->left, minVal, root->val) && Valid(root->right, root->val, maxVal);
    }
    bool CheckValidBST(Node *root, bool &status)
    {
        status = Valid(root, INT8_MIN, INT8_MAX);
        return status;
    }

    Node *LCA(Node *root, Node *p, Node *q)
    {
        if (root == NULL)
        {
            return root;
        }

        if (root->val > p->val && root->val > q->val)
        {
            return LCA(root->left, p, q);
        }
        if (root->val < p->val && root->val < q->val)
        {
            return LCA(root->right, p, q);
        }

        return root;
    }

    int Floor(Node *root, int target)
    {
        if (root == NULL)
            return 0;

        Node *current = root;
        int floorVal = -1;

        while (current != NULL)
        {
            if (current->val == target)
                return target;

            if (current->val < target)
            {
                floorVal = current->val;
                current = current->right;
            }
            else
            {
                current = current->left;
            }
        }
        return floorVal;
    }

    Node *kthSmallest(Node *root, int &k)
    {

        if (root == NULL)
        {
            return root;
        }

        Node *ans = kthSmallest(root->left, k);

        if (ans)
        {
            return ans;
        }

        if (k == 1)
        {
            return root;
        }
        else
        {
            k--;
        }
        Node *ans2 = kthSmallest(root->right, k);
        if (ans2)
        {
            return ans2;
        }
    }

    // Node *KthSmallest(Node *root, int &k)
    // {
    //     if (root == NULL)
    //         return root;

    //     Node *leftans = KthSmallest(root->left, k);

    //     if (leftans != NULL)
    //         return leftans;

    //     if (k == 0)
    //         return root;
    //     k--;

    //     Node *rightans = KthSmallest(root->right, k);
    //     if (rightans != NULL)
    //         return rightans;
    // }

    Node *kthLargest(Node *root, int &k)
    {
        if (root == NULL)
        {
            return root;
        }

        Node *rightans = kthLargest(root->right, k);
        if (rightans != NULL)
        {
            return rightans;
        }

        k--;
        if (k == 0)
        {
            return root;
        }
        Node *leftans = kthLargest(root->left, k);
        if (leftans != NULL)
        {

            return leftans;
        }
    }

    void BSTtoDDL(Node *root, DDLNode *&head, DDLNode *&tail)
    {

        if (root == NULL)
        {
            return;
        }

        BSTtoDDL(root->left, head, tail);

        if (head == NULL)
        {
            DDLNode *headnode = new DDLNode(root->val);
            head = headnode;
            tail = head;
        }
        else
        {

            DDLNode *tempNode = new DDLNode(root->val);
            tail->next = tempNode;
            tempNode->prev = tail;
            tail = tempNode;
        }
        BSTtoDDL(root->right, head, tail);
    }
};

int main()
{
    Traversal tv;
    RootToLeaf rtl;
    BST bst;
    vector<Node *> roots = tv.createTree(1);
    Node *root1 = roots[0];
    int k = 7;
    Node *root2 = bst.CreateBST(10);
    bst.LevelOrderTraversalBST(root2);
    Node *rootAfterDeletion = bst.deleteNode(root2, 20);
    cout << endl;
    bst.LevelOrderTraversalBST(rootAfterDeletion);

    return 0;
}