// TelesccopeCodilityTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

string solution(string& S, vector<int>& A) {
    string result;
    size_t player = 0; // initial pos

    do {
        result += S[player];
        player = A[player];
    } while (player);

    return result;
}


int main()
{
    std::cout << "Hello World!\n";
}