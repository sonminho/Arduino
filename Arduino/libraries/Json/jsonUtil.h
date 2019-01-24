#ifndef _JSONUTIL_h
#define _JSONUTIL_h

#include <ArduinoJson.h>

typedef void(*jsonEnc_t)(JsonObject &root);
typedef void(*jsonEncArr_t)(int index, JsonObject &element);
typedef void(*jsonDec_t)(JsonObject &root);
typedef void(*jsonDecArr_t)(int index, JsonObject &element);

String jsonEnc(jsonEnc_t process);
String jsonEncArr(int index, jsonEncArr_t process);
void jsonDec(String jsondata, jsonDec_t process);
void jsonDecArr(String jsondata, jsonDecArr_t process);


#endif
