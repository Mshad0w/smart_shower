#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include "index.h"


#define interrupt_pin 0


MDNSResponder mdns;

//////////////////////////////// WIFI SSID ////////////////////////

const char* ssid = "your wifi SSID"; // your connection name
const char* password = "your wifi Pass"; // your connection password

ESP8266WebServer server(80);


int ptr ;

int tmpir;
String ledState = "OFF";
String adcValue;
int count = 0;
float vol=0.00;
//Check if header is present and correct
bool is_authentified(){
  Serial.println("Enter is authentified");
  if (server.hasHeader("Cookie")){
    Serial.print("Found cookie: ");
    String cookie = server.header("Cookie");
    Serial.println(cookie);
    if (cookie.indexOf("ESPSESSIONID=1") != -1) {
      Serial.println("Authentification Successful");
      return true;
    }
  }
  Serial.println("Authentification Failed");
  return false;
}

//login page, also called for disconnect
void handleLogin(){
  String msg;
  if (server.hasHeader("Cookie")){
    Serial.print("Found cookie: ");
    String cookie = server.header("Cookie");
    Serial.println(cookie);
  }
  if (server.hasArg("DISCONNECT")){
    Serial.println("Disconnection");
    server.sendHeader("Location","/login");
    server.sendHeader("Cache-Control","no-cache");
    server.sendHeader("Set-Cookie","ESPSESSIONID=0");
    server.send(301);
    return;
  }
  if (server.hasArg("USERNAME") && server.hasArg("PASSWORD")){
    if (server.arg("USERNAME") == "admin" &&  server.arg("admin") == "mjd" ) // enter ur username and password you want
    {
      server.sendHeader("Location","/");
      server.sendHeader("Cache-Control","no-cache");
      server.sendHeader("Set-Cookie","ESPSESSIONID=1");
      server.send(301);
      Serial.println("Log in Successful");
      return;

      }

  msg = "Wrong username/password! try again.";
  Serial.println("Log in Failed");
  }
  String content = "<html><body style='background-color:MediumAquaMarine'><form action='/login' method='POST'><p  align ='center' style='font-size:300%;'><u><b><i>  Log In  </i></b></u></p><br>";
  content += " <p   align ='center' style='font-size:160%'><b> UserName:<input type='text' name='USERNAME' placeholder='user name' required></b></p><br>";
  content += "<p  align ='center' style='font-size:160%'><b>Password:<input type='password' name='PASSWORD' placeholder='password' required></b></p><br>";
  content += "<p  align ='center' style='font-size:160%'><input type='submit' name='SUBMIT' value='Submit'></form>" + msg + "</p><br> </body></html>";
  server.send(200, "text/html", content);
}

//root page can be accessed only if authentification is ok
void handleRoot(){
  Serial.println("Enter handleRoot");
  String header;
  if (!is_authentified()){
    server.sendHeader("Location","/login");
    server.sendHeader("Cache-Control","no-cache");
    server.send(301);
    return;
  }
   String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}

//no need authentification
void handleNotFound(){
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}


/////////////////////////////////////////////////////////////////////// ADC Handle Begin //////////////////////////////////////////
void handleADC() {
 
 
vol=count*0.002083/2.666;
adcValue = String(vol,DEC);
 
 Serial.println("Litre "); 
 
 Serial.println(adcValue);                        

server.send(200, "text/plane", adcValue);
  

}

 void handleLED() {

String  t_state = server.arg("LEDstate"); //Refer  xhttp.open("GET", "setLED?LEDstate="+led, true);
// tmp_stat = server.arg("tmpstat"); //Refer  xhttp.open("GET", "setLED?LEDstate="+led, true);
 Serial.println(t_state);
 if(t_state == "1")
 {
  
  attachInterrupt(digitalPinToInterrupt(interrupt_pin), handleInterrupt, CHANGE);
  ledState = "ON"; //Feedback parameter
  tmpir= 1;
 // count=0;
 }
 else if (t_state == "0")
 {
  ledState = "OFF"; //Feedback parameter
 detachInterrupt(digitalPinToInterrupt(interrupt_pin));
 tmpir= 0;
 count=0;
 }
 


 server.send(200, "text/plane", ledState); //Send web page
}
void handleInterrupt()
{
  count++;
}
////////////////////////////////////////////////////  ////////// S--E--T--U--P /////////////////////////////  //////////////////

void setup(void){

 

   // preparing GPIOs
  pinMode(interrupt_pin, INPUT_PULLUP);
   attachInterrupt(digitalPinToInterrupt(interrupt_pin), handleInterrupt, CHANGE);
  IPAddress ip(192,168,1,10);   
IPAddress gateway(192,168,1,1);   
IPAddress subnet(255,255,255,0); 
IPAddress primaryDNS(8, 8, 8, 8);  
WiFi.config(ip, gateway, subnet,primaryDNS);
  delay(1000);
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  Serial.println("");

  
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (mdns.begin("esp8266", WiFi.localIP())) {
    Serial.println("MDNS responder started");
    }


  server.on("/", handleRoot);
  server.on("/login", handleLogin);
  server.on("/inline", [](){
    server.send(200, "text/plain", "this works without need of authentification");
  });
  

 
server.on("/setLED", handleLED);
 server.on("/readADC", handleADC);

  server.onNotFound(handleNotFound);
  //here the list of headers to be recorded
  const char * headerkeys[] = {"User-Agent","Cookie"} ;
  size_t headerkeyssize = sizeof(headerkeys)/sizeof(char*);
  //ask server to track these headers
  server.collectHeaders(headerkeys, headerkeyssize );


   server.begin();
  Serial.println("HTTP server started");
}


void loop(void){
  

  server.handleClient();
 
}
