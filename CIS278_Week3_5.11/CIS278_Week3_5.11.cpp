/*************************************************************************
* Title: Find the Smallest Value
* File: CIS278_Week3_5.11.cpp
* Author: James Eli
* Date: 1/25/2018
*
* Exercise 5.11 on page 206. Write an application that finds the smallest 
* of several integers. Assume that the first value read specifies the 
* number of values to input from the user.
*
* Notes:
* (1) As usual, the majority of the program is consumed with performing 
*     input validation.
* (2) Uses STL regular expressions and iterator libraries to parse and 
*     validate numeric input.
* (3) Compiled with MS Visual Studio 2017 Community (v141).
*
* Submitted in partial fulfillment of the requirements of PCC CIS-278.
*************************************************************************
* Change Log:
*   01/25/2018: Initial release. JME
*************************************************************************/
#include <iostream>  // cout/endl
#include <string>    // getline/string/stoi
#include <vector>    // vector
#include <regex>     // regular expression

using namespace std;

// Parse input string for integer values and inserts them into a vector.
void parseInts(const string& s, vector<int>& vect) 
{
	regex rexp("[\\-]?(\\d+)");
	regex_iterator<string::const_iterator> rit(s.begin(), s.end(), rexp), rend;
	transform (
		rit, rend, back_inserter(vect), 
		// Lambda expression begins.
		[] (const regex_iterator<string::const_iterator>::value_type& it) { return stoi(it[0]); }
		// Lambda expression ends.
	);
}

int main()
{
	int count = { -1 };  // Count of elements in vector list.
	vector<int> numList; // Contains count of elements, followed by numbers to process.

	cout << "This program finds the smallest value in a list of up to 10 integers.\n";
	// Validate and process user input.
	do {
		string input; // Temporarily holds user input.

		// Exit input loop.
		if (count == 0)	break;

		// Limit list size.
		if (count < 0 || count > 10)
		{
			cout << "Enter number of integers in list: ";
			numList.clear();
		}
		else
			// Prompt for individual integer.
			cout << "Enter integer # " << numList.size() << ": ";
		// Get user input and parse.
		getline(cin, input);
		parseInts(input, numList);
		// Update count.
		if (!numList.empty()) count = numList.at(0);
	} while (static_cast<int>(numList.size()) < count + 1);

	// Ignore first element in vector list, it's the count of elements.
	if (!numList.empty() && numList.at(0) > 0)
		cout << "Smallest value is " << *min_element(numList.begin() + 1, numList.end()) << endl;
	else
		cout << "No valid numbers entered.\n";
}
