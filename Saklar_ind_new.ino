String voice;
int
relay1 = 11, //Connect RELAY 1 To Pin #2
relay2 = 10, //Connect RELAY 2 To Pin #3
relay3 = 9, //Connect RELAY 3 To Pin #4
relay4 = 8 //Connect RELAY 4 To Pin #5
;
//-----------------------------------------------------------------------//
void setup() {
Serial.begin(9600);
pinMode(relay1, OUTPUT);
pinMode(relay2, OUTPUT);
pinMode(relay3, OUTPUT);
pinMode(relay4, OUTPUT);

digitalWrite(relay1, HIGH);
digitalWrite(relay2, HIGH);
digitalWrite(relay3, HIGH);
digitalWrite(relay4, HIGH);
}
//-----------------------------------------------------------------------//
void loop() {
while (Serial.available()){  //
delay(10); //
char c = Serial.read(); //
if (c == '#') {break;} //
voice += c; //
}
if (voice.length() > 0) {

 
//----------kontrol setiap relay dengan perintah---------------//
if(voice == "Nyalakan kontak") {digitalWrite(relay1, LOW);}
else if(voice == "matikan kontak") {digitalWrite(relay1, HIGH);}
else if(voice == "hidupkan mesin") {digitalWrite(relay2, LOW); delay(1500); digitalWrite(relay3, LOW); delay(1000); digitalWrite(relay2, HIGH); digitalWrite(relay3, HIGH);}
else if(voice == "matikan mesin") {digitalWrite(relay4, LOW); delay(1000); digitalWrite(relay4, HIGH);}
//-----------------------------------------------------------------------//
voice="";}} //
