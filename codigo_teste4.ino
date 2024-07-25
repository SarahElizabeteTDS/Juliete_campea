const int motor1 = 5; //velocidade motor 1 - de 0 a 255 (motor 1 esquero)
const int motor2 = 6; //velocidade motor 2 - de 0 a 255 (motor 2 direito)

const int dir1 = 7; //direcao do motor 1 - HIGH ou LOW dir1 é esquerda
const int dir2 = 8; //direcao do motor 2 - HIGH ou LOW dir2 é direita


const int sensorE = A0; //sensor esquerda (ver a porta certinho na julieta quando voltar a robotica)
const int sensorM = A1; //sensor meio
const int sensorD = A2; //sensor direito

void setup() {
  Serial.begin(9600);
  
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(sensorE, INPUT);
  pinMode(sensorM, INPUT);
  pinMode(sensorD, INPUT);
}

void loop() {
  int valorSensorE = analogRead(sensorE);
  int valorSensorM = analogRead(sensorM);
  int valorSensorD = analogRead(sensorD);

  Serial.print("Sensor E: "); Serial.print(valorSensorE);
  Serial.print(" Sensor M: "); Serial.print(valorSensorM);
  Serial.print(" Sensor D: "); Serial.println(valorSensorD);

  if (is_black(valorSensorM) == true) { //se o sensor do meio estiver no preto
    if (is_black(valorSensorE) == false) { //se o sensor esquerdo estiver no branco
      praEsquerda(0, 80); //XX1 é a velocidade do motor da esquerda, que devera ser menor. Testar se deve ou nao ir para tras na robotica
    } else if (is_black(valorSensorD) == false) { //se o sensor direito estiver no branco
      praDireita(80, 0); //XX2 é a velocidade do motor da direita, que devera ser menor. Testar se deve ou nao ir para tras na robotica
    }
  } else {
    if (is_black(valorSensorM) == false && is_black(valorSensorE) == false && is_black(valorSensorD) == false) {
      praFrente(80); //velocidade dos dois motores, porque os dois tem que ir pra frente na mesma velocidade
    } else if (is_black(valorSensorM) == false && is_black(valorSensorE) == true && is_black(valorSensorD) == true) {
      praFrente(80); //velocidade dos dois motores, porque os dois tem que ir pra frente na mesma velocidade
    } else if (is_black(valorSensorM) == false && is_black(valorSensorE) == false && is_black(valorSensorD) == true) {
      praDireita(80, 0); //XX2 é a velocidade do motor da direita, que devera ser menor. Testar se deve ou nao ir para tras na robotica
    } else if (is_black(valorSensorM) == false && is_black(valorSensorE) == true && is_black(valorSensorD) == false) {
      praEsquerda(0, 80); //XX1 é a velocidade do motor da esquerda, que devera ser menor. Testar se deve ou nao ir para tras na robotica
    }
  }
}

bool is_black(int sensor)
{
  if(sensor > 850)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void praFrente(int velocidade) {
  digitalWrite(dir1, HIGH); // Define a direção do motor 1 para frente
  digitalWrite(dir2, HIGH); // Define a direção do motor 2 para frente
  analogWrite(motor1, velocidade); // Define a velocidade do motor 1 (mesma velocidade para os dois)
  analogWrite(motor2, velocidade); // Define a velocidade do motor 2
}

void praEsquerda(int velocidade1, int velocidade2) {
  digitalWrite(dir1, HIGH); // Define a direção do motor 1 para frente
  digitalWrite(dir2, LOW); // Define a direção do motor 2 para trás (ver se nao é bom deixar no high com uma vel mais baixa que o outro, vamos testar isso)
  analogWrite(motor1, velocidade1); // Define a velocidade do motor 1 (esquerda) (velocidade -)
  analogWrite(motor2, velocidade2); // Define a velocidade do motor 2 (direita) (velocidade +)
}

void praDireita(int velocidade1, int velocidade2) {
  digitalWrite(dir1, LOW); // Define a direção do motor 1 para trás (ver se nao é bom deixar no high com uma vel mais baixa que o outro, vamos testar isso)
  digitalWrite(dir2, HIGH); // Define a direção do motor 2 para frente 
  analogWrite(motor1, velocidade1); // Define a velocidade do motor 1 (esquerda) (velocidade +)
  analogWrite(motor2, velocidade2); // Define a velocidade do motor 2 (direita) (velocidade -)
}
