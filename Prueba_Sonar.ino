/* Se declaran los valores conectados al Arduino UNO   */
const int trigPin = 9;
const int echoPin = 10;
long int duration;
int distance;

void setup() {

  /* Se declara la entrada y salida segun el cable */
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  /* Apaga el gatillo y espera 2mn segundos */

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW); 
  /* Prende el gatillo, manda un bus de electricidad, apaga */
  
  duration = pulseIn(echoPin,HIGH);
  distance = duration*((0.034)/2.0); 
  /* Almacena la medición del sonar y calcula la distancia*/ 
 
  Serial.print(distance);
  Serial.print("\n");
  /* Imprime resultados */
  
  delay(100);
}
