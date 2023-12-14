#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    } else {
        if (key < root->key) {
            root->left = insert(root->left, key);
        } else {
            root->right = insert(root->right, key);
        }
    }
    return root;
}

int height(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
}

void printLeafNodes(struct Node* root) {
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {
            printf("%d ", root->key);
        } else {
            printLeafNodes(root->left);
            printLeafNodes(root->right);
        }
    }
}

void mirrorTree(struct Node* root) {
    if (root != NULL) {
        struct Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirrorTree(root->left);
        mirrorTree(root->right);
    }
}

void printLevelOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear) {
        struct Node* current = queue[++front];
        printf("%d ", current->key);

        if (current->left != NULL) {
            queue[++rear] = current->left;
        }
        if (current->right != NULL) {
            queue[++rear] = current->right;
        }
    }
}

int main() {
    struct Node* root = NULL;
//    int keys[] = {8, 3, 10, 1, 6, 9, 14, 4, 7, 13};
//    int i;
	int i,k,n,keys[20];
	printf("Enter the total no. of nodes you want to insert:\n");
	scanf("%d",&n);
	printf("Enter the values one by one:-\n");
	for(i=0;i<n;i++)
	{
		printf("Enter the value[%d]:",i+1);
		scanf("%d",&keys[i]);
//	}
//	
//    for (i = 0; i < 10; i++) {
        root = insert(root, keys[i]);
    }

    printf("\nOriginal tree:\n");
    printLevelOrder(root);
    printf("\nHeight of the tree: %d\n", height(root));
    printf("Leaf nodes: ");
    printLeafNodes(root);

    mirrorTree(root);
    printf("\n\nMirror image:\n");
    printLevelOrder(root);

    return 0;
}
