#ifndef SOLOMON_DB_UTILS_H_
#define SOLOMON_DB_UTILS_H_

#include <cstdint>
#include <string>
#include <vector>
#include <sstream>
#include <restclient-cpp/restclient.h>

namespace DBUtils {

  enum class SmartContractType { KVStore, DoNothing, SmallBank };

  inline std::string encode_hex(unsigned int c) {
    std::ostringstream stm;
    stm << std::hex << c;
    return stm.str();

}





}
