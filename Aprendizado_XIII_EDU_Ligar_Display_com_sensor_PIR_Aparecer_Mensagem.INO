// Código versão beta, pois, falta inserir uma linha de código para resetar o sensor para quando estiver LOW; 

// Projeto de dispositivo de detecção de movimento; 

// Display do LCD ;

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd_1(32, 16, 12); // pino 02 sensor para o display; 

// Declaração dos pinos e componentes eletr}onicos:
int pirPin = 2; // Pino do sensor PIR movimento

// Variável para armazenar o estado do sensor;

int pirState = LOW; // O sensor começa sem nenhuma informação.
int val = 0; // leitura do pino do sensor

void setup() {
  
  
  pinMode (pirPin, INPUT);

  // configuração do display LCD 16x2 i2c; 
  
  lcd_1.init();

  lcd_1.setCursor(0, 0);
  lcd_1.backlight();
  lcd_1.display();
 
 
}

void loop() {
  
  
   for (int i = 0; i<5; i++){
   
// Verificar o valor do sensor PIR para ver se detectou movimento   
 
  val = digitalRead (pirPin); // ler o sensor PIR. 
  
   while (val == HIGH) {
   
   
 // mensagem no LCD para o botão pressionado;
 
  lcd_1.setCursor(0, 0);
  lcd_1.print("Movimento");
  delay(2000); // Wait for 2000 millisecond(s)
  lcd_1.setCursor(0, 1);
  lcd_1.print("detectado!!!");
  delay(2000); // Wait for 2000 millisecond(s)
  lcd_1.clear();
       
 } 
     
 // Aguarda até o sensor "resetar" (ficar LOW novamente)
    while (digitalRead(pirPin) == HIGH) {
      delay(100); // Espera o sinal voltar a LOW
    }     
     
     
   }
           
//  mensagem do LCD inicialmente  
  lcd_1.setCursor(0, 0);
  lcd_1.print("Sem");
  delay(2000); // Wait for 2000 millisecond(s)
  lcd_1.setCursor(0, 1);
  lcd_1.print("movimento...");
  delay(2000); // Wait for 2000 millisecond(s)
  lcd_1.clear();
   
}
