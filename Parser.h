#include <fstream>
#include <string>
#include "Pcommand.h"

class Parser
{
private:
 std::ifstream* ifp; 
 bool firstread;
 std::string command;
public:
  Parser(std::ifstream* fp);
  bool hasMoreCommands();
  void advance();
  CommandType commandType();
  //std::string symbol();
  //std::string dest();
  //std::string comp();
  //std::string jump();
};
