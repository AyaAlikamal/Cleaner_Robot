#include "IMU.h"
#include "avoid.h"
// #include <ESP32_easy_wifi_data.h>

IMU imu;
Avoid_Obstecels avoid;

void setup() {
  Serial.begin(9600);
  imu.init();
  // EWD::mode = EWD::Mode::connectToNetwork;                // "connectToNetwork" or "createAP"(hotspot). default: connect to network
  // EWD::signalLossTimeout = 1000;                          // connection times out if no signal after this many milliseconds (default: 1000 (= 1 sec))
  // EWD::routerName = " ";                                  // name of the wifi network you want to connect to
  // EWD::routerPassword = "";                               // password for your wifi network (enter "" if the network has no password) (default: "")
  // EWD::APName = "esp32";                                  // name of hotspot network (default: esp32)
  // EWD::APPassword = "password";                           // password for network created by esp32 if it is in hotspot mode (default: password)
  // EWD::routerPort = 25210;                                // what port the esp32 communicates on if connected to a wifi network (default: 25210)
  // EWD::APPort = 25210;                                    // what port the esp32 communicates on if it makes its own network (default 25210)
  // EWD::blockSimultaneousConnections = true;               // block more than one client from connecting at a time (default: true)
  // EWD::debugPrint = false;                                // print ip address and other information to the serial monitor (default: false)
  // EWD::setupWifi(dataReceiveCallback, dataSendCallback);  // this function connects to wifi, it may take up to 10 seconds, give it the names of dataReceiveCallback, dataSendCallback (functions with data sending and data receiving commands)
  avoid.init();
}

void loop() {
  // EWD::runWifiCommunication();  // call in loop, as often as possible in order to stay connected
  // EWD::millisSinceMessage();    // returns how many milliseconds it has been since a message was last received
  // EWD::notTimedOut();           // returns millisSinceMessage<signalLossTimeout
  // EWD::timedOut();              // returns millisSinceMessage>=signalLossTimeout, >>>use to disable your robot if it loses connection<<<
  // EWD::newData();               // returns true if new data was received this loop
  // EWD::getWifiConnected();      // returns true if the wifi connection has been started to the router or a hotspot has been made (unrelated to whether data has been received, for that use notTimedOut)   // returns true if the wifi connection has been started to the router or a hotspot has been made (unrelated to whether data has been received, for that use notTimedOut)
  imu.update();
  imu.display();
  imu.getangels();
  avoid.set_motion();
}

// void dataReceiveCallback() {
//   // int c = EWD::recvIn(); // receive an int  (int32_t)
//   // float d = EWD::recvFl(); // receive a float
// }
// void dataSendCallback() {
//   // EWD::sendBl(true); // send a boolean

//   EWD::sendIn(0);                // send an int  (int32_t)
//   EWD::sendFl(12.0);  // send a float
// }