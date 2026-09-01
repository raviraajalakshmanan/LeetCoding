#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

class LicensePlateGenerator {
private:
  long long nextId = 0;

  static constexpr long long LETTER_COMBINATIONS = 26LL * 26 * 26;

  static constexpr long long MAX_PLATES = LETTER_COMBINATIONS * 1000;

  string encodeLetters(long long value) {
    string letters(3, 'A');

    for (int i = 2; i >= 0; --i) {
      letters[i] = 'A' + (value % 26);
      value /= 26;
    }

    return letters;
  }

  string encode(long long id, const string &pattern) {
    string result(pattern.size(), ' ');

    for (int i = pattern.size() - 1; i >= 0; --i) {
      if (pattern[i] == 'D') {
        result[i] = '0' + (id % 10);
        id /= 10;
      } else if (pattern[i] == 'L') {
        result[i] = 'A' + (id % 26);
        id /= 26;
      }
    }

    if (id != 0) {
      throw runtime_error("Plate space exhausted");
    }

    return result;
  }

public:
  string generate() {
    if (nextId >= MAX_PLATES) {
      throw runtime_error("No license plates remaining");
    }

    long long id = nextId++;

    int number = id % 1000;
    long long letterPart = id / 1000;

    string letters = encodeLetters(letterPart);

    stringstream ss;
    ss << letters << setw(3) << setfill('0') << number;

    return ss.str();
  }
};