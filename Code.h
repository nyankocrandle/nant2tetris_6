#ifndef _CODE_
#define _CODE_
#include <string>

class Code {
 public:
  std::string dest(std::string mnemonic);
  std::string comp(std::string mnemonic);
  std::string jump(std::string mnemonic);
};

#endif