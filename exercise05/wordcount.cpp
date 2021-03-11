// Starter code for Exercise-05
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>

bool increasingSort(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b) {
	return (a.second > b.second);
}

int main() {
    
	std::ifstream file("mobydick.txt");
	std::string word;
	std::map<std::string, int> instances;
	int count = 1;
	std::vector<std::pair<std::string, int>> sortMap;
	

	if (!file) {
		std::cout << "could not open file" << std::endl;
		return EXIT_FAILURE;
	}
	else {
		while (file >> word) {
			std::string words;
			for (int i = 0; i < word.length(); i++) {
				words += tolower(word[i]);

				
			}

			++instances[words];
		}
		
		for (auto i = instances.begin(); i != instances.end(); i++) {
			sortMap.push_back(std::make_pair(i->first, i->second));
		}
	}

	std::sort(sortMap.begin(), sortMap.end(), increasingSort);

	for (int i = 0; i < 10; i++) {
		std::cout << count++ << ". " << sortMap[i].first << ": " << sortMap[i].second << " times" << std::endl;
	}



    return EXIT_SUCCESS;
}
