
unsigned char FBusFrame[200];
//unsigned char SMSC[] = {0x07, 0x91, 0x16, 0x14, 0x91, 0x09, 0x00, 0xF1, 0x00, 0x00, 0x00, 0x00};
//douglas tel no.: +233 245 511 543
//SMSC: {0x07, 0x91, 0x32, 0x23, 0x54, 0x15, 0x51, 0x34, 0x00, 0x00, 0x00, 0x00};
unsigned char SMSC[] = {0x07, 0x91, 0x32, 0x23, 0x54, 0x15, 0x51, 0x34, 0x00, 0x00, 0x00, 0x00};
//unsigned char RecipientNo[] = {0x0A, 0x81, 0x40, 0x21, 0x43, 0x65, 0x87};
//John's number: 05 48 21 54 10
unsigned char RecipientNo[] = {0x0A, 0x81, 0x50, 0x84, 0x12, 0x45, 0x01};


void setup() {
  Serial.begin(115200);
  delay(100);
}
 
void loop() {
  // Initialise the Fbus by sending "U" 128 times
  for (int x = 0; x < 128; x++) {
    Serial.write("U");
  }
 
  // Send the SMS message
  SendSMS("Hi All. This message was sent through F-Bus. Cool!!");
 
  // Keep listening for a reply (we won't send any acknowledgements back)
  while (1) {
  }
}


unsigned char SendSMS(const char *Message) {
  // Clear buffer
  unsigned char j = 0;
  memset(FBusFrame, 0, sizeof(FBusFrame));
 
  unsigned char MsgLen = strlen(Message), FrameSize = 0;
  unsigned char c, w, n, shift = 0, frameIndex = 0;
  unsigned char oddCheckSum, evenCheckSum = 0;
 
  // Encode the message into 7 bit characters
  for (n = 0; n < MsgLen; n++) {
    c = Message[n] & 0x7f;
    c >>= shift;
    w = Message[n+1] & 0x7f;
    w <<= (7-shift);
    shift += 1;
    c = c | w;
    if (shift == 7) {
      shift = 0x00;
      n++;
    }
    FBusFrame[frameIndex + MsgStartIndex] = c;
    frameIndex++;
}
FBusFrame[frameIndex + MsgStartIndex] = 0x01;
FrameSize = frameIndex + 44; // The size of the frame is frameIndex+48 (FrameIndex + 48 + 1 - 5)

// Insert the frame values to prepare to send an SMS
FBusFrame[0] = 0x1E;
FBusFrame[1] = 0x00;
FBusFrame[2] = 0x0C;
FBusFrame[3] = 0x02;
FBusFrame[4] = 0x00;
FBusFrame[5] = FrameSize;
FBusFrame[6] = 0x00;
FBusFrame[7] = 0x01;
FBusFrame[8] = 0x00;
FBusFrame[9] = 0x01;
FBusFrame[10] = 0x02;
FBusFrame[11] = 0x00;
 
// Insert the SMS Center number
for (j = 0; j < sizeof(SMSC); j++) {
  FBusFrame[12 + j] = SMSC[j];
}
 
FBusFrame[24] = 0x15; // Message type
FBusFrame[28] = MsgLen; // Message length (uncompressed)
 
// Insert the Recipient number
for (j = 0; j < sizeof(RecipientNo); j++) {
  FBusFrame[j + 29] = RecipientNo[j];
}
 
FBusFrame[41] = 0xA7; // Validity period


// Check if the Framesize is odd or even
if (FrameSize & 0x01) {
  frameIndex = FrameSize + 5;
  FBusFrame[frameIndex] = SeqNo;
  frameIndex++;\
  FBusFrame[frameIndex] = 0; // Insert to make the Frame even
  frameIndex++;
}
else {
  frameIndex = FrameSize + 5;
  FBusFrame[frameIndex] = SeqNo;
  frameIndex++;
}
 
// Calculate the checksum from the start of the frame to the end of the frame
for (unsigned char i = 0; i < frameIndex+2; i += 2) {
  oddCheckSum ^= FBusFrame[i];
  evenCheckSum ^= FBusFrame[i+1];
}
FBusFrame[frameIndex] = oddCheckSum;
FBusFrame[frameIndex+1] = evenCheckSum;
 
// Send the full frame to the phone
for (unsigned char j = 0; j < (frameIndex+2); j++) {
  // Debug to check in hex what we are sending
  //Serial.print(FBusFrame [j], HEX);
  //Serial.print(" ");
 
  Serial.write(FBusFrame [j]);
}




