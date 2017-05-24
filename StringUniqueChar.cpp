#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;


/*
 * determine if a string have repeated char.
 */
bool isUnique(string s) {
  if (s.length() > 128) {
    return false;
  }

  bool charPresent[128];
  memset(charPresent, 0, sizeof(charPresent));
  for (int i = 0; i < s.length(); i++) {
    int val = s[i];
    if (charPresent[val]) {
      return false;
    }
    else {
      charPresent[val] = true;
    }
  }
  return true;
}

int main() {
  cout << isUnique("abb") << endl;
  cout << isUnique("ab") << endl;
}
