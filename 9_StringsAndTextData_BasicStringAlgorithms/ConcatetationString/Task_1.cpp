#include <iostream>

int main() {
   std::string str, word;
   int count_words = 0;
   std::getline(std::cin, str);
   std::cin >> word;
   for(int i = 0; i < str.length(); ++i) {
       if(word[0] == str[i]){
           bool found_word = true;
           for(int j = 0; j < str.length() && j < word.length(); ++j) {
               if(word[j] == str[i + j]){
                   continue;
               }
               else
                   found_word = false;
           }
           if(found_word)
               count_words++;
       }
   }
   std::cout << count_words << "\n";
}