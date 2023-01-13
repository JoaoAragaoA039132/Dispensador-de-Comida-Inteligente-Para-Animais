#include <Servo.h>

Servo myservo;                                                                  // cria o objeto servo para controlar um servo

int pos = 0;                                                                    // variavel para armazenar a posicao do servo
int rotationCount = 0;                                                          // variavel para controlar o numero de rotacoes

void setup() {
  myservo.attach(6);                                                            // atribui o servo na porta 6 ao objeto servo
  Serial.begin(9600);                                                           // define a velocidade da comunicacao a 9600
}

void loop() {
  if (Serial.available() > 0) {                                                 // verifica se ha dados sendo enviados atraves da ligacao serie
    char incomingByte = Serial.read();                                          // le os dados de entrada
    if (incomingByte == '1') {                                                  // verifica se os dados de entrada sao "1"
      if (rotationCount < 3) {                                                  // verifica se o numero de rotacoes e menor que 3
        rotationCount++;                                                        // incrementa a variavel rotationCount
        Serial.println("Comida Dispensada!");                                   // imprime a mensagem "Comida Dispensada!"
        for (pos = 0; pos <= 180; pos += 1) {                                   // vai de 0 graus a 180 graus
          myservo.write(pos);                                                   // diz ao servo para ir para a posição na variavel 'pos'
          delay(2);                                                             // espera 2ms para o servo alcançar a posicao
        }
        for (pos = 180; pos >= 0; pos -= 1) {                                   // vai dos 280 graus ate aos 0 gruas
          myservo.write(pos);                                                   // diz ao servo para ir para a posicao na variavel 'pos'
          delay(2);                                                             // espera 2ms para o servo alcancar a posicao
        }
      } else {
        Serial.println("Sem Comida! E Necessario Reabastecer o Deposito!");     // imprime a mensagem "Sem Comida! E Necessario Reabastecer o Deposito!" se rotationCount >= 3
      }
    }
    if (incomingByte == '2') {                                                  // verifica se os dados de entrada sao "2"
        rotationCount = 0;                                                      // coloca o numero de rotacoes igual a 0
        myservo.write(0);                                                       // o servo vai para a posicao 0
        pos = 0;                                                                // o servo vai para a posicao 0
        Serial.println("Programa Reiniciado!");                                 // imprime a mensagem "Programa Reiniciado!"
    }
  }
}
