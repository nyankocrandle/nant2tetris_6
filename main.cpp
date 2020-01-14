#include <fstream>
#include <iostream>
#include "Parser.h"
#include "Pcommand.h"

using namespace std;

int main() {
  string fname;
  ifstream fp;
  CommandType ctype;
  cout << "input open filename : ";
  cin >> fname;
  fp.open(fname);
  if (!fp) {
    cout << "cant open file\n";
  }
  Parser p(&fp);
  int i;
  while (p.hasMoreCommands()) {
    p.advance();
    ctype = p.commandType();
    switch (ctype) {
      case A_COMMAND:
        //printf("A");
        break;
      case C_COMMAND:
        //printf("C");
        break;
      case L_COMMAND:
        //printf("L");
        break;
    }
    i++;
    cout << i;
    if(i>20) break;
  }
  printf("End of fire");
  fp.close();
}