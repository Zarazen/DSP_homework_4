#include <iostream>
#include <fstream>
#include <stack>
#include "trinaryTree.h"

TrinaryTree::TrinaryTree() {



}

void TrinaryTree::getInput(std::ifstream& read) {

	char buff;
	int size = sizeof(buff);

	while (true) {

		read.read((char*)& buff, size);

		if (!read)
			break;

		input.push_back(buff);

	}

}

bool TrinaryTree::checkIfTrinaryTree() {

	if (!checkIfBracketsAreGood())
		return false;

	if (!checkSegment(0, input.size()))
		return false;

	return true;

}

void TrinaryTree::getWords() {

	int numberOpenBrackets = 0, sizeInput = input.size(), sizeOutput;

	for (int i = 0; i < sizeInput; ++i) {

		if (input[i] == '(')
			++numberOpenBrackets;

		if (input[i] == ')')
			--numberOpenBrackets;

		if (input[i] >= 'a' && input[i] <= 'z') {

			sizeOutput = output.size();
			if (sizeOutput < numberOpenBrackets)
				output.push_back(std::vector<char>());

			output[numberOpenBrackets - 1].push_back(input[i]);

		}

	}

}

void TrinaryTree::print() {

	int numWords = output.size();

	for (int i = 0; i < numWords; ++i) {

		output[i].push_back('\0');
		char* word = output[i].data();
		std::cout << word << std::endl;

	}

}

bool TrinaryTree::checkIfBracketsAreGood() {

	std::stack<char> bracketCounter;
	int size = input.size();

	for (int i = 0; i < size; ++i) {

		if (input[i] == '(')
			bracketCounter.push(input[i]);

		if (input[i] == ')') {

			if (bracketCounter.empty())
				return false;

			bracketCounter.pop();

		}

	}

	if (bracketCounter.empty())
		return true;

	return false;

}

bool TrinaryTree::checkSegment(const int& beg, const int& end) {

	if (input[beg + 1] < 'a' || input[beg + 1] > 'z')
		return false;

	int insideTrees = 0;

	for (int i = beg + 1; i < end; ++i) {

		if (input[i] == '*')
			++insideTrees;

		if (input[i] == '(') {

			int endOfSegment = findEndOfSegment(i);
			if (!checkSegment(i, endOfSegment))
				return false;

			i = endOfSegment;
			++insideTrees;


		}

	}

	if (insideTrees != 3)
		return false;

	return true;

}

int TrinaryTree::findEndOfSegment(const int& beg) {

	int numberOpenBrackets = 0;
	int size = input.size();

	for (int i = beg; i < size; ++i) {

		if (input[i] == '(')
			++numberOpenBrackets;

		if (input[i] == ')')
			--numberOpenBrackets;

		if (numberOpenBrackets == 0)
			return i;

	}

}
