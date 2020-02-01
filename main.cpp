#include <bitset>
#include <fstream>
#include <iostream>
#include "Code.h"
#include "Parser.h"
#include "Pcommand.h"
#include "SymbolTable.h"

using namespace std;

int main(int argc, char *argv[]) {
  if (argc == 1) {
    std::cout << "error : input command line" << std::endl;
    return 1;
  }
  string fname;
  ifstream ifp;
  ofstream ofp;
  CommandType ctype;
  fname = "C:\\Users\\shin\\Documents\\nand2tetris\\projects\\06\\";
  fname += argv[1];
  cout << "input open filename : " << argv[1] << std::endl;
  ifp.open(fname);
  if (!ifp) {
    cout << "cant open asm file\n";
  }

  //一回目のパス
  Parser *p = new Parser(&ifp);
  SymbolTable st;
  std::string symbol_str;
  int code_row = 0;
  while (p->hasMoreCommands()) {
    p->advance();
    ctype = p->commandType();
    switch (ctype) {
      case A_COMMAND:
        code_row++;
        break;
      case C_COMMAND:
        code_row++;
        break;
      case L_COMMAND:
        symbol_str = p->symbol();
        if (!st.contains(symbol_str)) {
          st.addEntry(symbol_str, code_row);
        }
        break;
    }
  }

  ifp.close();
  delete p;

  ifp.open(fname);
  ofp.open("out.hack");
  if (!ofp) {
    cout << "cant open hack file\n";
  }

  p = new Parser(&ifp);
  Code code;
  int var_addres = 16;
  while (p->hasMoreCommands()) {
    p->advance();
    ctype = p->commandType();
    switch (ctype) {
      case A_COMMAND:
        symbol_str = p->symbol();
        int symbol_int;
        symbol_int = atoi(symbol_str.c_str());
        if (symbol_int == 0) {
          if (symbol_str != "0") {
            if (!st.contains(symbol_str)) {
              st.addEntry(symbol_str, var_addres++);
            }
            symbol_int = st.getAddress(symbol_str);
          }
        }
        ofp << std::bitset<16>(symbol_int);
        ofp << std::endl;
        break;
      case C_COMMAND:
        ofp << "111";
        ofp << code.comp(p->comp());
        ofp << code.dest(p->dest());
        ofp << code.jump(p->jump());
        ofp << std::endl;
        break;
      case L_COMMAND:
        break;
    }
  }
  ifp.close();
  ofp.close();
  std::cout << "end of fire" << std::endl;
}
