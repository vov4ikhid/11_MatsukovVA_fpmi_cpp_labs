#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string& line) {
    std::vector<std::string> words;
    std::string word;
    for (char c : line) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
    return words;
}
int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");    
    if (!in) {
        std::cout << "Error opening file!" << std::endl;
        std::exit(1);
    }
    std::string word1, word2;
    in >> word1 >> word2;
    
    std::string temp;
    std::getline(in, temp);
    
    std::cout << "Searching for words: '" << word1 << "' and '" << word2 << "'" << std::endl;
    
    std::string line;
    while (std::getline(in, line)) {
        std::vector<std::string> words = split(line);
        
        int pos1 = -1, pos2 = -1;
        for (int i = 0; i < words.size(); i++) {
            if (pos1 == -1 && words[i] == word1) {
                pos1 = i;
            }
            if (pos2 == -1 && words[i] == word2) {
                pos2 = i;
            }
        }
        
        if (pos1 != -1 && pos2 != -1) {
            std::string temp = words[pos1];
            words[pos1] = words[pos2];
            words[pos2] = temp;
        }
        
        for (int i = 0; i < words.size(); i++) {
            if (i > 0) out << " ";
            out << words[i];
        }
        out << std::endl;
    }
    
    in.close();
    out.close();
    std::cout << "Done! Result in output.txt" << std::endl;
    
    return 0;
}