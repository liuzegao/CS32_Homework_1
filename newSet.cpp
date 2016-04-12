//
//  Set.cpp
//  CS32_Homework_1_5
//
//  Created by Zegao Liu on 16/4/9.
//  Copyright © 2016 Zegao Liu. All rights reserved.
//

#include "newSet.h"
#include <iostream>
#include <string>
using namespace std;


//Creat an dynamically allocated ItemType array Set and intialize it with emplty "".

Set::Set(int size)
{
    m_Setsize = size;
    m_Set = new ItemType[m_Setsize];
    m_Setcheck = new bool[m_Setsize];
    //Initialize the set with "" and make all the entries invalid
    for(int i=0; i < m_Setsize; i++)
    { 
        m_Setcheck[i] = false;
    }
    
}

Set::Set()
{
    m_Setsize = m_DEFAULT_MAX_ITEMS;
    m_Set = new ItemType[m_Setsize];
    m_Setcheck = new bool[m_Setsize];
    //Initialize the set with "" and make all the entries invalid
    for(int i=0; i < m_Setsize; i++)
    {
        m_Setcheck[i] = false;
    }
}


    
Set::~Set()
{
    delete [] m_Set;
    delete [] m_Setcheck;
}
 



// Return true if the set is empty, otherwise false.

bool Set::empty() const
{
    
    for(int i=0; i < m_Setsize; i++)
        if( m_Setcheck[i] == true)
        {
            cerr << "Error: Set is not empty" <<endl;
            return false;
        }
    return true;
}


// Return the number of items in the set.

int Set::size() const
{
    //Initialize the size of used slots to 0
    int size=0;
    
    //Go through the set and find the number of slot that is not empty and record them into size;
    for(int i=0; i < m_Setsize; i++)
        if( m_Setcheck[i] == true)
            size++;
    
    return size;
}


// Insert value into the set if it is not already present.  Return
// true if the value was actually inserted.  Leave the set unchanged
// and return false if the value was not inserted (perhaps because it
// is already in the set or because the set has a fixed capacity and
// is full).

bool Set::insert(const ItemType& value)
{
    //Check if the set is full, if full cerr "Set is full"
    if(size() >= m_Setsize)
    {   cerr << "Error: Set is full" << endl;
        return false;
    }
    
    //Check if value is alreay presented
    for(int i=0; i < m_Setsize; i++)
        //Check if this position i is valid etnry
        if( m_Setcheck[i] == true)
            //Check if the value of this entry is the same as value
            if(m_Set[i] == value)
            {
                cerr << "Error: Input value is already presented" << endl;
                return false;
            }
    
    //Find the closet empty slot from Set[0] the start point and insert the value in it. m_Setsize + 1
    for(int i=0; i < m_Setsize; i++)
        if( m_Setcheck[i] == false)
        {
            //Set m_Set[i] with value
            m_Set[i] = value;
            //Make this entry a valid entry
            m_Setcheck[i] = true;
            return true;
        }
    
    // If somehow I cannot insert the value, return false anyway.
    return false;
}


// Remove the value from the set if present.  Return true if the
// value was removed; otherwise, leave the set unchanged and
// return false.

bool Set::erase(const ItemType& value)
{
    //Check if value is presented if so then erase it.
    for(int i=0; i < m_Setsize; i++)
        //Check if this entry is valid;
        if(m_Setcheck[i] == true)
            //Check if this valid entry has value
            if( m_Set[i] == value)
            {
                //Clean the content of m_Set[i]
                //m_Set[i] = "";
                //Make this entry invalid
                m_Setcheck[i] = false;
                return true;
            }
    return false;
}


// Return true if the value is in the set, otherwise false.

bool Set::contains(const ItemType& value) const
{
    //Go through the set and see if the value is in the set.
    for(int i=0; i < m_Setsize; i++)
        if(m_Setcheck[i] == true)
            if( m_Set[i] == value)
            {
                return true;
            }
    //If not, return false.
    return false;
}


// If 0 <= i < size(), copy into value an item in the set and
// return true.  Otherwise, leave value unchanged and return false
// (See below for details about this function.)

bool Set::get(int i, ItemType& value) const
{
    //Check if i<0 or i >= size(), if so return false
    if( i<0 || i>= this->size())
        return false;
    
    //If i is within the range, copy into value into position i and return true
    for(int k=0; k < m_Setsize; k++)
        if(m_Setcheck[k] == true)
            if(k == i)
            value = m_Set[k];
    return true;
}


// Exchange the contents of this set with the other one
void Set::swap(Set& other)
{
    //Creat a temp Set that copys the other Set
    ItemType* temp_m_Set = nullptr;
    temp_m_Set = other.m_Set;
    
    bool* temp_m_Setcheck = nullptr;
    temp_m_Setcheck = other.m_Setcheck;
    int temp_m_Setsize = other.m_Setsize;
    
    other.m_Set = m_Set;
    other.m_Setcheck = m_Setcheck;
    other.m_Setsize = m_Setsize;
    
    
    
    m_Set = temp_m_Set;
    m_Setcheck = temp_m_Setcheck;
    m_Setsize = temp_m_Setsize;
    
    temp_m_Set = nullptr;
    temp_m_Setcheck = nullptr;
    
    
    /*
     //Copy m_Set[] into other.m_Set[]
    for(int i=0; i< other.m_Setsize; i++)
    {
        temp.m_Set[i] = other.m_Set[i];
        temp.m_Setcheck[i] =other.m_Setcheck[i];
        
    }


    
               //Clean other.m_Set[] with ""
               //for(int i=0; i< m_DEFAULT_MAX_ITEMS; i++)
               //other.m_Set[i] = "";
    
               //Make the other.m_Setsize = m_Setsize
               //other.m_Setsize = m_Setsize;
    
    
    other.m_Setsize = m_Setsize;
    
    //Copy m_Set[] into other.m_Set[]
    for(int i=0; i< m_Setsize; i++)
    {
        other.m_Set[i] = m_Set[i];
        other.m_Setcheck[i] =m_Setcheck[i];
      
    }
    
    
              //Clean m_Set[] with ""
              //for(int i=0; i< m_DEFAULT_MAX_ITEMS; i++)
              // m_Set[i] = "";
    
    
     m_Setsize = temp.m_Setsize;
    //Copy temp.m_Set[] into m_Set[]
    for(int i=0; i< temp.m_Setsize; i++)
    {
        m_Set[i] = temp.m_Set[i];
        m_Setcheck[i] = temp.m_Setcheck[i];

    }
    
    //Make the m_Setsize = temp_Setsize
     */
    
}


//Exam before turn in : Delete

void Set::Print(int i)
{
    cout <<m_Set[i]<<endl;
}

void Set::put(int i, unsigned long& value)
{
    m_Set[i] = value;
    
}



