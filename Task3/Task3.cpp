// Task3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int solution(vector<int>& A) {
  int minimal_dist = (int)A.size();

  for (int P = 0; P < (int)A.size(); P++) {
    for (int Q = 0; Q < (int)A.size(); Q++) {

      if (P == Q || A[P] == A[Q]) break; // scrutch

      bool exist = false;
      for (int D = (A[P] + 1); D <= A[Q]; D++) { // positive TODO for  minis

        for (int& i : A) {
          if (D == i) exist = true;
        }
      }

      if (exist) break;

      int dist = abs(P - Q);

      std::cout << P << ":" << Q << " = " << A[P] << ":" << A[Q] << std::endl;

      if (dist < minimal_dist) {
        minimal_dist = dist;
      }
    }
  }

  return minimal_dist == (int)A.size() ? -1 : minimal_dist;
}

int main()
{
  std::cout << "Hello World!\n";
  vector<int> in_data = {};
  return solution(in_data);
}
