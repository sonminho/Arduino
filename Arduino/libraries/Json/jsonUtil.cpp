#include "jsonUtil.h"

StaticJsonBuffer<200> jsonBuffer;

String jsonEnc(jsonEnc_t process) {
  jsonBuffer.clear();
  JsonObject &root = jsonBuffer.createObject();

  process(root);

  String jsondata = "";
  root.printTo(jsondata);
  return jsondata;
}

String jsonEncArr(int index, jsonEncArr_t process) {
  jsonBuffer.clear();
  JsonArray &root = jsonBuffer.createArray();

  for (int i = 0; i < index; i++) {
    JsonObject &element = root.createNestedObject();
    process(i, element);
  }
  String jsondata = "";
  root.printTo(jsondata);
  return jsondata;
}

void jsonDec(String jsondata, jsonDec_t process) {
  jsonBuffer.clear();
  JsonObject &root = jsonBuffer.parseObject(jsondata);

  process(root);
}

void jsonDecArr(String jsondata, jsonDecArr_t process) {
  jsonBuffer.clear();
  auto &root = jsonBuffer.parseArray(jsondata);
  int ix = 0;
  for (auto &element : root) {
    process(ix++, element);
  }
}
