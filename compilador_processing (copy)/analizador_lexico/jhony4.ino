int pin3 =3;
int pin5 =5;
int pin6 =6;
int pin9 =9;
int estado;
int vel = 75;
void setup() {
  Serial.begin (9600);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
}
void activar(int v){
    analogWrite(pin3, v);
    analogWrite(pin5, v);
    analogWrite(pin6, v);
    analogWrite(pin9, v);
}
void parar(){
  analogWrite(pin3, 0);
  analogWrite(pin5, 0);
  analogWrite(pin6, 0);
  analogWrite(pin9, 0);
}
void adelante(int v){
    analogWrite(pin3, v);
    analogWrite(pin5, 0);
    analogWrite(pin6, 0);
    analogWrite(pin9, v);
}
void atras(int v){
    analogWrite(pin3, 0);
    analogWrite(pin5, v);
    analogWrite(pin6, v);
    analogWrite(pin9, 0);
  }
void derecha(int v){
    analogWrite(pin3, v);
    analogWrite(pin5, 0);
    analogWrite(pin6, v);
    analogWrite(pin9, 0);
}


void izquierda(int v){
    analogWrite(pin3, 0);
    analogWrite(pin5, v);
    analogWrite(pin6, 0);
    analogWrite(pin9, v);
}

 void loop() {
if (Serial.available ()>0){
    estado = Serial.read();
    if (estado != -1){
      switch(estado){
          case 'w': //hola w
          adelante(vel);
          break;
          case 's': //hola s
          atras(vel);
          break;
          case 'a': //hola a
          izquierda(vel);
          break;
          case 'd': //hola d
          derecha(vel);
          break;
          case 'x': //hola x
          activar(vel);
          break;
          case 'c': //hola c
          parar();
          break;
      }
    }
  }
}
