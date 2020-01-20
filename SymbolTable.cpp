#include "SymbolTable.h"
#include <map>
#include <string>

SymbolTable::SymbolTable() {
  addEntry("SP", 0);
  addEntry("LCL", 1);
  addEntry("ARG", 2);
  addEntry("THIS", 3);
  addEntry("THAT", 4);
  std::string label;
  for (int i = 0; i < 16; i++) {
    label = "R" + std::to_string(i);
    addEntry(label, i);
  }
  addEntry("SCREEN", 16384);
  addEntry("KBD", 24576);
}

void SymbolTable::addEntry(std::string symbol, int address) {
  symboltable[symbol] = address;
}

bool SymbolTable::contains(std::string symbol) {
  auto itr = symboltable.find(symbol);
  if (itr != symboltable.end()) return true;
  return false;
}

int SymbolTable::getAddress(std::string symbol) { return symboltable[symbol]; }