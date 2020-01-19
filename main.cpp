#include <bitset>
#include <fstream>
#include <iostream>
#include "Code.h"
#include "Parser.h"
#include "Pcommand.h"

using namespace std;

int main() {
  string fname;
  ifstream ifp;
  ofstream ofp;
  CommandType ctype;
  cout << "input open filename : \n";
  // cin >> fname;
  fname = "C:\\Users\\shin\\Documents\\nand2tetris\\projects\\06\\add\\Add.asm";
  ifp.open(fname);
  if (!ifp) {
    cout << "cant open asm file\n";
  }

  ofp.open("add.hack");
  if (!ofp) {
    cout << "cant open hack file\n";
  }

  Parser p(&ifp);
  Code code;
  std::string symbol_str;
  while (p.hasMoreCommands()) {
    p.advance();
    ctype = p.commandType();
    switch (ctype) {
      case A_COMMAND:
        symbol_str = p.symbol();
        int symbol_int;
        symbol_int = atoi(symbol_str.c_str());
        ofp << std::bitset<16>(symbol_int);
        break;
      case C_COMMAND:
        ofp << "111";
        ofp << code.comp(p.comp());
        ofp << code.dest(p.dest());
        ofp << code.jump(p.jump());
        break;
      case L_COMMAND:
        break;
    }
    ofp << std::endl;
  }
  printf("End of fire");
  ifp.close();
  ofp.close();
}