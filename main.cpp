//
//  main.cpp
//  CS32_Homework_1
//
//  Created by Zegao Liu on 16/4/9.
//  Copyright © 2016 Zegao Liu. All rights reserved.
//

#include "Set.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    Set s;
    assert(s.empty());
    ItemType x = 9876543;
    assert( !s.get(42, x)  &&  x == 9876543); // x unchanged by get failure
    s.insert(123456789);
    assert(s.size() == 1);
    assert(s.get(0, x)  &&  x == 123456789);
    cout << "Passed all tests" << endl;
	cin.ignore(1000, '\n');
}
