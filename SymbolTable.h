#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_
#include <map>
#include <string>

class SymbolTable {
 private:
  std::map<std::string, int> symboltable;

 public:
  SymbolTable();
  void addEntry(std::string symbol, int address);
  bool contains(std::string symbol);
  int getAddress(std::string symbol);
};
#endif