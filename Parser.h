#ifndef _PARSER_
#define _PARSER_
#include <fstream>
#include <string>
#include "Pcommand.h"

class Parser {
 private:
  std::ifstream* ifp;
  bool firstread;
  std::string command;
  std::string nextcommand;

 public:
  Parser(std::ifstream* fp);
  bool hasMoreCommands();
  void advance();
  CommandType commandType();
  std::string symbol();
  std::string dest();
  std::string comp();
  std::string jump();
};
#endif