#include <SdFat.h>
#include <string.h>

// SD chip select pin
const uint8_t chipSelect = SS;

// file system object
SdFat sd;

// create a serial stream
ArduinoOutStream cout(Serial);

char command[255];

//------------------------------------------------------------------------------
void Getline() {
  const int line_buffer_size = 18;
  char buffer[line_buffer_size];
  ifstream sdin("test.rml");
  //int line_number = 0;
  while (sdin.getline(buffer, line_buffer_size, '\n') || sdin.gcount()) {
    strcat(command,buffer);
  }
  cout << command;
}
//------------------------------------------------------------------------------
void setup(void) {
  Serial.begin(9600);

  // pstr stores strings in flash to save RAM
  cout << pstr("Type any character to start\n");
  while (Serial.read() < 0) {}

  // initialize the SD card at SPI_HALF_SPEED to avoid bus errors with
  // breadboards.  use SPI_FULL_SPEED for better performance.
  if (!sd.begin(chipSelect, SPI_HALF_SPEED)) sd.initErrorHalt();

  // run the example
  Getline();
}
//------------------------------------------------------------------------------
void loop(void) {}


