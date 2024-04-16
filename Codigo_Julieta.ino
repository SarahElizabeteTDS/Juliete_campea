const int motor1 = 5; //velocidade motor 1 - de 0 a 255
const int motor2 = 6; //velocidade motor 2 - de 0 a 255
const int dir1 = 7; //direcao do motor 1 - HIGH ou LOW dir1 é esquerda
const int dir2 = 8; //direcao do motor 2 - HIGH ou LOW dir2 é direita
const int sensorE = XX; //sensor esquerda (ver a porta certinho na julieta quando voltar a robotica)
const int sensorM = XX; //sensor meio
const int sensorD = XX; //sensor direito

void setup() 
{
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(sensorE, INPUT);
  pinMode(sensorM, INPUT);
  pinMode(sensorD, INPUT);
}

void loop() 
{
  if(is_black(sensorM) == true) //se o sensor do meio estiver no preto
  {
    if(is_black(sensorE) == false) //se o sensor esquerdo estiver no branco
    {
      
    }
    if else(is_black(sensorD) == false) //se o sensor esquerdo estiver no branco
    {

    }
  }else{
    
  }
}

bool is_black(int sensor)
{
  if(sensor >= 800)
  {
    return false;
  }else{
    return true;
  }
}

void praFrente(int velocidade)
{
  digitalWrite(dir1, HIGH); // Define a direção do motor 1 para frente
  digitalWrite(dir2, HIGH); // Define a direção do motor 2 para frente
  analogWrite(motor1, velocidade); // Define a velocidade do motor 1 (mesma velocidade para os dois)
  analogWrite(motor2, velocidade); // Define a velocidade do motor 2
}

void praEsquerda(int velocidade1, int velocidade2)
{
  digitalWrite(dir1, HIGH); // Define a direção do motor 1 para frente
  digitalWrite(dir2, LOW); // Define a direção do motor 2 para trás (ver se nao é bom deixar no high com uma vel mais baixa que o outro, vamos testar isso)
  analogWrite(motor1, velocidade1); // Define a velocidade do motor 1 (esquerda) (velocidade +)
  analogWrite(motor2, velocidade2); // Define a velocidade do motor 2 (direita) (velocidade -)
}

void praDireita(int velocidade1, int velocidade2)
{
  digitalWrite(dir1, LOW); // Define a direção do motor 1 para trás (ver se nao é bom deixar no high com uma vel mais baixa que o outro, vamos testar isso)
  digitalWrite(dir2, HIGH); // Define a direção do motor 2 para frente 
  analogWrite(motor1, velocidade1); // Define a velocidade do motor 1 (esquerda) (velocidade +)
  analogWrite(motor2, velocidade2); // Define a velocidade do motor 2 (direita) (velocidade -)
}
