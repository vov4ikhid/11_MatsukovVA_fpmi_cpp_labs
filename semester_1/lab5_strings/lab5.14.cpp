#include <iostream>
#include <string>

bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool getWord(const std::string& str, size_t& i, std::string& word) {
    word = "";
    
    while (i < str.length() && !isLetter(str[i])) {
        i++;
    }
    
    if (i >= str.length()) {
        return false;
    }
    
    while (i < str.length() && isLetter(str[i])) {
        word += str[i];
        i++;
    }
    
    return true;
}

std::string mergeStrings(const std::string& str1, const std::string& str2) {
    std::string str3;
    size_t i = 0, j = 0;
    std::string word1, word2;
    bool has_word1, has_word2;
    
    while (true) {
        has_word1 = getWord(str1, i, word1);
        has_word2 = getWord(str2, j, word2);
        
        if (!has_word1 && !has_word2) {
          break;
        }
        
        if (!str3.empty()) {
          str3 += " ";
        }
        if (has_word1) {
          str3 += word1;
        }
        if (has_word2) {
            if (has_word1) {
              str3 += " ";
            }
            str3 += word2;
        }
    }
    
    return str3;
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
    
    std::string str3 = mergeStrings(str1, str2);
    
    std::cout << "\nNew string: " << str3 << std::endl;
    
    return 0;
}