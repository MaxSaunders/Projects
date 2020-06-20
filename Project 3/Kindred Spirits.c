// Max Saunders
// COP 4415, Spring 2019
// Project 3 Kindred Spirits

#include <stdio.h>
#include <stdlib.h>
#include "KindredSpirits.h"


double difficultyRating(void)
{
	return 3;
}

double hoursSpent(void)
{
	return 6;
}


// Function to compare two nodes and see if they are reflections
int isReflection(node *a, node *b)
{
	// If a & b == NULL return 1, simply true
	if (a == NULL && b == NULL)
		return 1;
	// Else if one but not the other is NULL return 0 since NULL != !NULL
	else if (a == NULL || b == NULL)
		return 0;
	// If root data is equal
	if (a->data == b->data)
	{
		// If both no children return 1
		if (a->left == NULL && a->right == NULL && b->right == NULL && b->left == NULL)
			return 1;
		// If any of the reflection combinations are not =, return 0;
		else if (a->left == NULL && b->right != NULL)
			return 0;
		else if (a->right == NULL && b->left != NULL)
			return 0;
		else if (b->left == NULL && a->right != NULL)
			return 0;
		else if (b->right == NULL && a->left != NULL)
			return 0;
		// If reflection combinations are = recursively check through the whole tree
		if (a->left->data == b->right->data && a->right->data == b->left->data)
		{
			if (isReflection(a->left, b->right) == 0)
				return 0;
			if (isReflection(a->right, b->left) == 0)
				return 0;
			// If it makes it through unscathed then return 1
			return 1;
		}
		// Else if either are unequal return 0
		else if (a->left->data != b->right->data || a->right->data != b->left->data)
		{
			return 0;
		}
	}
	// If root data not = return 0
	else
	{
		return 0;
	}
}

// InsertReflectionNodes function used in the makeReflection function
node *insertReflectionNodes(node *root)
{
	// Check for root == NULL
	if (root == NULL)
		return NULL;
	// Declare root node and set = root data
	node *node_x = calloc(1, sizeof(node));
	node_x->data = root->data;
	// Set reflection combinations for new tree using root
	node_x->right = (root->left == NULL ? NULL : insertReflectionNodes(root->left));
	node_x->left = (root->right == NULL ? NULL : insertReflectionNodes(root->right));
	// Return new tree
	return nodey;
}

// Make Reflection function
node *makeReflection(node *root)
{
	return root == NULL ? NULL : insertReflectionNodes(root);
}

// PreOrderTraversal function used in the kindredSpirits function
// Transverse tree in preorder
int *preOrderTraversal(node *root, int *array, int i)
{
	if (root == NULL)
		return array;
	// Set index 0 of array = root data increment index
	array[i] = root->data;
	i++;
	// Recursively call preOrderTraversal function on left side of tree
	array = preOrderTraversal(root->left, array, i);
	// Fix index
	while (array[i] != 0)
		i++;
	// Recursively call preOrderTraversal function on right side of tree
	array = preOrderTraversal(root->right, array, i);
	// Return array of preOrderTraversal of given tree
	return array;
}

// PostOrderTraversal function in the kindredSpirits function
// Transverse tree in post order
int *postOrderTraversal(node *root, int *array, int i)
{
	// Check root == NULL
	if (root == NULL)
		return array;
	// If both left and right NULL set array to root data and continue
	if (root->left == NULL && root->right == NULL)
	{
		array[i] = root->data;
	}
	// If right != NULL recursively call right side and set array
	else if (root->left == NULL)
	{
		array = postOrderTraversal(root->right, array, i++);
		array[i] = root->data;
	}
	// If left != opposite as above
	else if (root->right == NULL)
	{
		array = postOrderTraversal(root->left, array, i++);
		array[i] = root->data;
	}
	// Else neither is NULL so traverse both children and set array
	else
	{
		array = postOrderTraversal(root->left, array, i++);
		while (array[i] != 0)
		{
			i++;
		}
		array = postOrderTraversal(root->right, array, i++);
		while (array[i] != 0)
		{
			i++;
		}
		array[i] = root->data;
	}
	// Return array of postOrderTraversal
	return array;
}

// numNodes function designed to return the # of nodes in a given tree
int numNodes(node *root)
{
	return root == NULL ? 0 : 1 + numNodes(root->left) + numNodes(root->right);
}

//PostOrder function used in the kindredSpirits function
// collects data from postOrder function
int PostOrderData(node *root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL & root->right == NULL)
		return root->data;
	if (root->right == NULL)
		return PostOrderData(root->left);
	if (root->left == NULL)
		return PostOrderData(root->right);
	else
		return PostOrderData(root->left);
}

// Main Function
// KindredSpirits function
int kindredSpirits(node *a, node *b)
{
	// Declare variables
	int i = 0, j = 0, CounterA = numNodes(a), CounterB = numNodes(b);
	int *arrayA, *arrayB;
	// If unequal node counts, then return 0
	if (CounterA != CounterB)
		return 0;
	// Allocate memory for arrays
	arrayA = calloc(1, sizeof(int)*CounterA);
	arrayB = calloc(1, sizeof(int)*CounterB);
	// Check for NULLs
	if (a == NULL && b == NULL)
		return 1;
	else if (a == NULL || b == NULL)
		return 0;
	// If data is = and no children for either return 1
	if (a->data == b->data &&
	(a->left == NULL && b->left == NULL && a->right == NULL && b->right == NULL))
	{
		return 1;
	}
	// If a first preOrder = b first postOrder then do it accordingly
	if (a->data == PostOrderData(b))
	{
		arrayA = preOrderTraversal(a, arrayA, i);
		arrayB = postOrderTraversal(b, arrayB, i);
	}
	// If b first preOrder = a firstPostOrder then do it accordingly
	else if (b->data == PostOrderData(a))
	{
		arrayA = postOrderTraversal(a, arrayA, i);
		arrayB = preOrderTraversal(b, arrayB, i);
	}
	// If neither than this can't be a kindredSpirits relation return 0
	else
	{
		return 0;
	}
	// If made to this point go through created pre and post order arrays and compare
	for(j = 0; j < CounterA; j++)
	{
		// If they are ever different return 0
		if (arrayA[j] != arrayB[j])
			return 0;
	}
	// If they are never different return 1
	return 1;
}
