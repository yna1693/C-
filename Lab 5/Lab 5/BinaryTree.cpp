/** @file BinaryTree.cpp */ 

#include "BinaryTree.h" 
#include <iostream>
using namespace std;

template<class ItemType>
BinaryTree<ItemType>::BinaryTree()
{
      leftSubtreePtr = rightSubtreePtr = nullptr;
      pItem = nullptr;
      subtree = false;
}

template<class ItemType>
BinaryTree<ItemType>::BinaryTree(const ItemType& rootItem)
{
      pItem = new ItemType(rootItem);
      leftSubtreePtr = rightSubtreePtr = nullptr;
      subtree = false;
}

template<class ItemType>
BinaryTree<ItemType>::BinaryTree(const ItemType& rootItem, 
                                 BinaryTree<ItemType>& leftTree, 
                                 BinaryTree<ItemType>& rightTree)
{
      pItem = new ItemType(rootItem);
      leftSubtreePtr = rightSubtreePtr = nullptr; 
      subtree = false;
      
      attachLeftSubtree(leftTree);
      attachRightSubtree(rightTree);
}

template<class ItemType>
BinaryTree<ItemType>::BinaryTree(const BinaryTree<ItemType>& tree)
{
      copyTree(tree);
      subtree = false;
}

template<class ItemType>
BinaryTree<ItemType>::~BinaryTree()
{
      destroyTree();
}

template<class ItemType>
bool BinaryTree<ItemType>::isEmpty() const
{
      return bool(pItem == nullptr);
}

template<class ItemType>
ItemType BinaryTree<ItemType>::getRootData() const
  throw(TreeLogicException)
{
      if (isEmpty())
            throw TreeLogicException(
              "TreeLogicException: Empty tree");
      return *pItem;
}  

template<class ItemType>
void BinaryTree<ItemType>::setRootData(const ItemType& newItem)
{
      if (pItem != nullptr)
            *pItem = newItem;
      else
      {
            pItem = new ItemType(newItem);
            leftSubtreePtr = rightSubtreePtr = nullptr;
            subtree = false;
      }
}

template<class ItemType>
void BinaryTree<ItemType>::attachLeft(const ItemType& newItem) 
  throw(TreeLogicException)
{
      if (isEmpty())
            throw TreeLogicException(
              "TreeLogicException: Empty tree");
      else if (leftSubtreePtr != nullptr)
            throw TreeLogicException(
              "TreeLogicException: Cannot overwrite left subtree");
      else  // nonempty tree; no left child
            leftSubtreePtr = new BinaryTree(newItem);
} 

template<class ItemType>
void BinaryTree<ItemType>::attachRight(const ItemType& newItem) 
  throw(TreeLogicException)
{
      if (isEmpty())
            throw TreeLogicException(
             "TreeLogicException: Empty tree");
      else if (rightSubtreePtr != nullptr)
            throw TreeLogicException(
              "TreeLogicException: Cannot overwrite right subtree");
      else  // nonempty tree; no right child
            rightSubtreePtr = new BinaryTree(newItem);
}
 
template<class ItemType>
void BinaryTree<ItemType>::attachLeftSubtree(
  BinaryTree<ItemType>& leftTree)
    throw(TreeLogicException)
{
      if (isEmpty())
            throw TreeLogicException(
              "TreeLogicException: Empty tree");
      else if (leftSubtreePtr != nullptr)
            throw TreeLogicException(
              "TreeLogicException: Cannot overwrite left subtree");
      else  // nonempty tree; no left child
      {
            leftSubtreePtr = new BinaryTree(leftTree);
            leftTree.destroyTree();
      }
}  

template<class ItemType>
void BinaryTree<ItemType>::attachRightSubtree(
  BinaryTree<ItemType>& rightTree)
    throw(TreeLogicException)
{
      if (isEmpty())
            throw TreeLogicException(
              "TreeLogicException: Empty tree");
      else if (rightSubtreePtr != nullptr)
            throw TreeLogicException(
              "TreeLogicException: Cannot overwrite right subtree");
      else  // nonempty tree; no right child
      {
            rightSubtreePtr = new BinaryTree(rightTree);
            rightTree.destroyTree();
      }
}

template<class ItemType>
void BinaryTree<ItemType>::detachLeftSubtree(
  BinaryTree<ItemType>& leftTree) 
    throw(TreeLogicException)
{
      if (isEmpty())
            throw TreeLogicException(
              "TreeLogicException: Empty tree");
      else
      {
            leftTree = *leftSubtreePtr;
            leftSubtreePtr = nullptr;
            subtree = false;
      }
}

 
template<class ItemType>
void BinaryTree<ItemType>::detachRightSubtree(
  BinaryTree<ItemType>& rightTree)
    throw(TreeLogicException)
{
      if (isEmpty())
            throw TreeLogicException(
              "TreeLogicException: Empty tree");
      else
      {  
            rightTree = *rightSubtreePtr;
            rightSubtreePtr = nullptr;
            subtree = false;
      }
}

template<class ItemType>
BinaryTree<ItemType>& BinaryTree<ItemType>::getLeftSubtree() 
  throw(TreeLogicException)
{
      if (isEmpty())
      {
            throw TreeLogicException(
              "TreeLogicException: Empty tree");

            // unreached code to satisfy Visual C++ return requirement
            BinaryTree<ItemType>* emptyTree = new BinaryTree();
            return *emptyTree;
      }

      else if (leftSubtreePtr)
      {
            leftSubtreePtr->subtree = true;
            return *leftSubtreePtr;
      }
      else
      {
            BinaryTree<ItemType>* emptyTree = new BinaryTree();
            return *emptyTree;
      }
}

template<class ItemType>
BinaryTree<ItemType>& BinaryTree<ItemType>::getRightSubtree()
  throw(TreeLogicException)
{
      if (isEmpty())
      {
            throw TreeLogicException(
              "TreeLogicException: Empty tree");

            // unreached code to satisfy Visual C++ return requirement
            BinaryTree<ItemType>* emptyTree = new BinaryTree();

            return *emptyTree;
      }
 
      else if (rightSubtreePtr)
      {
            rightSubtreePtr->subtree = true;
            return *rightSubtreePtr;
      }
      else
      {
            BinaryTree<ItemType>* emptyTree = new BinaryTree();
            return *emptyTree;
      }
}  

template<class ItemType>
void BinaryTree<ItemType>::preorderTraverse(void visit(ItemType&)) 
{
      if (pItem != nullptr)
      {
            visit(*pItem);
            if (leftSubtreePtr)
                  leftSubtreePtr->preorderTraverse(visit);
            if (rightSubtreePtr)
                  rightSubtreePtr->preorderTraverse(visit);
      }
}

template<class ItemType>
void BinaryTree<ItemType>::inorderTraverse(void visit(ItemType&)) 
{
      if (pItem != nullptr)
      {
            if (leftSubtreePtr)
                  leftSubtreePtr->inorderTraverse(visit);
            visit(*pItem);
            if (rightSubtreePtr)
                  rightSubtreePtr->inorderTraverse(visit);
      }
}

template<class ItemType>
void BinaryTree<ItemType>::postorderTraverse(void visit(ItemType&)) 
{
      if (pItem != nullptr)
      {
            if (leftSubtreePtr)
                  leftSubtreePtr->postorderTraverse(visit);
            if (rightSubtreePtr)
                  rightSubtreePtr->postorderTraverse(visit);
            visit(*pItem);
      } 
}

template<class ItemType>
BinaryTree<ItemType>& BinaryTree<ItemType>::operator=(const BinaryTree<ItemType>& rhs) throw(UnsupportedOperationException)
{
      if (isSubtree(rhs))
      {
            string message = "UnsupportedOperationException: ";
            message += "illegal assignment in BinaryTree";
            throw UnsupportedOperationException(message);
      }
      else if (this != &rhs)
      {
            destroyTree();  // deallocate left-hand side
            copyTree(rhs);  
      }

      return *this;
}

template<class ItemType>
void BinaryTree<ItemType>::copyTree(const BinaryTree<ItemType>& tree) 
{
      // preorder traversal
      if (tree.pItem)
      {        // copy node
            ItemType Temp = *(tree.pItem);
            pItem = new ItemType(Temp);

            if (tree.leftSubtreePtr)
            {
                  leftSubtreePtr = 
                        new BinaryTree(*(tree.leftSubtreePtr));
            }
            else
            {
                  leftSubtreePtr = nullptr;
            }

            if (tree.rightSubtreePtr)
            {
                  rightSubtreePtr = 
                        new BinaryTree(*(tree.rightSubtreePtr));
            }
            else
            {
                  rightSubtreePtr = nullptr;
            }
      }
      else
      {
            pItem = nullptr;  // copy empty tree
            leftSubtreePtr = rightSubtreePtr = nullptr;
      }
}  
 
 
template<class ItemType>
void BinaryTree<ItemType>::destroyTree()
{
      // postorder traversal

      if (leftSubtreePtr && !leftSubtreePtr->subtree)
      {
            leftSubtreePtr->destroyTree();
            delete leftSubtreePtr;
            leftSubtreePtr = nullptr;
      }

      if (rightSubtreePtr && !rightSubtreePtr->subtree) 
      {
            rightSubtreePtr->destroyTree();
            delete rightSubtreePtr;
            rightSubtreePtr = nullptr;
      }

      if (pItem && !subtree)
      {
            delete pItem;
            pItem = nullptr;
      }
}

template<class ItemType>
bool BinaryTree<ItemType>::isSubtree(
  const BinaryTree<ItemType>& tree) const
{
      if (!pItem || !tree.pItem)
            return false;
      else if (leftSubtreePtr && leftSubtreePtr == &tree)
            return true;
      else if (rightSubtreePtr && rightSubtreePtr == &tree)
            return true;
      else 
      {
            if (leftSubtreePtr && leftSubtreePtr->isSubtree(tree))
                  return true;
            if (rightSubtreePtr && rightSubtreePtr->isSubtree(tree))
                  return true;
            return false;
      }
}
