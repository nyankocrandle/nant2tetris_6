#include "Parser.h"
#include <fstream>
#include <iostream>
#include "Pcommand.h"

Parser::Parser(std::ifstream* fp) {
  firstread = true;
  ifp = fp;
  command = "";
}

bool Parser::hasMoreCommands() {
  if (firstread) {
    firstread = false;
    return true;
  }
  if (ifp->eof()) return false;
  return true;
}

void Parser::advance() {
  std::getline(*ifp, command);
  std::cout << command << std::endl;
}

CommandType Parser::commandType() {
  char initial = command[0];
  if (initial == '@') return A_COMMAND;
  if (initial == '(') return L_COMMAND;
  return C_COMMAND;
}
