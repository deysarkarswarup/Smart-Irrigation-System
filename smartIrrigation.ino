int sensor_pin = A0; // Soil Sensor input at Analog PIN A0
int output_value ; 
//First of all, we have defined two variables;
//one for the soil moisture sensor pin and the other for storing the output of the sensor.
void setup() {
  // put your setup code here, to run once:
  pinMode(4,OUTPUT);
  //In the setup function, the “Serial.begin(9600)” command will help in communication between
  //the Arduino and serial monitor. Then, we will print the “Reading From the Sensor …” on the serial monitor.
  Serial.begin(9600);
  Serial.println("Reading From the Sensor ...");
  delay(2000);
}
//In the loop function, we will read from the sensor analog pin and will store the values in the “output_ value”
//variable. Then, we will map the output values to 0-100, because the moisture is measured in percentage. 
//When we took the readings from the dry soil, then the sensor value was 550 and in the wet soil, the sensor value 
//was 10. So, we mapped these values to get the moisture. After that, we printed these values on the serial monitor.
  void loop() {
  // put your main code here, to run repeatedly:
   output_value= analogRead(sensor_pin);
   output_value = map(output_value,550,10,0,100);
   Serial.print("Mositure : ");
   Serial.print(output_value);
   Serial.println("%");
   if(output_value<0){
      digitalWrite(4,HIGH);
     }
     else{
      digitalWrite(4,LOW);
     }
   delay(1000);
}
