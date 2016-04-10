//
//  main.cpp
//  CS32_Homework_1
//
//  Created by Zegao Liu on 16/4/9.
//  Copyright © 2016 Zegao Liu. All rights reserved.
//

#include "Set.h"
#include <iostream>
#include <string>
#include <cassert>
	using namespace std;

	int main()
	{
		Set s;
		assert(s.empty());
		ItemType x = "arepa";
		assert(!s.get(42, x) && x == "arepa"); // x unchanged by get failure
		s.insert("chapati");
		assert(s.size() == 1);
		assert(s.get(0, x) && x == "chapati");
		cout << "Passed all tests" << endl;
	}

