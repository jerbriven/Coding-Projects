/** @file  ArrayDictionary */

// Private Member Functions

#include <iostream>
using namespace std;

template <class KeyType, class ItemType>
void ArrayDictionary<KeyType, ItemType>::destroyDictionary()
{
    // Delete and recreate items, reset itemCount to 0
    delete[] items;
    items = new Entry<KeyType, ItemType>[maxItems];
    itemCount = 0;
}

template <class KeyType, class ItemType>
int ArrayDictionary<KeyType, ItemType>::findEntryIndex(int firstIndex, 
    int lastIndex, const KeyType& searchKey) const 
{
    // Use Binary search to find entry
    int middleIdx = firstIndex + (lastIndex - firstIndex) / 2;

    if (firstIndex > lastIndex)
        // Item not found
        return -1;
    else if (searchKey == items[middleIdx].getKey())
    {
        // Middle index is item key
        return middleIdx;
    }
    else if (searchKey < items[middleIdx].getKey())
    {
        // Recursively call binary search left of middle index
        return findEntryIndex(firstIndex, middleIdx - 1, searchKey);
    }
    else if (searchKey > items[middleIdx].getKey())
    {
        // Recursively call binary search right of middle index
        return findEntryIndex(middleIdx + 1, lastIndex, searchKey);
    }
    
}

// Public Member Functions

// Default Constructor
template <class KeyType, class ItemType>
ArrayDictionary<KeyType, ItemType>::ArrayDictionary() : 
    itemCount(0), maxItems(DEFAULT_CAPACITY)
{
    // Instantiate items
    items = new Entry<KeyType, ItemType>[DEFAULT_CAPACITY];
}

template <class KeyType, class ItemType>
ArrayDictionary<KeyType, ItemType>::ArrayDictionary(int maxNumberOfEntries) :
    itemCount(0), maxItems(maxNumberOfEntries) 
{
    items = new Entry<KeyType, ItemType>[maxNumberOfEntries];
}

template <class KeyType, class ItemType>
ArrayDictionary<KeyType, ItemType>::ArrayDictionary(const ArrayDictionary<KeyType, ItemType>& dict) :
    itemCount(dict.itemCount), maxItems(dict.maxItems)
{
    // Instantiate items
    items = new Entry<KeyType, ItemType>[dict.maxItems];
    // Copy over dictionary items
    for (int i = 0; i < dict.itemCount; ++i)
        items[i] = dict.items[i];
}
   
template <class KeyType, class ItemType>
ArrayDictionary<KeyType, ItemType>::~ArrayDictionary()
{
    // Call destroy dictionary
    destroyDictionary();
}
   
template <class KeyType, class ItemType>
bool ArrayDictionary<KeyType, ItemType>::isEmpty() const
{
    // Only return true if itemCount is 0
    if (itemCount == 0)
        return true;
    else
        return false;
}

template <class KeyType, class ItemType>
int ArrayDictionary<KeyType, ItemType>::getNumberOfItems() const
{
    // Return current itemCount
    return itemCount;
}

template <class KeyType, class ItemType>
bool ArrayDictionary<KeyType, ItemType>::add(const KeyType& searchKey, const ItemType& newItem)
{
   bool ableToInsert = (itemCount < maxItems);
   if (ableToInsert)
   {
      // Make room for new entry by shifting all entries at
      // positions >= newPosition toward the end of the array
      // (no shift if newPosition == itemCount + 1). Performing
      // a binary search doesn’t help here, because we need to
      // shift the entries while looking for the insertion location.
      int index = itemCount;
      
      // Short-circuit evaluation is important
      while ( (index > 0) && (searchKey < items[index - 1].getKey()) )
      {
         items[index] = items[index - 1];
         index--;
      }  // end while
      
      // Insert new entry
      items[index] = Entry<KeyType, ItemType>(newItem, searchKey);
      itemCount++; // Increase count of entries
   }  // end if
   
   return ableToInsert;
}  // end add

template <class KeyType, class ItemType>
bool ArrayDictionary<KeyType, ItemType>::remove(const KeyType& searchKey) {
    // Find index of the item to be deleted
    int currentIdx = findEntryIndex(0, itemCount-1, searchKey);

    // If item can be deleted
    if (!isEmpty() && currentIdx >= 0) {
        // Shift all items to the left
        while (currentIdx < itemCount - 1) {
            items[currentIdx] = items[currentIdx + 1];
            ++ currentIdx;
        }
        // Decrease itemCount
        --itemCount;
        return true;
    }
    else
    {
        return false;
    }
    
}
  
template <class KeyType, class ItemType>
void ArrayDictionary<KeyType, ItemType>::clear()
{
    // Destroy dictionary resets dictionary
    destroyDictionary();
}
  
template <class KeyType, class ItemType>
ItemType ArrayDictionary<KeyType, ItemType>::getItem(const KeyType& searchKey) const throw (NotFoundException)
{
    // Find index using search key
    int findIdx = findEntryIndex(0, itemCount - 1, searchKey);

    // Throw exception if index is less than 0
    if (findIdx < 0)
        throw NotFoundException("Item is not in the Dictionary!");

    // Return item at the index
    return items[findIdx].getItem();
}
 
template <class KeyType, class ItemType>
bool ArrayDictionary<KeyType, ItemType>::contains(const KeyType& searchKey) const
{
    // Try to find the index
    int findIdx = findEntryIndex(0, itemCount - 1, searchKey);
    // Return true if the value is within correct range
    return (findIdx >= 0);
}
   
template <class KeyType, class ItemType>
/** Traverses the items in this dictionary in sorted search-key order
     and calls a given client function once for each item. */
void ArrayDictionary<KeyType, ItemType>::traverse(void visit(ItemType&)) const
{
    for (int i = 0; i < itemCount; ++i) {
        ItemType currentItem = items[i].getItem();
        visit(currentItem);
    }
    cout << endl;
}