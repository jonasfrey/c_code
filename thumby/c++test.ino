
// c file
#include <cstring>
#include <Thumby.h>

#include <vector>
#include <string>
#include <unistd.h>


Thumby thumby = Thumby();
char sendBuf[7] = "Hello!";
uint8_t dataBuf[7];
uint8_t packedBuf[10];



void setup() {
  // Sets up buttons, audio, link pins, and screen
  thumby.begin();

  // Init duplex UART for Thumby to PC comms
  Serial.begin(115200);

  // Make sure RX buffer is empty
  //   removeRxBytes();
}


class MyClass {       // The class
  public:             // Access specifier
    int myNum;        // Attribute (int variable)
    String myString;  // Attribute (string variable)
};

void loop() {

  MyClass myObj;  // Create an object of MyClass

  // Access attributes and set values
  myObj.myNum = 15;
  myObj.myString = "Some text";

std::vector< MyClass > a_o_collision_object;

a_o_collision_object.push_back(myObj);

  // Clear the screen to black
  thumby.clear();

  // usleep(1000);



  // Update the screen
  thumby.writeBuffer(thumby.getBuffer(), thumby.getBufferSize());
}
