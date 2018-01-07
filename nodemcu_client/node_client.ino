#include <ESP8266WiFi.h>
#include <Servo.h>
/*

This script sets up the nodemcu side. It provides a rudimentary REST api that
can be used to communicate with this board.

2018-01-06

*/

// Set up the servo

Servo servo;
// the servo is set up on GPIO 5
int servoPin = 5;


const char* ssid = "InsidiousInternet";
const char* password = "superman";

WiFiServer server(80);

void setup() {

  Serial.begin(115200);
  delay(10);
  
  servo.attach(servoPin);
  servo.write(90);
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");

  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait until the client sends some data
  Serial.println("new client");
  while (!client.available()) {
    delay(1);
  }

  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  for (int i=0; i<=360; i+=15) {
  if (request.indexOf("/SERVO=0") != -1) {
    servo.write(0);
  }

  if (request.indexOf("/SERVO=15") != -1) {
    servo.write(15);
  }

  if (request.indexOf("/SERVO=30") != -1) {
    servo.write(30);
  }

  if (request.indexOf("/SERVO=45") != -1) {
    servo.write(45);
  }

  if (request.indexOf("/SERVO=60") != -1) {
    servo.write(45);
  }

  if (request.indexOf("/SERVO=75") != -1) {
    servo.write(75);
  }

  if (request.indexOf("/SERVO=90") != -1) {
    servo.write(90);
  }

  if (request.indexOf("/SERVO=105") != -1) {
    servo.write(105);
  }

  if (request.indexOf("/SERVO=-15") != -1) {
    servo.write(-15);
  }

  

    
  }
  // Match the request


  

  

  

  if (request.indexOf("/SERVO=ROTATE") != -1) {
    servo.write(0);
    delay(1000);
    servo.write(90);
    delay(1000);
    servo.write(0);
  }
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("</html>");

  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");

}

