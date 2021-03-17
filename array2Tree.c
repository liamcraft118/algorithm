#include <stdio.h>
#include <stdlib.h>

struct BinaryTreeNode {
    int val;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

typedef struct BinaryTreeNode BinaryTreeNode;

// o(n)时间复杂度，o(n)空间复杂度
BinaryTreeNode* array2BinaryTree(int a[], int size) {
    if (size == 0) {
        return NULL;
    }

    BinaryTreeNode *tree[size];
    BinaryTreeNode *head = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    head->val = a[0];
    tree[0] = head;
    for (int i = 0; i < size; i++) {
        BinaryTreeNode *cur = tree[i];
        int leftIdx = 2 * i + 1;
        int rightIdx = 2 * i + 2;

        if (leftIdx >= size) break;

        BinaryTreeNode *left = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
        left->val = a[leftIdx];
        tree[leftIdx] = left;
        cur->left = left;

        if (rightIdx >= size) break;

        BinaryTreeNode *right = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
        right->val = a[rightIdx];
        tree[rightIdx] = right;
        cur->right = right;
    }

    return head;
}

BinaryTreeNode *array2BinaryTreeRecursive(int a[], int size, int n) {
    if (size == 0) return NULL;
    BinaryTreeNode *head = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    head->val = a[n];
    int leftIdx = 2 * n + 1;
    int rightIdx = 2 * n + 2;
    if (leftIdx < size) {
        head->left = array2BinaryTreeRecursive(a, size, leftIdx);
    }

    if (rightIdx < size) {
        head->right = array2BinaryTreeRecursive(a, size, rightIdx);
    }

    return head;
}

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

void retrieve(TreeNode *head) {
    if (head == NULL) return;
    printf("%d ", head->val);
    retrieve(head->left);
    retrieve(head->right);
}

int nodesOfTree(BinaryTreeNode *head) {
    if (head == NULL) return 0;
    int left = nodesOfTree(head->left);
    int right = nodesOfTree(head->right);
    return left + right + 1;
}


TreeNode* invertTree(TreeNode* root){
    if (root == NULL) return NULL;
    invertTree(root->right);
    invertTree(root->left);
    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    return root;
}

int main() {
    /* int a[10] = {0, 2, 5, 6, 3, 12, 53, 13, 145, 1}; */
    int a[8] = {4, 2, 7, 1, 3, 6, 9};
    int size = sizeof(a) / sizeof(a[0]);
    TreeNode *head = (TreeNode*)array2BinaryTree(a, size);
    /* BinaryTreeNode *head = array2BinaryTreeRecursive(a, size, 0); */
    /* retrieve(head); */
    TreeNode* root = invertTree(head);
    retrieve(root);

    return 0;
}
