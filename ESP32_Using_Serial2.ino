

#define RXD2 16
#define TXD2 17

void setup() {
  // Note the format for setting a serial port is as follows: Serial2.begin(baud-rate, protocol, RX pin, TX pin);
  Serial.begin(115200);
  pinMode(RXD2, INPUT);
  pinMode(TXD2, OUTPUT);
  //Serial1.begin(9600, SERIAL_8N1, RXD1, TXD1);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  Serial2.println("Serial Txd is on pin: "+String(TX));
  Serial2.println("Serial Rxd is on pin: "+String(RX));
}
byte myArray[] = "";
//int gasLevel=10;
int i=0;
void loop() { //Choose Serial1 or Serial2 as required
  i=0;
  while (Serial2.available()) {
  myArray[i] = Serial2.read();
  Serial.print(myArray[i], HEX); 
  i++;
  }
int ResolutionCoff = myArray[3];
int firstByte = myArray[4];
int secondByte = myArray[5];


if (myArray[i] >= (firstByte*256+secondByte)*ResolutionCoff){
  Serial.println(" No Gas Detected");
  delay(1000);
}
  else{
    Serial.println(" Gas Detected");
    delay(1000);
}
}
