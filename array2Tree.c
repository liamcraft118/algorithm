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

void retrieve(BinaryTreeNode *head) {
    if (head == NULL) return;
    printf("%d ", head->val);
    retrieve(head->left);
    retrieve(head->right);
}

int main() {
    int a[10] = {0, 2, 5, 6, 3, 12, 53, 13, 145, 1};
    int size = sizeof(a) / sizeof(a[0]);
    BinaryTreeNode *head = array2BinaryTree(a, size);
    /* BinaryTreeNode *head = array2BinaryTreeRecursive(a, size, 0); */
    retrieve(head);
    return 0;
}
