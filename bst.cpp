#include <iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

void insert(node** root, int data);
void preOrder(node* root);
void inOrder(node* root);
void postOrder(node* root);
int size(node* root);
int height(node* root);
int sumOfWeight(node* root);
int maxPathWeight(node* root);
void mirror(node** root);
void destruct(node** root);

int main()
{
    int numTestCases;

    cin >> numTestCases;
    while (numTestCases--)
    {
        int num, i;
        node* root = nullptr;

        cin >> num;
        for (i = 0; i < num; i++)
        {
            int data;
            cin >> data;
            insert(&root, data);
        }

        cout << size(root) << endl;
        cout << height(root) << endl;
        cout << sumOfWeight(root) << endl;
        cout << maxPathWeight(root) << endl;
        mirror(&root);
        preOrder(root); cout << endl;
        inOrder(root); cout << endl;
        postOrder(root); cout << endl;
        destruct(&root); 
        if (root == nullptr)
            cout << "0" << endl;
        else
            cout << "1" << endl;
    }
    return 0;
}

// 데이터 삽입(recursion)
void insert(node** root, int data)
{
    if(*root == nullptr){
        *root = new node;
        (*root)->data = data;
        (*root)->left = nullptr;
        (*root)->right = nullptr;
    }else if(data <= (*root)->data){
        insert(&((*root)->left), data);
    }else{
        insert(&((*root)->right), data);
    }
}

// 전위(preorder)탐색(recursion)
void preOrder(node* root)
{
    if(root != nullptr){
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// 중위(inorder)탐색(recursion)
void inOrder(node* root)
{
    if(root != nullptr){
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// 후위(postorder)탐색(recursion)
void postOrder(node* root)
{
    if(root != nullptr){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

// 노드의 개수(recursion)
int size(node* root)
{
    if(root == nullptr){
        return 0;
    }else{
        return size(root->left) + size(root->right) + 1;
    }
}

// 높이(recursion)
int height(node* root)
{
    if(root == nullptr){
        return -1; 
    }else{
        int lh = height(root->left);
        int rh = height(root->right);
        return max(lh, rh) + 1;
    }
}

// 미러 이미지로 변환하기(recursion)
void mirror(node** root)
{
    if(*root == nullptr){
        return;
    }else{
    node* temp = (*root)->left;
    (*root)->left = (*root)->right;
    (*root)->right = temp;

    mirror(&((*root)->left));
    mirror(&((*root)->right));
    }
}

// 노드에 저장된 데이터의 값의 합 구하기(recursion)
int sumOfWeight(node* root)
{
    if(root == nullptr){
        return 0;
    }else{
        return (root->data) + sumOfWeight(root->left) + sumOfWeight(root->right);
    }
}

// 루트노드부터 단말노드까지의 경로 상의 데이터의 최대합(recursion)
int maxPathWeight(node* root)
{
    if(root == nullptr){
        return 0;
    }else{
    int lMax = maxPathWeight(root->left);
    int rMax = maxPathWeight(root->right);

    return max(root->data, max(root->data + lMax, root->data + rMax));
    }
}

// 트리노드의 동적 메모리 해제하기(recursion)
void destruct(node** root)
{
    if(*root == nullptr){
        return;
    }else{
    destruct(&((*root)->left));
    destruct(&((*root)->right));

    delete *root;
    *root = nullptr;
    }
}
