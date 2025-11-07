#include "BagInterface.h"
#include "Node.h"
#include <cstddef>
#include <string>

template <class ItemType>
class LinkedBag : public BagInterface<ItemType>
{
private:
   Node<ItemType> *headPtr; // Pointer to first node
   int itemCount;           // Current count of bag items

public:
   LinkedBag();
   LinkedBag(const LinkedBag<ItemType> &aBag); // Copy constructor
   virtual ~LinkedBag();                       // Destructor should be virtual
   int getCurrentSize() const;
   bool isEmpty() const;
   bool add(const ItemType &newEntry);
   bool remove(const ItemType &anEntry);
   bool containsAllValues(LinkedBag<ItemType> *otherPtr);
   bool isSameUnordered(LinkedBag<ItemType> *otherPtr);
   void clear();
   vector<ItemType> toVector() const;
};

template <class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0)
{
}

template <class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
   clear();
}

template <class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
   return itemCount == 0;
}

template <class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
   return itemCount;
}

template <class ItemType>
void LinkedBag<ItemType>::clear()
{
   Node<ItemType> *nodeToDeletePtr = headPtr;

   while (headPtr != nullptr)
   {
      headPtr = headPtr->getNext();

      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;

      nodeToDeletePtr = headPtr;
   } // end while
   // headPtr is nullptr; nodeToDeletePtr is nullptr

   itemCount = 0;
}

template <class ItemType>
bool LinkedBag<ItemType>::add(const ItemType &newEntry)
{

   // add your code here
   Node<ItemType> *node = new Node<ItemType>();
   node->setItem(newEntry);
   node->setNext(headPtr);

   headPtr = node;
   itemCount++;

   return true;
}

template <class ItemType>
vector<ItemType> LinkedBag<ItemType>::toVector() const
{
   vector<ItemType> bagContents;
   Node<ItemType> *curPtr = headPtr;
   int counter = 0;

   while ((curPtr != nullptr) && (counter < itemCount))
   {
      bagContents.push_back(curPtr->getItem());
      curPtr = curPtr->getNext();
      counter++;
   }

   return bagContents;
}

template <class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType &anEntry)
{

   // add your code here

   return false;
}

template <class ItemType>
bool LinkedBag<ItemType>::containsAllValues(LinkedBag<ItemType> *other)
{

   // add yor code here
   Node<ItemType> *otherBag = other->headPtr;

   while (otherBag)
   {
      Node<ItemType> *myBag = this->headPtr;
      bool flag = false;
      while (myBag)
      {
         if (otherBag->getItem() == myBag->getItem())
         {
            flag = true;
            break;
         }
         myBag = myBag->getNext();
      }
      if (!flag)
         return flag;

      otherBag = otherBag->getNext();
   }
   
   return true;

}

template <class ItemType>
bool LinkedBag<ItemType>::isSameUnordered(LinkedBag<ItemType> *other)
{
   // add yor code here

   if (this->itemCount != other->itemCount)
      return false;

   vector<ItemType> thisVector = this->toVector();
   vector<ItemType> otherVector = other->toVector();

   // insertsort
   for (int i = 1; i < thisVector.size(); i++)
   {
      ItemType key = thisVector[i];
      int j = i - 1;

      while (j >= 0 && thisVector[j] > key)
      {
         thisVector[j + 1] = thisVector[j];
         j--;
      }
      thisVector[j + 1] = key;
   }

   for (int i = 1; i < otherVector.size(); i++)
   {
      ItemType key = otherVector[i];
      int j = i - 1;

      while (j >= 0 && otherVector[j] > key)
      {
         otherVector[j + 1] = otherVector[j];
         j--;
      }
      otherVector[j + 1] = key;
   }
   // end sort

   for (int i = 0; i < thisVector.size(); i++)
   {
      if (thisVector[i] != otherVector[i])
         return false;
   }

   return true;
}
