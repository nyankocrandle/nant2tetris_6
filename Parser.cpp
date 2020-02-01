#include "Parser.h"
#include <fstream>
#include <iostream>
#include "Pcommand.h"

Parser::Parser(std::ifstream* fp) {
  firstread = true;
  ifp = fp;
  command = "";
  nextcommand = "";
}

bool Parser::hasMoreCommands() {
  char c;
  std::string buff;
  nextcommand = "";
  while (!ifp->eof()) {
    std::getline(*ifp, buff);
    std::string::iterator str;
    for (str = buff.begin(); str != buff.end(); str++) {
      if (*str == ' ') continue;
      if (*str == '/') break;
      nextcommand += *str;
    }
    if (nextcommand != "") return true;
  }
  return false;
}

void Parser::advance() {
  command = nextcommand;
}

CommandType Parser::commandType() {
  char initial = command[0];
  if (initial == '@') return A_COMMAND;
  if (initial == '(') return L_COMMAND;
  return C_COMMAND;
}

std::string Parser::symbol() {
  std::string buff = "";
  std::string::iterator str;
  for (str = command.begin(); str != command.end(); str++) {
    if (*str == '@') continue;
    if (*str == '(') continue;
    if (*str == ')') continue;
    buff += *str;
  }
  return buff;
}

std::string Parser::dest() {
  std::string buff = "";
  std::string::iterator str;
  if (command.find("=") == std::string::npos) {
    return "null";
  }
  for (str = command.begin(); str != command.end(); str++) {
    if (*str == '=') break;
    buff += *str;
  }
  return buff;
}

std::string Parser::comp() {
  std::string buff = "";
  std::string::iterator str;
  if (command.find("=") != std::string::npos) {
    for (str = command.begin(); str != command.end(); str++) {
      if (*str == '=') break;
    }
    str++;
  } else {
    str = command.begin();
  }

  for (; str != command.end(); str++) {
    if (*str == ';') break;
    buff += *str;
  }
  return buff;
}

std::string Parser::jump() {
  std::string buff = "";
  std::string::iterator str;
  if (command.find(";") == std::string::npos) {
    return "null";
  }
  for (str = command.begin(); str != command.end(); str++) {
    if (*str == ';') break;
  }
  for (str++; str != command.end(); str++) {
    buff += *str;
  }
  return buff;
}