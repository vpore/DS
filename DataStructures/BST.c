#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct BST{
    int data;
    struct BST *left;
    struct BST *right;
}node;

node* root=NULL;

node *insertElement(node*);
void preorderTrav(node*);
void inorderTrav(node*);
void postorderTrav(node*);
node *deleteElement(node*, int);
int totalNodes(node*);
int internalNodes(node*);
int externalNodes(node*);
int height(node*);
node *smallest(node*);
node *largest(node*);
int max(int, int);

void main(){
    int choice, val;
    node *temp;
    do{
        printf("Enter your choice:\n1. Insert Element\t2. PreOrder Traversal\t3. InOrder Traversal\n4. PostOrder Traversal\t5. Delete Element\t6. Total Nodes\n7. Internal Nodes\t8. External Nodes\t9. Height Of BST\n10. Smallest Element\t11. Largest Element\t12. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1: root=insertElement(root); break;
            case 2: preorderTrav(root); printf("\n"); break;
            case 3: inorderTrav(root); printf("\n"); break;
            case 4: postorderTrav(root); printf("\n"); break;
            case 5:
                printf("Enter the element to be deleted:\n");
                scanf("%d", &val);
                root=deleteElement(root, val); break;
            case 6: printf("Total Nodes: %d\n", totalNodes(root)); break;
            case 7: printf("Internal Nodes: %d\n", internalNodes(root)); break;
            case 8: printf("Internal Nodes: %d\n",externalNodes(root)); break;
            case 9: printf("Height: %d\n", height(root)); break;
            case 10: 
                temp=smallest(root); 
                printf("Smallest Element: %d\n", temp->data);
                break;
            case 11: 
                temp=largest(root); 
                printf("Largest Element: %d\n", temp->data);
                break; 
            case 12: exit(1);
            default: printf("Enter appropriate choice\n");
        }
    }while(choice!=12);
}

node* insertElement(node *root){
    int val;
    node *temp1;
    node *temp2;
    node *newnode=(node*)malloc(sizeof(node));
    newnode->left=NULL;
    newnode->right=NULL;
    printf("Enter data:\n");
    scanf("%d", &val);
    newnode->data=val;
    if(root==NULL){
        root=newnode;
    }
    else{
        temp2=NULL;
        temp1=root;
        while(temp1!=NULL){
            temp2=temp1;
            if(val<=temp1->data)
                temp1=temp1->left;
            else
                temp1=temp1->right;
        }
        if(val<temp2->data){
            temp2->left=newnode;
        }
        else{
            temp2->right=newnode;
        }
    }
    return root;
}

void preorderTrav(node *root){
    if(root!=NULL){
        printf("%d\t", root->data);
        preorderTrav(root->left);
        preorderTrav(root->right);
    }
}

void inorderTrav(node *root){
    if(root!=NULL){
        inorderTrav(root->left);
        printf("%d\t", root->data);
        inorderTrav(root->right);
    }
}

void postorderTrav(node *root){
    if(root!=NULL){
        postorderTrav(root->left);
        postorderTrav(root->right);
        printf("%d\t", root->data);
    }
}

node *deleteElement(node *root, int val){
    if(root==NULL){root=root;}
    else if(val>root->data){root->right=deleteElement(root->right, val);}
    else if(val<root->data){root->left=deleteElement(root->left, val);}
    else{
        if(root->left==NULL){
            node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            node *temp=root->left;
            free(root);
            return temp;
        }
        else{
            node *temp=smallest(root->right);
            root->data=temp->data;
            root->right=deleteElement(root->right, temp->data);
        }
    }
    return root;
}

node *smallest(node *temp){
    if(temp==NULL || temp->left==NULL){return temp;}
    else{return smallest(temp->left);}
}

node *largest(node *temp){
    if(temp==NULL || temp->right==NULL){return temp;}
    else{return largest(temp->right);}
}

int totalNodes(node *temp){
    if(temp!=NULL){
        return (totalNodes(temp->right) + totalNodes(temp->left) + 1);
    }
    else{return 0;}
}

int internalNodes(node *temp){
    if(temp==NULL || temp->left==NULL && temp->right==NULL){return 0;}
    else{return(internalNodes(temp->left) + internalNodes(temp->right) + 1);}
}

int externalNodes(node *temp){
    if(temp==NULL){return 0;}
    else if(temp->left==NULL && temp->right==NULL){return 1;}
    else{return (externalNodes(temp->left) + externalNodes(temp->right));}
}

int height(node *temp){
    if(temp==NULL){return -1;}
    else{
        int left=height(temp->left);
        int right=height(temp->right);
        return( max(left, right)+1);
    }
}

int max(int a, int b){
    if(a>b){return a;}
    else{return b;}
}