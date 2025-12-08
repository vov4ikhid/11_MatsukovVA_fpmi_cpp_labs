#include <iostream>
#include <vector>
#include <string>
bool isLetter(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
} 
std::vector<std::string> WordSeparation(const std::string string) {
  std::vector<std::string> words;
   if(string.empty()) {
     return words;
   }
   std::string word;
    for (int i = 0; i < string.length(); ++i) {
      char c = string[i];
      if(isLetter(c)) {
        word += c;
      }
      else if(!word.empty()) {
        words.push_back(word);
        word = "";
      }
    }
    if(!word.empty()) {
        words.push_back(word);
    }
    return words;
}
int main() {
  std::string str1, str2;
    std::cout << "Enter first string: ";
      if(!std::getline(std::cin, str1)) {
        std::cout << "Error of string input";
        std::exit(1);
      }
     std::cout << "Enter second string: ";
       if(!std::getline(std::cin, str2)) {
         std::cout << "Error of string input";
         std::exit(1);
       }

  if (str1.empty()) {
    std::cout << str2;
    std::exit(1);
  }
  else if (str2.empty()) {
    std::cout << str1;
    std::exit(1);
  }
  else if (str1.empty() && str2.empty()) {
    std::cout << "Strings are empty";
    std::exit(1);
  }
  std::vector<std::string> words1 = WordSeparation(str1);
  std::vector<std::string> words2 = WordSeparation(str2);
  std::string str3;
    int count_of_words = words1.size();
    if (words2.size() < count_of_words) { 
      count_of_words = words2.size();
    }
  for (int i = 0; i < count_of_words; ++i) {
    if (!str3.empty()) { 
    str3 += " ";
    }
    str3 += words1[i] + " " + words2[i];
  }
  for (int i = 0; i < count_of_words; ++i) {
    if (!str3.empty()) {
      str3 += " ";
    }
    str3 += words1[i];
  }
  for (int i = 0; i < count_of_words; ++i) {
    if (!str3.empty()) {
      str3 += " ";
    }
    str3 += words2[i];
  }
  std::cout << "New string: " << str3 << "\n";
  return 0;
}