
// Headers 
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>	
#include "Quicksort.H"
#include "Mergesort.H"

using namespace std;

int main() {

	srand (time(NULL));

	int ints1[] = {2, 4, 3, 5, 7, 6, 8, 9, 11, 10};
	vector<int> v1(ints1, ints1 + sizeof(ints1) / sizeof(int));

	int ints2[] = {172,480,20,244,789,284,624,680,525,310,615,458,679,674,744,360,920,581,351,37,824,791,200,474,824,35,344,438,363,234,66,768,443,909,174};
	vector<int> v2(ints2, ints2 + sizeof(ints2) / sizeof(int));

	ifstream inFile1("100nums.txt");
	vector<int> v3;
	string line;
	while (inFile1 >> line) {
		v3.push_back(stoi(line));
	}
	inFile1.close();

	ifstream inFile2("1000nums.txt");
	vector<int> v4;
	string line2;
	while (inFile2 >> line2) {
		v4.push_back(stoi(line2));
	}
	inFile2.close();

	string p = "deterministic_qsort";

	vector<int> result1 = quicksort(v1, p);
	vector<int> result2 = quicksort(v2, p);
	vector<int> result3 = quicksort(v3, p);
	vector<int> result4 = quicksort(v4, p);

	return 0;

}
