// DEFINIÇÕES DE PINOS
#include <NewPing.h>

#define pinEcho 2
#define pinTrig 4
#define maxDistance 200

NewPing sensorUltra(pinTrig, pinEcho, maxDistance);

#define pinMotor1 3 ex
#define pinMotor2 5  //Frente
#define pinMotor3 6  //Frente
#define pinMotor4 9

void setup() {
  Serial.begin(9600);

  pinMode(pinMotor1, OUTPUT);
  pinMode(pinMotor2, OUTPUT);
  pinMode(pinMotor3, OUTPUT);
  pinMode(pinMotor4, OUTPUT);
}

void loop() {
  static unsigned long tempo = millis();
  int distancia;
   
  if ((millis() - tempo) > 200 ) {
     distancia = sensorUltra.ping_cm();
     tempo = millis();
  }

  Serial.print("Dist: ");
  Serial.println(distancia);

  //Serial.print("Tempo: ");
  //Serial.println(tempo);
 
  if (distancia > 10) {
    paraFrente();
    //Serial.println("Passou pelo 1");
  } else {
    virar();
  }
  
  delay(10);
}

void paraFrente() {
  parar();
  for (int velocidade = 100; velocidade >= 45; velocidade--) {
    analogWrite(pinMotor2, velocidade);
    analogWrite(pinMotor3, velocidade);
    delay(1);
  }
}

void virar() {
  parar();
  analogWrite(pinMotor1, 100);
  analogWrite(pinMotor3, 100);
  delay(100);
  parar();
}

void paraTras() {
  parar();
  for (int velocidade = 100; velocidade >= 30; velocidade--) {
    analogWrite(pinMotor1, velocidade);
    analogWrite(pinMotor4, velocidade);
    delay(1);
  }
}

void parar() {
  digitalWrite(pinMotor1, LOW);
  digitalWrite(pinMotor2, LOW);
  digitalWrite(pinMotor3, LOW);
  digitalWrite(pinMotor4, LOW);
}
