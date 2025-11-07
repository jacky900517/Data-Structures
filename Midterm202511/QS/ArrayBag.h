#include "BagInterface.h"
#include <cstddef>
#include <string>

template<class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 10; // Small size to test for a full bag
	ItemType items[DEFAULT_CAPACITY];      // Array of bag items
	int itemCount;                         // Current count of bag items 
	int maxItems;                          // Max capacity of the bag

public:
	ArrayBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	bool containsAllValues(ArrayBag<ItemType>& other);
	bool isSameUnordered(ArrayBag<ItemType>& other);
	void clear();
   	vector<ItemType> toVector() const;
}; 


template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
} 

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
} 

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
} 

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
} 

template<class ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const
{
	vector<ItemType> bagContents;

	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);
      
   	return bagContents;
}

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if

	return hasRoomToAdd;

	return false;
}

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{

	// add yor code here

	return false;
}

template<class ItemType>
bool ArrayBag<ItemType>::containsAllValues(ArrayBag<ItemType>& other)
{

	// add yor code here

	return false;
}

template<class ItemType>
bool ArrayBag<ItemType>::isSameUnordered(ArrayBag<ItemType>& other)
{

	// add yor code here

	return false;
}
