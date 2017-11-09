#ifndef SOLOMONDB_EVM_UTILS_H
#define SOLOMONDB_EVM_UTILS_H

#include <cstdint>
#include <string>
#include <vector>
#include <sstream>
#include <cassert>

#include "solomondb_bb_utils.h"

namespace DBUtils {
  namespace EVMUtils {

    enum class EVMType { Ethereum, Parity};

    inline std::string encode_string(const std::string& str) {

      std::string utf8_encoded = encode_str_hex(str);
      std::string l = encode_hex(utf8_encoded.length() / 2);
      std::string ret = left_padding_string(l) + right_padding_string(utf8_encoded);
      return ret;


}


    unsigned int get_tip_block_number();

    unsigned int get_txn_block_number();

    void unlock_address(const std::string& endpoint, const std::string& address);




}





}
