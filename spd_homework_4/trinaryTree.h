#include <vector>

#ifndef _trinaryTree_h_
#define _trinaryTree_h_

class TrinaryTree {

public:

	TrinaryTree();

	void getInput(std::ifstream& read);
	bool checkIfTrinaryTree();
	void getWords();
	void print();

private:

	bool checkIfBracketsAreGood();
	bool checkSegment(const int& beg, const int& end);
	int findEndOfSegment(const int& beg);

	TrinaryTree(const TrinaryTree& dummy) = delete;
	TrinaryTree& operator=(const TrinaryTree& dummy) = delete;

	std::vector<char> input;
	std::vector<std::vector<char> >output;

};

#endif // !_trinaryTree_h_

