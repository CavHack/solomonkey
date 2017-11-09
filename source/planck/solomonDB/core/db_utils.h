#ifndef SOLOMONDB_DB_UTILS_H_
#define SOLOMONDB_DB_UTILS_H_

#include<cstdint>
#include <string>
#include <vector>
#include <sstream>
#include <restclient-cpp/restclient.h>

namespace DBUTILS {
  
  enum class SmartContractType {KVStore, DoNothing, SmallBank };

  inline std::string encode_hex(unsigned int c) {}

  inline unsigned int decode_hex(const std::string &s) {}

  inline std::string encode_str_hex(){}


}
