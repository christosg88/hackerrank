// https://www.hackerrank.com/challenges/sum-vs-xor
#include <bits/stdc++.h>
#include <cmath>

std::string ltrim(const std::string &);
std::string rtrim(const std::string &);

long sumXor(long n) {
  int num_bits = ((int)std::log2(n)) + 1;
  long count = 0;
  for (int i = 0; i < num_bits; ++i) {
    count += !(n & 1);
    n >>= 1;
  }
  return 1UL << count;
}

int main() {
  std::ofstream fout(getenv("OUTPUT_PATH"));

  std::string n_temp;
  std::getline(std::cin, n_temp);

  long n = std::stol(ltrim(rtrim(n_temp)));

  long result = sumXor(n);

  std::cout << result << "\n";
  fout << result << "\n";

  fout.close();

  return 0;
}

std::string ltrim(const std::string &str) {
  std::string s(str);

  s.erase(s.begin(), find_if(s.begin(), s.end(), not1(std::ptr_fun<int, int>(isspace))));

  return s;
}

std::string rtrim(const std::string &str) {
  std::string s(str);

  s.erase(find_if(s.rbegin(), s.rend(), not1(std::ptr_fun<int, int>(isspace))).base(), s.end());

  return s;
}

