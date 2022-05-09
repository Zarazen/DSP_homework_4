#include <iostream>
#include <fstream>
#include "trinaryTree.h"

int main() {

	char path[64];
	std::cout << "Enter path\n";
	std::cin >> path;

	std::ifstream read;
	read.open(path, std::ios::binary);
	if (!read.is_open()) {

		std::cout << "Couldn't open file\n";
		return 0;

	}

	TrinaryTree theTree;

	try {

		theTree.getInput(read);

	}
	catch (std::bad_alloc) {

		std::cout << "Insufficient memory\n";
		read.close();
		return 0;

	}

	read.close();

	try {

		if (!theTree.checkIfTrinaryTree()) {

			std::cout << "Not a trinary tree\n";
			return 0;

		}

		theTree.getWords();
		theTree.print();

	}
	catch (std::bad_alloc) {

		std::cout << "Insufficient memory\n";

	}

	return 0;

}