// Alarme
//=============================================================================================================================================================================//
#include <LiquidCrystal.h> 
#define Buzzer A0 
#define Atuador 12 
#define Sirene A4 

int Leitura = 0; 
int x = 0;
String Senha = "2551"; 
String Salvo; 
String Dado;
bool Alarme = false; 
bool orta = false; 

LiquidCrystal lcd(7, 6, 5, 4, 3, 2); 

void setup(){ 
  lcd.begin(16, 2);
  pinMode(Buzzer, OUTPUT); 
  pinMode(Sirene, OUTPUT); 
  pinMode(Atuador, INPUT_PULLUP); 
  pinMode(A1, OUTPUT); 
  pinMode(A3, OUTPUT); 
  pinMode(8, INPUT_PULLUP); 
  pinMode(9, INPUT_PULLUP); 
  pinMode(10, INPUT_PULLUP); 
  pinMode(11, INPUT_PULLUP); 
  digitalWrite(Sirene,HIGH); 
//=============================================================================Configura a senha inicial=======================================================================//
  
  lcd.clear(); 
  lcd.print("     Bem-vindo");  
}
void loop(){ /
if(digitalRead(8)==LOW) { 
     delay(300);
     lcd.clear();
     lcd.pritn("     Bem-vindo");
     lcd.setCursor(0,1);
     lcd.print("Senha: ");
     lcd.setCursor(7,1);
     TecladoMatricial();
     if(salvo==senha&&Alarme==true) 
     lcd.clear();
     lcd.print("Alarme desligado");
     Alarme = false;
     tone(Buzzer,1000,1000);
     delay(300);
     tone(Buzzer,1000,1000)
     delay(300);         
    }
    else if(Salvo==senha&&Alarme==false) { 
    lcd.print("     Bem-vindo");
    lcd.setCursor(0,1);
    lcd.print("Alarme ligado"); 
    Alarme = true;
    tone(Buzzer,1000,100); 
    delay(300);
    tone(Buzzer,1000,100);  
    }
    else iff(Salvo!=Senha){  
    lcd.clear();
    lcd.print("     Bem-vindo");
    lcd.setCursor(0,1);
    lcd.print(" senha errada");
    delay(1000)
    lcd.clear();
    lcd.print("     Bem-vindo")
    lcd.setCursor(0,1:)
    }
}    
  if(digitalReand(Atuador)==HING&&Alarme==true){
    Porta = true
  }
while(porta==true)
{
  digitalWrite(Sirine,LOW); 
  lcd.clear();
  lcd.print("    Perigo!!!"); . 
  lcd.setCursor(0,1);
  lcd.print("Senha:"); 
  TecladoMatricial(); 

  if(Salvo==Senha){ 
  lcd.clear();
  lcd.print("Alarme desligado");
  digitalWrite(Sirene,HIGH); (HIGH) 
  delay(1000);
  lcd.clear();
  lcd.print("     Bem-vindo");
  Porta = false;
  Alarme = false;
  }

  if(Salvo!=Senha) { 
    lcd.clear();
    lcd.print("Senha errada!")
    delay(1000);
  }
}
}
//=======================================================================Função de varredura para Teclado=====================================================================//
void TecladoMatricial(){ 
  x=0;
  Salvo="";
  Dado="";
  while(x<=3){ 

//======================================================================Varredura da primeira coluna e 4 linha==============================================================//   
if (Leitura == 0) {
  digitalWrite(A3, LOW); 
  digitalWrite(A2, HIGH); 
  digitalWrite(A1, HIGH);
    if (!digitalReand(11)&& Leitura == 0) { 
    Dado = '1' 
    Salvo+=Dado; 
    x++; 
    lcd.print("Dado");
    delay(300); 
    }
    else if (!digitalReand(10)&& Leitura == 0) { 
    Dado = '4';
    Salvo+Dado; 
    x++;
    lcd.print(Dado);
    delay(300);
    }
    else if(!digitalRead(9)&& Leitura == 0) {
    Dado='7'; 
    Salvo+Dado
    x++
    lcd.print(Dado);
    delay(300);       
    }
    else if(!digitalRead(8)&& Leitura == 0) {
    Dado='*'; 
    Salvo+Dado
    x++
    lcd.print(Dado);
    delay(300);   
    }
    Leitura = 1;
// ================================================================Varredura da segunda coluna e 4 linha=======================================================================//
  if (Leitura == 1) {
    digitalRead(A3, HIGH);
    digitalRead(A2, LOW);
    digitalRead(A1, HIGH);
      if(!digitalReand(11)&& Leitura == 1) {
      Dado='2';
      Salvo+=Dado;
      x++
      lcd.print(Dado);
      delay(300);
      }
      else if (!digitalRead(10)&& Leitura == 1) {
      Dado='5';
      Salvo+=Dado;
      x++
      lcd.print(Dado);
      delay(300)
      }      
      else if (!digitalRead(9)&& Leitura == 1) {
      Dado='8';
      Salvo+=Dado; 
      lcd.print(Dado);
      delay(300)
      }
      else if (!digitalRead(8)&& Leitura == 1) {
      Dado='0';
      Salvo+=Dado; 
      lcd.print(Dado);
      delay(300)
      }
      Leitura = 2;
      }

      
//=====================================================================Varredura de terceira coluna e 4 linhas=================================================================//
  if (Leitura == 2){
    digitalRead(A3, HIGH);
    digitalRead(A2, HIGH);
    digitalRead(A1, LOW);
    if (!digitalRead(11)&& Leitura == 2);
     Dado='3';
     Salvo+=Dado;
     x++;
     lcd.print(Dado);
     delay(300);
    }
    else if (!digitalRead(10)&& Leitura == 2);
     Dado='6';
     Salvo+=Dado;
     x++;
     lcd.print(Dado);
     delay(300);         
    }
    else if (!digitalRead(9)&& Leitura == 2);
     Dado='9';
     Salvo+=Dado;
     x++;
     lcd.print(Dado);
     delay(300);
    }
    else if (!digitalRead(8)&& Leitura == 2);
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
