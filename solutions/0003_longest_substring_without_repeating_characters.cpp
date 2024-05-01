#include <iostream>
#include <unordered_set>
using namespace std;

/*
  3. LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS
  Dada una cadena de caracteres, encontrar la longitud de la subcadena más larga que no contiene caracteres repetidos.

  - Ejemplo:
  Entrada: "abcabcbb"
  Salida: 3

  Explicación: La subcadena más larga sin caracteres repetidos es "abc", que tiene longitud 3.
*/

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int n = s.length();
    unordered_set<char> charSet;
    int maxLen = 0, i = 0, j = 0;
    while(i < n && j < n){
      if(charSet.find(s[j]) == charSet.end()){
        charSet.insert(s[j++]);
        maxLen = max(maxLen, j - i);
      } else {
        charSet.erase(s[i++]);
      }
    }
    return maxLen;
  }
};

int main(){
  string str = "abcabcbb";
  Solution solution;
  cout << solution.lengthOfLongestSubstring(str) << endl;

  return 0;
}