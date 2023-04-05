//Alarme 
//Danuzio Alves 
//=================================================================================================================================================//
#include <LiquidCrystal.h>
#define Buzzer A0
#define Atuador 12
#define Sirene A4
int Leitura = 0;
int x = 0;
String Senha="2551";
String Salvo;
String Dado;
bool Alarme=false;
int Porta=false;
LiquidCrystal lcd(7,6,5,4,3,2);

void setup() {
  lcd.begin(16, 2);
  pinMode(Buzzer, OUTPUT);
  pinMode(Sirene, OUTPUT);
  pinMode(Atuador, INPUT_PULLUP);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);                 
  pinMode(A3, OUTPUT);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);      
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  digitalWrite(Sirene,HIGH);
//=====================================================Configura a senha inicial===================================================================//

  lcd.clear();
  lcd.print("   Bem-vindo");
}
void loop() {
if(digitalRead(8)==LOW){
     delay(300);
     lcd.clear();
     lcd.print("   Bem-vindo");
     lcd.setCursor(0,1); 
     lcd.print("Senha: ");
     lcd.setCursor(7,1); 
     TecladoMatricial(); 
     if(Salvo==Senha&&Alarme==true){
     lcd.clear();
     lcd.print("   Bem-vindo");
     lcd.setCursor(0,1);
     lcd.print("Alarme desligado"); 
     Alarme=false;
     tone(Buzzer,1000,100);
     delay(300);
     tone(Buzzer,1000,100);
     delay(300);
     tone(Buzzer,1000,100);
     }
     else if(Salvo==Senha&&Alarme==false){
     lcd.clear();
     lcd.print("   Bem-vindo");
     lcd.setCursor(0,1);
     lcd.print("Alarme ligado");
     Alarme=true;
     tone(Buzzer,1000,100);
     delay(300);
     tone(Buzzer,1000,100);
     }
     else if(Salvo!=Senha){
     lcd.clear();
     lcd.print("   Bem-vindo");
     lcd.setCursor(0,1); 
     lcd.print(" Senha errada!"); 
     delay(1000);
     lcd.clear();
     lcd.print("   Bem-vindo");
     lcd.setCursor(0,1);
     }
}
   if(digitalRead(Atuador)==HIGH&&Alarme==true){
      Porta=true;
     }
while(Porta==true)
{
     digitalWrite(Sirene,LOW);
     lcd.clear();
     lcd.print("    Perigo!!!");
     lcd.setCursor(0,1);
     lcd.print("Senha:");
     TecladoMatricial();
     
     if(Salvo==Senha){
     lcd.clear();
     lcd.print("Alarme desligado");
     digitalWrite(Sirene,HIGH);
     delay(1000);
     lcd.clear();
     lcd.print("   Bem-vindo");
     Porta=false;
     Alarme=false;
     } 
     
     if(Salvo!=Senha){
     lcd.clear();
     lcd.print(" Senha errada!");
     delay(1000);
     }
}
}
 //=======================================================Função de varredura para Teclado=========================================================//
void TecladoMatricial(){ 
  x=0;
  Salvo="";
  Dado="";
 while(x<=3){
//=====================================================Verredura da primeira coluna e 4 linhas=====================================================//
  if (Leitura == 0) {
    digitalWrite(A3, LOW);
    digitalWrite(A2, HIGH);
    digitalWrite(A1, HIGH);
      if (!digitalRead(11)&& Leitura == 0){
      Dado='1';
      Salvo+=Dado;
      x++;
      lcd.print(Dado);
      delay(300);
      }
      else if (!digitalRead(10)&& Leitura == 0){
      Dado='4';
      Salvo+=Dado;
      x++;
      lcd.print(Dado);
      delay(300);
      }
      else if (!digitalRead(9)&& Leitura == 0){
      Dado='7';
      Salvo+=Dado;
      x++;
      lcd.print(Dado);
      delay(300);
      }
      else if (!digitalRead(8)&& Leitura == 0){
      Dado='*';
      Salvo+=Dado;
      x++;
      lcd.print(Dado);
      delay(300); 
      }   
      Leitura = 1;
      }
//=====================================================Verredura da segunda coluna e 4 linhas======================================================//
  if (Leitura == 1) {
    digitalWrite(A3, HIGH);
    digitalWrite(A2, LOW);
    digitalWrite(A1, HIGH);
      if(!digitalRead(11)&& Leitura == 1){
      Dado='2';
      Salvo+=Dado;
      x++;
      lcd.print(Dado);
      delay(300);
      }
      else if (!digitalRead(10)&& Leitura == 1){
      Dado='5';
      Salvo+=Dado;
      x++;
      lcd.print(Dado);
      delay(300);
      }
      else if (!digitalRead(9)&& Leitura == 1){
      Dado='8';
      Salvo+=Dado;
      x++;
      lcd.print(Dado);
      delay(300);
      }
      else if (!digitalRead(8)&& Leitura == 1){
      Dado='0';
      Salvo+=Dado;
      x++;
      lcd.print(Dado);
      delay(300);
      }
      Leitura = 2;
      }
    
//=====================================================Verredura da terceira coluna e 4 linhas====================================================//
  if (Leitura == 2) {
    digitalWrite(A3, HIGH);
    digitalWrite(A2, HIGH);
    digitalWrite(A1, LOW);
    if (!digitalRead(11)&& Leitura == 2){
      Dado='3';
      Salvo+=Dado;
      x++;
      lcd.print(Dado);
      delay(300);
      }
      else if (!digitalRead(10)&& Leitura == 2){
      Dado='6';
      Salvo+=Dado;
      x++;
      lcd.print(Dado);
      delay(300);
      }
      else if (!digitalRead(9)&& Leitura == 2){
      Dado='9';
      Salvo+=Dado;
      x++;
      lcd.print(Dado);
      delay(300);
      }
      else if (!digitalRead(8)&& Leitura == 2){
      Dado='#';
      Salvo+=Dado;
      x++;
      lcd.print(Dado);
      delay(300);
      }
      Leitura = 0;
}
}
}
