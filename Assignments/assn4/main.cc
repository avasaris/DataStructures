/**
* Course: CS 14 Summer 2016
*
* First Name: Courtney 
* Last Name: Kelly
* Username: ckell015
* email address: ckell015@ucr.edu
*
*
* Assignment: assn4
* Filename : main.cc
*
* I hereby certify that the contents of this file represent
* my own original indimostlyRandomIntidual work. Nowhere herein is there 
* code from any outside resources such as another indimostlyRandomIntidual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/

// Headers 
#include <iostream>
#include <string>
#include <vector>
#include <ctime>	
#include "Quicksort.H"
#include "Mergesort.H"

using namespace std;

int main() {

	srand (time(NULL));

    // Vector<int>
        // mostly-ordered
            int ints1[] = {2, 4, 3, 5, 7, 6, 8, 9, 11, 10};
            vector<int> mostlyOrderedInt(ints1, ints1 + sizeof(ints1) / sizeof(int));
        // mostly-random
            vector<int> mostlyRandomInt;
            mostlyRandomInt.push_back(10);
            mostlyRandomInt.push_back(6);
            mostlyRandomInt.push_back(8);
            mostlyRandomInt.push_back(4);
            mostlyRandomInt.push_back(2);
            mostlyRandomInt.push_back(12);
            mostlyRandomInt.push_back(14);
        
        // random 
            int myints[] = {172,480,20,244,789,284,624,680,525,310,615,458,679,674,744,360,920,581,351,37,824,791,200,474,824,35,344,438,363,234,66,768,443,909,174};            
            vector<int> randomInt(myints, myints + sizeof(myints) / sizeof(int) );

        // monotonically increasing
            int ints2[] = {2,3,4,5,6,7,8,9,10,11};
            vector<int> monIncreaseInt(ints2, ints2 + sizeof(ints2) / sizeof(int));
        // monotonically decreasing
            int ints3[] = {11,10,9,8,7,6,5,4,3,2};
            vector<int> monDecreaseInt(ints3, ints3 + sizeof(ints3) / sizeof(int));

    // Vector<string>
        // mostly-ordered
            string str4[] = {"bat", "fat", "cat", "hat", "gat", "mat", "pat", "tat", "sat", "rat"};
            vector<string> mostlyOrderedStr( str4, str4 + sizeof(str4) / sizeof(string));
        // mostly-random
            vector<string> mostlyRandomStr;
            mostlyRandomStr.push_back("pillow");
            mostlyRandomStr.push_back("cushion");
            mostlyRandomStr.push_back("couch");
            mostlyRandomStr.push_back("tissues");
            mostlyRandomStr.push_back("hat");
            mostlyRandomStr.push_back("magazine");
            mostlyRandomStr.push_back("remote");
            mostlyRandomStr.push_back("backpack");
        // random
            string str1[] = {"ijemrsqafq", "ohxvfjgtkq","qdbbifotiu", "asmjhvcdfc","yqcowhmqzs","ubvbolnyst","xpvhpurknr","cgdxrgkohd",
            "qmsltdnbpn","szreihlebv","xsblxmvdqn","cat", "hat", "akdjag","asruyailerfh", "dsjhfgds", "jpoiqlnkzy","lzblzbpqqs","kyjtuvpzbb","qqpiearoez","nirbzuduxv","butkotkeaw","amshnqlgsa",
            "htpyodwaxf","frzttmohar","hvzpwkpbkt","mjsibxbtzl","psnhuaztbn","vntxhxhxir","ybrdpwgneu","tpvhxxxpbl","achtrlurqf","tmtvobwexk","xtekjrrtej",
            "zbdgxuujfq"}; 
            vector<string> randomStr( str1, str1 + sizeof(str1) / sizeof(string));
        // monotonically increasing
            string str2[] = {"bat", "cat", "fat", "gat", "hat", "mat", "pat", "rat", "sat", "tat"};
            vector<string> monIncreaseStr( str2, str2 + sizeof(str2) / sizeof(string));
        // monotonically decreasing
            string str3[] = {"tat", "sat", "rat", "pat", "mat", "hat", "gat", "fat", "cat", "bat"};
            vector<string> monDecreaseStr( str3, str3 + sizeof(str3) / sizeof(string));

    // Quicksort
        string random = "random", median = "median_three", qselect = "random_qselect", dqsort = "deterministic_qsort", first = "first";
        cout << "---------------" << endl;
        cout << "QUICKSORT TESTS" << endl;
        cout << "---------------" << endl;
        cout << "Vector<int>" << endl;
        cout << "-----------" << endl;
    
        cout << "Mostly Ordered Vector<int>" << endl;
            cout << "Before: ";
            print(mostlyRandomInt);
            cout << "First Element Pivot:" << endl;
                vector<int> first1 = quicksort<int>(mostlyOrderedInt, first);
                print(first1);
            cout << "Random Pivot:" << endl;
                vector<int> result1 = quicksort<int>(mostlyOrderedInt, random);
                print(result1);
            cout << "Median of Three Pivot" << endl;
                vector<int> result2 = quicksort<int>(mostlyOrderedInt, median);
                print(result2);
            cout << "Quickselect Pivot" << endl;
                vector<int> result3 = quicksort<int>(mostlyOrderedInt, qselect);
                print(result3);
            cout << "Deterministic Quickselect Pivot" << endl;
                vector<int> result4 = quicksort<int>(mostlyOrderedInt, dqsort);
                print(result4);

        cout << "\nMostly Random Vector<int>" << endl;
            cout << "Before: ";
            print (mostlyRandomInt);
            cout << "First Element Pivot:" << endl;
                vector<int> first2 = quicksort<int>(mostlyRandomInt, first);
                print(first2);
            cout << "Random Pivot" << endl;
                vector<int> result5 = quicksort<int>(mostlyRandomInt, random);
                print(result5);
            cout << "Median of Three Pivot" << endl;
                vector<int> result6 = quicksort<int>(mostlyRandomInt, median);
                print(result6);
            cout << "Quickselect Pivot" << endl;
                vector<int> result7 = quicksort<int>(mostlyRandomInt, qselect);
                print(result7);
            cout << "Deterministic Quickselect Pivot" << endl;
                vector<int> result8 = quicksort<int>(mostlyRandomInt, dqsort);
                print(result8);

        cout << "\nRandom Vector<int>" << endl;
            cout << "Before: ";
            print(randomInt);
            cout << "First Element Pivot:" << endl;
                vector<int> first3 = quicksort<int>(randomInt, first);
                print(first3);
            cout << "Random Pivot" << endl;
                vector<int> result9 = quicksort<int>(randomInt, random);
                print(result9);
            cout << "Median of Three Pivot" << endl;
                vector<int> result10 = quicksort<int>(randomInt, median);
                print(result10);
            cout << "Quickselect Pivot" << endl;
                vector<int> result11 = quicksort<int>(randomInt, qselect);
                print(result11);
            cout << "Deterministic Quickselect Pivot" << endl;
                vector<int> result12 = quicksort<int>(randomInt, dqsort);
                print(result12);

        cout << "\nMonotonically Increasing Vector<int>" << endl;
            cout << "Before: ";
            print(monIncreaseInt);
            cout << "First Element Pivot:" << endl;
                vector<int> first4 = quicksort<int>(monIncreaseInt, first);
                print(first4);
            cout << "Random Pivot" << endl;
                vector<int> result13 = quicksort<int>(monIncreaseInt, random);
                print(result13);
            cout << "Median of Three Pivot" << endl;
                vector<int> result14 = quicksort<int>(monIncreaseInt, median);
                print(result14);
            cout << "Quickselect Pivot" << endl;
                vector<int> result15 = quicksort<int>(monIncreaseInt, qselect);
                print(result15);
            cout << "Deterministic Quickselect Pivot" << endl;
                vector<int> result16 = quicksort<int>(monIncreaseInt, dqsort);
                print(result16);

        cout << "\nMonotonically Decreasing Vector<int>" << endl;
            cout << "Before: ";
            print(monDecreaseInt);
            cout << "First Element Pivot:" << endl;
                vector<int> first5 = quicksort<int>(monDecreaseInt, first);
                print(first5);
            cout << "Random Pivot" << endl;
                vector<int> result17 = quicksort<int>(monDecreaseInt, random);
                print(result17);
            cout << "Median of Three Pivot" << endl;
                vector<int> result18 = quicksort<int>(monDecreaseInt, median);
                print(result18);
            cout << "Quickselect Pivot" << endl;
                vector<int> result19 = quicksort<int>(monDecreaseInt, qselect);
                print(result19);
            cout << "Deterministic Quickselect Pivot" << endl;
                vector<int> result20 = quicksort<int>(monDecreaseInt, dqsort);
                print(result20);

        cout << "\n--------------" << endl;
        cout << "Vector<string>" << endl;
        cout << "--------------" << endl;

        cout << "\nMostly Ordered Vector<string>" << endl;
            cout << "Before: ";
            print(mostlyOrderedStr);
            cout << "First Element Pivot:" << endl;
                vector<string> first6 = quicksort<string>(mostlyOrderedStr, first);
                print(first6);
            cout << "Random Pivot" << endl;
                vector<string> result21 = quicksort<string>(mostlyOrderedStr, random);
                print(result21);
            cout << "Median of Three Pivot" << endl;
                vector<string> result22 = quicksort<string>(mostlyOrderedStr, median);
                print(result22);
            cout << "Quickselect Pivot" << endl;
                vector<string> result23 = quicksort<string>(mostlyOrderedStr, qselect);
                print(result23);
            cout << "Deterministic Quickselect Pivot" << endl;
                vector<string> result24 = quicksort<string>(mostlyOrderedStr, dqsort);
                print(result24);

        cout << "\nMostly Random Vector<string>" << endl;
            cout << "Before: ";
            print(mostlyRandomStr);
            cout << "First Element Pivot:" << endl;
                vector<string> first7 = quicksort<string>(mostlyRandomStr, first);
                print(first7);
            cout << "Random Pivot" << endl;
                vector<string> result25 = quicksort<string>(mostlyRandomStr, random);
                print(result25);
            cout << "Median of Three Pivot" << endl;
                vector<string> result26 = quicksort<string>(mostlyRandomStr, median);
                print(result26);
            cout << "Quickselect Pivot" << endl;
                vector<string> result27 = quicksort<string>(mostlyRandomStr, qselect);
                print(result27);
            cout << "Deterministic Quickselect Pivot" << endl; 
                vector<string> result28 = quicksort<string>(mostlyRandomStr, dqsort);
                print(result28);       

        cout << "\nRandom Vector<string>" << endl;
            cout << "Before: ";
            print(randomStr);
            cout << "First Element Pivot:" << endl;
                vector<string> first8 = quicksort<string>(randomStr, first);
                print(first8);
            cout << "Random Pivot" << endl;
                vector<string> result29 = quicksort<string>(randomStr, random);
                print(result29);
            cout << "Median of Three Pivot" << endl;
                vector<string> result30 = quicksort<string>(randomStr, median);
                print(result30);
            cout << "Quickselect Pivot" << endl;
                vector<string> result31 = quicksort<string>(randomStr, qselect);
                print(result31);
            cout << "Deterministic Quickselect Pivot" << endl;
                vector<string> result32 = quicksort<string>(randomStr, dqsort);
                print(result32);

        cout << "\nMonotonically Increasing Vector<string>" << endl;
            cout << "Before: ";
            print(monIncreaseStr);
            cout << "First Element Pivot:" << endl;
                vector<string> first9 = quicksort<string>(monIncreaseStr, first);
                print(first9);
            cout << "Random Pivot" << endl;
                vector<string> result33 = quicksort<string>(monIncreaseStr, random);
                print(result33);
            cout << "Median of Three Pivot" << endl;
                vector<string> result34 = quicksort<string>(monIncreaseStr, median);
                print(result34);
            cout << "Quickselect Pivot" << endl;
                vector<string> result35 = quicksort<string>(monIncreaseStr, qselect);
                print(result35);
            cout << "Deterministic Quickselect Pivot" << endl;
                vector<string> result36 = quicksort<string>(monIncreaseStr, dqsort);
                print(result36);

        cout << "\nMonotonically Decreasing Vector<string>" << endl;
            cout << "Before: ";
            print(monDecreaseStr);
            cout << "First Element Pivot:" << endl;
                vector<string> first10 = quicksort<string>(monDecreaseStr, first);
                print(first10);
            cout << "Random Pivot" << endl;
                vector<string> result37 = quicksort<string>(monDecreaseStr, random);
                print(result37);
            cout << "Median of Three Pivot" << endl;
                vector<string> result38 = quicksort<string>(monDecreaseStr, median);
                print(result38);
            cout << "Quickselect Pivot" << endl;
                vector<string> result39 = quicksort<string>(monDecreaseStr, qselect);
                print(result39);
            cout << "Deterministic Quickselect Pivot" << endl;
                vector<string> result40 = quicksort<string>(monDecreaseStr, dqsort);
                print(result40);
/*
    // Mergesort
        cout << "\n---------------" << endl;
        cout << "MERGESORT TESTS" << endl;
        cout << "---------------" << endl;
        cout << "Vector<int>" << endl;
        cout << "-----------" << endl;

        cout << "Mostly Ordered Vector<int>" << endl;
            cout << "Before: ";
            print(mostlyOrderedInt);
            vector<int> merged1 = mergesort<int>(mostlyOrderedInt);
            cout << "After: ";
            print(merged1);

        cout << "\nMostly Random Vector<int>" << endl;
            cout << "Before: ";
            print (mostlyRandomInt);
            vector<int> merged2 = mergesort<int>(mostlyRandomInt);
            cout << "After: ";
            print(merged2);

        cout << "\nRandom Vector<int>" << endl;
            cout << "Before: ";
            print(randomInt);
            vector<int> merged3 = mergesort<int>(randomInt);
            cout << "After: ";
            print(merged3);

        cout << "\nMonotonically Increasing Vector<int>" << endl;
            cout << "Before: ";
            print(monIncreaseInt);
            vector<int> merged4 = mergesort<int>(monIncreaseInt);
            cout << "After: ";
            print(merged4);

        cout << "\nMonotonically Decreasing Vector<int>" << endl;
            cout << "Before: ";
            print(monDecreaseInt);
            vector<int> merged5 = mergesort<int>(monDecreaseInt);
            cout << "After: ";
            print(merged5);

        cout << "\n--------------" << endl;
        cout << "Vector<string>" << endl;
        cout << "--------------" << endl;

        cout << "\nMostly Ordered Vector<string>" << endl;
            cout << "Before: ";
            print(mostlyOrderedStr);
            vector<string> merged6 = mergesort<string>(mostlyOrderedStr);
            cout << "After: ";
            print(merged6);

        cout << "\nMostly Random Vector<string>" << endl;
            cout << "Before: ";
            print(mostlyRandomStr);        
            vector<string> merged7 = mergesort<string>(mostlyRandomStr);
            cout << "After: ";
            print(merged7);

        cout << "\nRandom Vector<string>" << endl;
            cout << "Before: ";
            print(randomStr);
            vector<string> merged8 = mergesort<string>(randomStr);
            cout << "After: ";
            print(merged8);

        cout << "\nMonotonically Increasing Vector<string>" << endl;
            cout << "Before: ";
            print(monIncreaseStr);
            vector<string> merged9 = mergesort<string>(monIncreaseStr);
            cout << "After: ";
            print(merged9);

        cout << "\nMonotonically Decreasing Vector<string>" << endl;
            cout << "Before: ";
            print(monDecreaseStr);
            vector<string> merged10 = mergesort<string>(monDecreaseStr);
            cout << "After: ";
            print(merged10);
   */

	return 0;
}
