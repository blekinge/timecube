
#include <HTTPClient.h>


struct header_t {
  const String name;
  const String value;
};

typedef enum {
  BASIC
} auth_types_t;

struct endpoint_t {
  String httpMethod;
  String url;
  String body;
  header_t headers[4];
  uint8_t count;
  String username;
  String password;
  auth_types_t authMethod;
};

endpoint_t urls[] = {
  //side1
  { "GET",
    "http://192.168.2.136:8080/side/1",
    "", //body
    {}, //headers
    0, //headers count
    "username", //httpBasic username
    "password", //httpBasic password
    BASIC //authMethod
  },

  //side2
  { "GET",
    "http://192.168.2.136:8080/side/2",
    "", //body
    {}, //headers
    0, //headers count
    "username", //httpBasic username
    "password", //httpBasic password
    BASIC //authMethod
  },

  //side3
  { "GET",
    "http://192.168.2.136:8080/side/3",
    "", //body
    {}, //headers
    0, //headers count
    "username", //httpBasic username
    "password", //httpBasic password
    BASIC //authMethod
  },

  //side4
  { "GET",
    "http://192.168.2.136:8080/side/4",
    "", //body
    {}, //headers
    0, //headers count
    "username", //httpBasic username
    "password", //httpBasic password
    BASIC //authMethod
  },

  //side5
  { "GET",
    "http://192.168.2.136:8080/side/5",
    "", //body
    {}, //headers
    0, //headers count
    "username", //httpBasic username
    "password", //httpBasic password
    BASIC //authMethod
  },

  //side6
  { "GET",
    "http://192.168.2.136:8080/side/6",
    "", //body
    {}, //headers
    0, //headers count
    "username", //httpBasic username
    "password", //httpBasic password
    BASIC //authMethod
  }

};

//TODO https

String httpGetRequest(byte side) {

  endpoint_t endpoint = urls[side - 1];

  //https://github.com/espressif/arduino-esp32/blob/master/libraries/HTTPClient/src/HTTPClient.h
  HTTPClient http;

  // configure traged server and url
  //http.begin("https://www.howsmyssl.com/a/check", ca); //HTTPS
  http.begin(endpoint.url); //HTTP

  if (endpoint.authMethod == BASIC) {
    http.setAuthorization(endpoint.username.c_str(), endpoint.password.c_str());
    http.setAuthorizationType("BASIC");
  }

  for (int headerNum = 0; headerNum < endpoint.count; headerNum++) {
    http.addHeader(endpoint.headers[headerNum].name, endpoint.headers[headerNum].value);
  }

  // start connection and send HTTP header
  int httpCode = http.sendRequest(endpoint.httpMethod.c_str(), endpoint.body);

  String result = http.getString();

  http.end();

  return result;

}
