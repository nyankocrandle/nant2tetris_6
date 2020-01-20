#ifndef _SYMBOL_TABLE_
#define _SYMBOL_TABLE_
#include <string>
class SymbolTable {
 private:
 public:
  SymbolTable();
  void addEntry(std::string symbol, int address);
  bool contains(std::string symbol);
  int getAddress(std::string symbol);
};
#endif