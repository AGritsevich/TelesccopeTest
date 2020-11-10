#include <iostream>
#include <vector>
#include <bitset>
#include <iomanip>

void print_binary(int n) {
  auto size = sizeof(int) * 8;
  std::vector<int> binary;
 
  std::cout << std::setfill('0') << std::setw(10) << n << " : ";
 
  do {
    std::cout << n % 2;
    binary.push_back((n % 2));

    n /= 2;
  } while (n);

  size_t limit = size - binary.size();
  std::cout << std::string(limit, '0');

  //while (!binary.empty()) {
    //std::cout << binary.back();
    //binary.pop_back();
  //}

  std::cout << std::endl;
}

int solution(int N) {
    int largest = 0;
    int shift = 0;
    int32_t temp = N;
    std::cout << std::setw(10) << temp << " : " 
              << std::bitset<32>(temp) << "  /shift: 0" << std::endl;

    for (int i = 1; i < 30; ++i) {
        int index = (temp & 0x00000001);
        temp = ((temp >> 1) | (index <<  29));
        std::cout << std::setw(10) << temp << " : " << std::bitset<32>(temp) 
                  << "  /shift: " << i << std::endl;
        if (temp > largest) {
            largest = temp;
            shift = i;
        }
    }
    return shift;
}

int main() {
    char answer = 0;
    int in_data = 32; // less manual check
    //while (answer != 'c') {
    while (std::cin >> answer) {
      if (answer == 'c') break;
      std::cout << "\x1B[2J\x1B[H";
      std::cout << "Answer: " << solution(in_data++);
      //std::cin >> answer;
    }
    return 0;
}
