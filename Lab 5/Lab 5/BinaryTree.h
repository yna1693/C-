/** @file BinaryTree.h */
#ifndef _BINARY_TREE
#define _BINARY_TREE

#include "TreeException.h"
#include "UnsupportedOperationException.h"

template<class ItemType>
class BinaryTree {
	public:
	/** Default constructor
	Creates empty binary tree. */
	BinaryTree();

	/** Constructor with one argument
	@param rootItem  The item that will be at the root of the binary tree.
	@post  A binary tree is created with one node, which node contains
	rootItem. */
	BinaryTree(const ItemType& rootItem);

	/** Three argument constructor
	@param rootItem  The item that will be at the root of the binary tree.
	@param leftTree  Tree that will become the left subtree of the root.
	@param rightTree  Tree that will become the right subtree of the root.
	@post  A binary tree is created, containing rootItem at the root,
	what used to be leftTree is the left subtree of the root, and
	what used to be rightTree is the right subtree of the root.
	The original objects leftTree and rightTree are empty. */
	BinaryTree(const ItemType& rootItem,
		BinaryTree<ItemType>& leftTree,
		BinaryTree<ItemType>& rightTree);

	/** Copy constructor */
	BinaryTree(const BinaryTree<ItemType>& tree);

	/** Destructor */
	virtual ~BinaryTree();

	/** Determines whether or not the binary tree is empty.
	@post  Returns true if the binary tree is empty,
	else returns false.
	The binary tree is unchanged.  */
	virtual bool isEmpty() const;

	/** Returns a copy of item at the root of the binary tree.
	@pre  The binary tree is not empty.
	@post  Returns a copy of the item at the root of the binary tree.
	@throw  TreeLogicException in the binary tree is empty. */
	virtual ItemType getRootData() const
		throw(TreeLogicException);

	/** If the binary tree is empty, creates a new binary tree with
	newItem at the root.  If the binary tree is not empty, replaces
	the item at the root with newItem.
	@param newItem  The item to be placed at the root.
	@post  newItem is at the root of the binary tree. */
	virtual void setRootData(const ItemType& newItem);

	/** Creates a left child of the root, which child contains newItem.
	@pre  The binary tree is not empty and the root has no left child.
	@param newItem  The item to be placed in the left child of the root.
	@post  The root has a left child, which contains newItem.
	@throw  TreeLogicException if the binary tree is empty or if the
	root has a left child. */
	virtual void attachLeft(const ItemType& newItem)
		throw(TreeLogicException);

	/** Creates a right child of the root, which child contains newItem.
	@pre  The binary tree is not empty and the root has no right child.
	@param newItem  The item to be placed in the right child of the root.
	@post  The root has a right child, which contains newItem.
	@throw  TreeLogicException if the binary tree is empty or if the
	root has a right child. */
	virtual void attachRight(const ItemType& newItem)
		throw(TreeLogicException);

	/** Attaches leftTree as the left subtree of the root of the binary
	tree.  The original leftTree becomes empty.
	@pre  The binary tree is not empty and the root has no left child.
	@param leftTree  The binary tree which becomes the left subtree of
	the root.
	@post  leftTree is the left subtree of the root.  The original
	leftTree isEmpty.
	@throw  TreeLogicException if the binary tree is empty or if the
	root has a left child. */
	virtual void attachLeftSubtree(BinaryTree<ItemType>& leftTree)
		throw(TreeLogicException);

	/** Attaches rightTree as the right subtree of the root of the binary
	tree.  The original rightTree becomes empty.
	@pre  The binary tree is not empty and the root has no right child.
	@param rightTree  The binary tree which becomes the right subtree of
	the root.
	@post  rightTree is the right subtree of the root.  The original
	rightTree isEmpty.
	@throw  TreeLogicException if the binary tree is empty or if the
	root has a right child. */
	virtual void attachRightSubtree(BinaryTree<ItemType>& rightTree)
		throw(TreeLogicException);

	/** Detaches left subtree of the root and places it in leftTree
	@pre  The binary tree is not empty.
	@param leftTree  This parameter will contain the detached left
	subtree.
	@post  The left subtree of the root is empty.  The original left
	subtree of the root has been moved to leftTree.  subtree
	is set to false.
	@throw  TreeLogicException if the binary tree is empty. */
	virtual void detachLeftSubtree(BinaryTree<ItemType>& leftTree)
		throw(TreeLogicException);

	/** Detaches right subtree of the root and places it in rightTree
	@pre  The binary tree is not empty.
	@param rightTree  This parameter will contain the detached right
	subtree.
	@post  The right subtree of the root is empty.  The original right
	subtree of the root has been moved to rightTree.  subtree
	is set to false.
	@throw  TreeLogicException if the binary tree is empty. */
	virtual void detachRightSubtree(BinaryTree<ItemType>& rightTree)
		throw(TreeLogicException);

	/** Returns (does not detach) the left subtree of the root
	@pre  The binary tree is not empty.
	@post  The original binary tree is unchanged.  The left subtree of the
	root is returned.  subtree for the returned object is false.
	@throw  TreeLogicException if the original binary tree is empty. */
	virtual BinaryTree& getLeftSubtree()
		throw(TreeLogicException);


	/** Returns (does not detach) the right subtree of the root
	@pre  The binary tree is not empty.
	@post  The original binary tree is unchanged.  The right subtree of
	the root is returned. subtree for the returned object is false.
	@throw  TreeLogicException if the original binary tree is empty. */
	virtual BinaryTree& getRightSubtree()
		throw(TreeLogicException);

	/** Overloaded assignment operator.
	@pre  The left hand side is not a descendant of the right hand side
	@param rhs  The binary tree object on the right hand side of the
	assignment operator
	@post  The binary tree update on the right hand side of the assignment
	operator is copied to the current object on the left side of the
	assignment operator.
	@throw UnsupportedOperationException  if the current object on the
	left side of the assignment operator is a descendant of the binary
	tree on the right side of the assignment operator. */
	virtual BinaryTree& operator=(const BinaryTree<ItemType>& rhs)
		throw(UnsupportedOperationException);

	/** These three traversal functions traverse the tree in
	preorder/inorder/postorder and call the function visit once
	per node as it traverses each node.
	@param visit  A programmer-defined function that is called once
	per node as it traverses each node.
	@post  The function supplied by the argument operates once on each
	node. */
	virtual void preorderTraverse(void visit(ItemType&));
	virtual void inorderTraverse(void visit(ItemType&));
	virtual void postorderTraverse(void visit(ItemType&));

	protected:
	/** Copies the binary tree in its parameter to the current object
	@param tree  The binary tree to be copied.
	@post  The parameter is copied to the current object; subtree is set
	to false for the current object. */
	void copyTree(const BinaryTree<ItemType>& tree);

	/** Destroys the binary tree unless it is part of another binary
	tree.
	@post  The binary tree is empty unless it is part of another
	binary tree.  If the binary tree is a part of another binary
	tree, the binary tree is unchanged.  */
	void destroyTree();

	/** Determines whether or not the parameter tree is a subtree of the
	binary tree or a subtree of a descendant of the binary tree's root.
	@param tree  The binary tree that we are testing to see if it is a
	subtree of the current object or a subtree of a descendant of the
	current object's root.
	@post  Returns true if the parameter is a subtree of the current
	object or a subtree of a descendent of the current object's root,
	else returns false. */
	bool isSubtree(const BinaryTree<ItemType>& tree) const;


	private:
	BinaryTree<ItemType>* leftSubtreePtr;
	BinaryTree<ItemType>* rightSubtreePtr;
	ItemType* pItem;  // pointer to root item
	bool subtree;     // true if this is part of another object, which 
					  //   occurs if this object was created as a result
					  //   of a call to of getLeftSubtree or 
					  //   getRightSubtree; else return false
};
    
#endif       
