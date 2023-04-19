#include <bits/stdc++.h>
#define SPACE 10
using namespace std;
class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
    {
        value = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};
class BST
{
public:
    TreeNode *root;
    BST()
    {
        root = NULL;
    }
    bool isTreeEmpty()
    {
        if (root == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void insertNode(TreeNode *new_node)
    {
        if (root == NULL)
        {
            root = new_node;
            cout << "Value Inserted as root node." << endl;
        }
        else
        {
            TreeNode *temp = root;
            while (temp != NULL)
            {
                if (new_node->value == temp->value)
                {
                    cout << "Value already exists,insert another value." << endl;
                    return;
                }
                else if ((new_node->value < temp->value) && (temp->left == NULL))
                {
                    temp->left = new_node;
                    cout << "Value inserted to the left." << endl;
                    break;
                }
                else if (new_node->value < temp->value)
                {
                    temp = temp->left;
                }
                else if ((new_node->value > temp->value) && (temp->right == NULL))
                {
                    temp->right = new_node;
                    cout << "Value inserted to the right." << endl;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
    void print2D(TreeNode *r, int space)
    {
        if (r == NULL)
        {
            return;
        }
        space += SPACE;
        print2D(r->right, space);
        cout << endl;
        for (int i = SPACE; i < space; i++)
        {
            cout << " ";
        }
        cout << r->value << endl;
        print2D(r->left, space);
    }
    void printPreorder(TreeNode *r)
    {
        if (r == NULL)
        {
            return;
        }
        cout << r->value << " ";
        printPreorder(r->left);
        printPreorder(r->right);
    }
    void printInorder(TreeNode *r)
    {
        if (r == NULL)
        {
            return;
        }
        printInorder(r->left);
        cout << r->value << " ";
        printInorder(r->right);
    }
    void printPostorder(TreeNode *r)
    {
        if (r == NULL)
        {
            return;
        }
        printPostorder(r->left);
        printPostorder(r->right);
        cout << r->value << " ";
    }
    TreeNode *recursiveSearch(TreeNode *r, int val)
    {
        if (r == NULL || r->value == val)
        {
            return r;
        }
        else if (val < r->value)
        {
            return recursiveSearch(r->left, val);
        }
        else
        {
            return recursiveSearch(r->right, val);
        }
    }
    int height(TreeNode *r)
    {
        if (r == NULL)
        {
            return -1;
        }
        else
        {
            int lheight = height(r->left);
            int rheight = height(r->right);
            if (lheight > rheight)
            {
                return (lheight + 1);
            }
            else
            {
                return (rheight + 1);
            }
        }
    }
    void printGivenLevel(TreeNode *r, int level)
    {
        if (r == NULL)
        {
            return;
        }
        else if (level == 0)
        {
            cout << r->value << " ";
        }
        else
        {
            printGivenLevel(r->left, level - 1);
            printGivenLevel(r->right, level - 1);
        }
    }
    void printLevelOrderBFS(TreeNode *r)
    {
        int h = height(r);
        for (int i = 0; i <= h; i++)
        {
            printGivenLevel(r, i);
        }
    }
    TreeNode *minValueNode(TreeNode *node)
    {
        TreeNode *current = node;
        while (current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }
    TreeNode *deleteNode(TreeNode *r, int v)
    {
        if (r == NULL)
        {
            return NULL;
        }
        else if (v < r->value)
        {
            r->left = deleteNode(r->left, v);
        }
        else if (v > r->value)
        {
            r->right = deleteNode(r->right, v);
        }
        else
        {
            if (r->left == NULL)
            {
                TreeNode *temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL)
            {
                TreeNode *temp = r->left;
                delete r;
                return temp;
            }
            else
            {
                TreeNode *temp = minValueNode(r->right);
                r->value = temp->value;
                r->right = deleteNode(r->right, temp->value);
            }
        }
        return r;
    }
};
int main()
{
    BST obj;
    int choice, val;
    cout << " 1. Insert Node\n 2. Delete Node\n 3. Search Node\n 4. Display BST values\n 5. Height of Tree\n 6. DFS\n 7. BFS \n 8. Exit Program "<< endl;
        while (1)
    {
        cout << "Enter your choice: " << endl;
        cin >> choice;
        TreeNode *new_node = new TreeNode();
        switch (choice)
        {
        case 1:
            cout << "Enter value to insert in BST: ";
            cin >> val;
            new_node->value = val;
            obj.insertNode(new_node);
            cout << endl;
            break;
        case 2:
            cout << "Enter the value to delete in BST: ";
            cin >> val;
            new_node = obj.recursiveSearch(obj.root, val);
            if (new_node != NULL)
            {
                obj.deleteNode(obj.root, val);
                cout << "Value Deleted." << endl;
            }
            else
            {
                cout << "Value not found." << endl;
            }
            break;
        case 3:
            cout << "Enter value to search in BST: ";
            cin >> val;
            new_node = obj.recursiveSearch(obj.root, val);
            if (new_node != NULL)
            {
                cout << "Value found." << endl;
            }
            else
            {
                cout << "Value not found." << endl;
            }
            break;
        case 4:
            cout << "The BST is: " << endl;
            obj.print2D(obj.root, 5);
            cout << endl;
            break;
        case 5:
            cout << "BST Height: " << endl;
            cout << "Height : " << obj.height(obj.root) << endl;
            break;
        case 6:
            cout << "DFS of the BST :" << endl;
            cout << "PREORDER: ";
            obj.printPreorder(obj.root);
            cout << endl;
            cout << "INORDER: ";
            obj.printInorder(obj.root);
            cout << endl;
            cout << "POSTORDER: ";
            obj.printPostorder(obj.root);
            break;
        case 7:
            cout << "Print Level Order BFS: \n";
            obj.printLevelOrderBFS(obj.root);
            break;
        case 8:
            return 0;
        default:
            cout << "Invalid choice!!Enter correct choice......" << endl;
        }
    }
    return 0;
}