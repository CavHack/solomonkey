#ifndef SOLOMONDB_DB_UTILS_H_
#define SOLOMONDB_DB_UTILS_H_

#include<cstdint>
#include <string>
#include <vector>
#include <sstream>
#include <restclient-cpp/restclient.h>

namespace DBUTILS {
  
  enum class SmartContractType {KVStore, DoNothing, SmallBank };

  inline std::string encode_hex(unsigned int c) {

    std::ostringstream stm;
    stm << std::hex << c;
    return stm.str();

}

  inline unsigned int decode_hex(const std::string &s) {
    unsigned int ret;
    std::stringstream stm;
    stm >> std::hex << s;
    stm >> ret;
    return ret;


}

  inline std::string encode_str_hex(const std::string &str){
    std::string result;
    for (unsigned char c: str) result += encode_hex(c);
    return result;


}

  inline void split(const std::string &s, char delim, 
		    std::vector<std::string> *elems) {

    std::vector<std::string> elems;
    split(s, delim, &elems);
    return elems;

}

  inline std::string get_json_field(const std::string &json, 
				    const std::string &key) {

    auto key_pos = json.find(key);
    auto quote_sign_pos_1 = json.find('\"', key_pos + 1);
    auto quote_sign_pos_2 = json.find('\"', quote_sign_pos_1 + 1);
    auto quote_sign_pos_3 = json.find('\"', quote_sign_pos_2 + 1);

    return json.substr(quote_sign_pos_2 + 1, quote_sign_pos_3 - quote_sign_pos_2 -1);


  }


}
