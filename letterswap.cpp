//Write a function, called "letter_swap" that
//takes a const reference to a string as its only parameter and returns a string. 
//For every letter (A-Za-z) in the string, 
//replace it with its "opposite" in the alphabet. For instance,
//'a' is replaced with 'z' and 'Y' is replaced with 'B'. 
//All other characters should be left unchanged.
#include <string>
#include <cctype>

char opposite_letter(const char & c) {
  if (!std::isalpha(c)) {
    return c; 
  }
  char letter = c;
  bool is_uppercase = std::isupper(letter);
  if (is_uppercase) {
    letter = std::tolower(letter);
  }
  int index = letter - 'a';
  int midpoint = ('z' - 'a') / 2;
  char new_letter = '?';
  if (index <= midpoint) {
    new_letter = 'z' - index;
  } else {
    new_letter = ('z' - 'a') - index + 'a';
  }
  if (is_uppercase) {
    new_letter = std::toupper(new_letter);
  }
  return new_letter;
}

std::string letter_swap(const std::string & input) {
  std::string result;
  for (auto c : input) {
    result += opposite_letter(c);
  }
  return result;
}
