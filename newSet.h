//
//  Set.h
//  CS32_Homework_1_5
//
//  Created by Zegao Liu on 16/4/9.
//  Copyright © 2016 Zegao Liu. All rights reserved.
//

#ifndef newSet_h
#define newSet_h
#include <iostream>
#include <String>

typedef std::string ItemType;

class Set
{
public:
    Set(int size);         // Create a set with a size.
    
    
    //Exam before turn in:Can I add a public member data myself?
    Set(); //Creat a empty set
    
    //Exam before turn in:Shall I build a costum destructor?
    //~Set();
    
    
    bool empty() const;  // Return true if the set is empty, otherwise false.
    
    int size() const;    // Return the number of items in the set.
    
    bool insert(const ItemType& value);
    // Insert value into the set if it is not already present.  Return
    // true if the value was actually inserted.  Leave the set unchanged
    // and return false if the value was not inserted (perhaps because it
    // is already in the set or because the set has a fixed capacity and
    // is full).
    
    bool erase(const ItemType& value);
    // Remove the value from the set if present.  Return true if the
    // value was removed; otherwise, leave the set unchanged and
    // return false.
    
    bool contains(const ItemType& value) const;
    // Return true if the value is in the set, otherwise false.
    
    bool get(int i, ItemType& value) const;
    // If 0 <= i < size(), copy into value an item in the set and
    // return true.  Otherwise, leave value unchanged and return false.
    // (See below for details about this function.)
    
    void swap(Set& other);
    // Exchange the contents of this set with the other one.
    
    
    //Test data member
    
    //Print out the m_Set[i]
    void Print(int i);
    //Input value in m_Set[i]
    void put(int i, ItemType& value);
    
    
private:
    
    //Maximum size ??How do I make it always equals the maximum m_Set?
    const int m_DEFAULT_MAX_ITEMS = 100;
    
    //m_Setcheck checks if a specific entry in the array is valid
    bool m_Setcheck[100];
    
    //Pointer
    ItemType* m_Set;
    
    int m_Setsize;
    
};

#endif /* newSet_h */
