#include "BinaryTree.h"

void bCreate(bTree *tree){
    tree->root = NULL;
}
nAddress bCreateNode(infotype x){
    nAddress newNode;
    newNode = (nAddress) malloc(sizeof(TreeNode));
    if(newNode != NULL){
    	newNode->info = x;
    	newNode->left = NULL;
    	newNode->right = NULL;
	}
	return newNode;
}
bool isTreeEmpty(bTree tree){
	return (tree.root == NULL);
}
// Start Hafizh
void bInsert(bTree *root, nAddress parent, char position ,infotype x){
    nAddress newNode;
    newNode = bCreateNode(x);
    if(newNode != NULL){
    	if(parent == NULL){
    		root->root = newNode;
		}else{
			if( toupper(position) == 'L' && parent->left == NULL){
				parent->left = newNode;
			}else if( toupper(position) == 'R' && parent->right == NULL){
				parent->right = newNode;
			}else{
				printf("GAGAL INSERT !!\n");
				return;
			}
			printf("BERHASIL INSERT !!\n");
		}
	}
}
nAddress bSearch(nAddress root, infotype src){
    nAddress searchNode;
    if(root == NULL){
    	return NULL;
	}else{
		if(root->info == src){
			return root;
		}else{
			searchNode = bSearch(root->left, src);
			if(searchNode == NULL)
				return bSearch(root->right, src);
			else
				return searchNode;
		}
	}
}
nAddress bSearchParent(nAddress root, nAddress searchChild){
	nAddress searchNode;
	if(root == NULL){
		return NULL;
	}else{
		if(root->left == searchChild || root->right == searchChild){
			return root;
		}else{
			searchNode = bSearchParent(root->left, searchChild);
			if(searchNode == NULL)
				return bSearchParent(root->right, searchChild);
			else
				return searchNode;
		}
	}
}
void bUpgrade(bTree *root){
    return;
}
void bDelete(bTree *tree, nAddress *nodeDel){
    if(isTreeEmpty(*tree)){
    	printf("Tree Kosong");
    	return;
	}else{
		nAddress nCurrent, nParent;
		nCurrent = *nodeDel;
		if(nCurrent == tree->root && nCurrent->left == NULL){
			tree->root = NULL;
			return;
		}
		nParent = bSearchParent(tree->root, nCurrent);
		if(nParent != NULL){
			if(nParent->left == nCurrent){
				nParent->left = NULL;
			}else if(nParent->right == nCurrent){
				nParent->right = NULL;
			}else{
				printf("GAGAL DELETE !! \n");
				return;
			}
			printf("BERHASIL DELETE");
		}
		free(*nodeDel);
	}
    	
}
int bDepth(nAddress root){
    if(root == NULL){
    	return -1;
	}else{
		int left = bDepth(root->left);
		int right = bDepth(root->right);
		if(left > right)
			return left + 1;
		else
			return right + 1;
	}
}
// End Hafizh
// Start Salman 
// TRAVERSAL TREE
void bPost(nAddress root) //Post order untuk memproses simpul anak sebelah kiri dilanjukan ke sebelah kanan
{
	if (root!=NULL){
		bPost(root->left);
		bPost(root->right);
		printf("%d ", root->info);
		
	}
}
void bPre(nAddress root) //PreOrder
{
	if (root!=NULL){
		printf("%d ", root->info);
		bPre(root->left);
		bPre(root->right);
	}
    return;
}
void bIn(nAddress root) //Inorder
{
	if (root!=NULL){
		bIn(root->left);
		printf("%d ", root->info);
		bIn(root->right);
	}
}
void bLevelOrder(nAddress root,int level){
	if(root!=NULL)
	{
		if(level == 0){
			printf("%d ", root->info);
		}
		if(level > 0){
			bLevelOrder(root->left, level-1);
			bLevelOrder(root->right, level-1);
		}
	}
}
void bPrint(nAddress node, char tab[]){
	char tempTab[255];
	strcpy(tempTab, tab);
	strcat(tempTab, "-");
	if (node!=NULL){
		printf("%s%d\n",tab,node->info);
		bPrint(node->left,tempTab);
		bPrint(node->right,tempTab);
	}
}
// End Salman
