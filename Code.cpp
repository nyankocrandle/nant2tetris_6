#include "Code.h"
#include <bitset>

std::string Code::dest(std::string mnemonic) {
  if (mnemonic == "null") return "000";
  if (mnemonic == "M") return "001";
  if (mnemonic == "D") return "010";
  if (mnemonic == "MD") return "011";
  if (mnemonic == "A") return "100";
  if (mnemonic == "AM") return "101";
  if (mnemonic == "AD") return "110";
  return "111";
}

std::string Code::comp(std::string mnemonic) {
  if (mnemonic == "0") return "0101010";
  if (mnemonic == "1") return "0111111";
  if (mnemonic == "-1") return "0111010";
  if (mnemonic == "D") return "0001100";
  if (mnemonic == "A") return "0110000";
  if (mnemonic == "!D") return "0001101";
  if (mnemonic == "!A") return "0110000";
  if (mnemonic == "-D") return "0001111";
  if (mnemonic == "-A") return "0110011";
  if (mnemonic == "D+1") return "0011111";
  if (mnemonic == "A+1") return "0110111";
  if (mnemonic == "D-1") return "0001110";
  if (mnemonic == "A-1") return "0110010";
  if (mnemonic == "D+A") return "0000010";
  if (mnemonic == "D-A") return "0010011";
  if (mnemonic == "A-D") return "0000111";
  if (mnemonic == "D&A") return "0000000";
  if (mnemonic == "D|A") return "0010101";

  if (mnemonic == "M") return "1110000";
  if (mnemonic == "!M") return "1110001";
  if (mnemonic == "-M") return "1110011";
  if (mnemonic == "M+1") return "1110111";

  if (mnemonic == "M-1") return "1110010";
  if (mnemonic == "D+M") return "1000010";
  if (mnemonic == "D-M") return "1010011";
  if (mnemonic == "M-D") return "1000111";
  if (mnemonic == "D&M") return "1000000";
  return "1010101";
}

std::string Code::jump(std::string mnemonic) {
  if (mnemonic == "null") return "000";
  if (mnemonic == "JGT") return "001";
  if (mnemonic == "JEQ") return "010";
  if (mnemonic == "JGE") return "011";
  if (mnemonic == "JLT") return "100";
  if (mnemonic == "JNE") return "101";
  if (mnemonic == "JLE") return "110";
  return "111";
}