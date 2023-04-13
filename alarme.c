// Alarme
//A linguagem C é uma linguagem de programação de alto nível, desenvolvida para escrever sistemas operacionais.
//=============================================================================================================================================================================//
#include <LiquidCrystal.h> // Essa biblioteca é usada para controlar displays LCD
#define Buzzer A0 //Buzzer é um dispositivo eletrônico que produz som ou ruído, é oq vai dizer se o alarme está desligado ou ligado (A0)= porta
#define Atuador 12 //Atuador é um componente ou dispositivo que converte energia em movimento, é oq vai detectar que a porta foi aberta (12)=porta digital 
#define Sirene A4 //o relé vai acionar a sirene na porta (A4), vou mandar nivel baixo, vai acionar o relé, com isso vou acionar a sirene.

int Leitura = 0; //representar números inteiros, variável que vai ler 
int x = 0;
String Senha = "2551"; //é a nossa senha
String Salvo; //
String Dado;
bool Alarme = false; // a variável que indica que o nosso alarme se inicial desligado 
bool Porta = false; // quando a porta estiver aberta, mesmo se fechar a porta,  ele vai continuar alarmando até colocar sua senha 


LiquidCrystal lcd(7, 6, 5, 4, 3, 2); //iniciamos o nosso displya em ()são os pinos que utilizamos.

void setup(){  //void setup é uma função padrão na linguagem de programação Arduino, é usada para inicializar o programa e definir o comportamento de algumas configurações iniciais, como as configurações dos pinos de entrada/saída, comunicação serial, timers, entre outras,é usada para inicializar o hardware e definir as configurações iniciais do programa, é configurar as entradas e saídas.

  lcd.begin(16, 2); //configura o lcd para ficar no formado 16:2, mais utilizado e mais simples
  pinMode(Buzzer, OUTPUT); // uma saída
  pinMode(Sirene, OUTPUT); // uam saída
  pinMode(Atuador, INPUT_PULLUP); //uma entrada, quando a porta abre, ele vai receber o sinal
  pinMode(A1, OUTPUT); //teclado
  pinMode(A2, OUTPUT); //teclado
  pinMode(A3, OUTPUT); //teclado
  pinMode(8, INPUT_PULLUP); //teclado
  pinMode(9, INPUT_PULLUP); //teclado (input_pullup) significa que é uma entrada, está habilitando o registore tipo up internos do arduinos, nivel alto
  pinMode(10, INPUT_PULLUP); //teclado
  pinMode(11, INPUT_PULLUP); //teclado
  digitalWrite(Sirene,HIGH); //madando nivel alto para começar a sirene ligada
//=============================================================================Configura a senha inicial=======================================================================//
  
  lcd.clear(); //limpou o lcd
  lcd.print("     Bem-vindo");  
}
void loop(){ //é executada continuamente em um loop infinito, até que o Arduino seja desligado ou o programa seja interrompido. é oq vai rodar o nosso programa o tempo todo!
if(digitalRead(8)==LOW) { // é uma função da linguagem de programação Arduino que é usada para ler o valor de um pino digital, precisso precionar o # no teclado, ai entra na função!, se o alarme estiver ligado, aperto o #, chama a (função teclado matricial), vai verificar a senha, vai dar um bem-vindo, ele dar 3 bips para dizer quer o alarme está desligado
     delay(300);
     lcd.clear();
     lcd.pritn("     Bem-vindo");
     lcd.setCursor(0,1);
     lcd.print("Senha: ");
     lcd.setCursor(7,1);
     TecladoMatricial(); //aqui vai digitar os 4 números da senha.
     if(salvo==senha&&Alarme==true) // aqui ela vai fazer a verificação da senha, o teclado matricial vai pegar cada dado e vai salvar na variável(salvo) e vai verificar a senha que digitou que vc colocou, se tiver ligado o alarme ele entra nessa condição
     lcd.clear();
     lcd.print("Alarme desligado");
     Alarme = false;
     tone(Buzzer,1000,1000);
     delay(300);
     tone(Buzzer,1000,1000)
     delay(300);         
    }
    else if(Salvo==senha&&Alarme==false) { // a senha correta, ele vai trabalhar essa função
    lcd.print("     Bem-vindo");
    lcd.setCursor(0,1);
    lcd.print("Alarme ligado"); // vai ligar o alarme
    Alarme = true;
    tone(Buzzer,1000,100); //ele vai acionar o buzzer em uma terminada frequencia (1000) no determinado tempo (100)
    delay(300);
    tone(Buzzer,1000,100);  //acionar novamente, vai dar 2 bips para dizer que o alarme está ligado.
    }
    else if(Salvo!=Senha){ //aqui vai digitar a senha novamente, antes disso ele vai continuar sempre fazendo a leitura 
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
  if(digitalReand(Atuador)==HING&&Alarme==true){ // se sua porta for aberta o alarme e estiver ligado, vai com nível alto, vai falar que a porta é verdadeira, vai continuar tocando até colocar a senha de volta
    Porta = true
  }
while(porta==true)
{
  digitalWrite(Sirine,LOW); // liga a sirene, obs= nivel LOW=BAIXO ativa a sirene, vai ativar no relé
  lcd.clear();
  lcd.print("    Perigo!!!"); //entra uma mensagem de perigo. 
  lcd.setCursor(0,1);
  lcd.print("Senha:"); // ai já printa uma mensagem para colocar de novo a senha 
  TecladoMatricial(); //aqui ele ta preso na função (tecladoMatricial), tem que colocar a senha para parar de tocar a sirene

  if(Salvo==Senha){ //obs: toda vez que eu chamo a função teclado, eu limpo minha variável (Salvo). aqui ele vai verificar e se senha que colocou está certa,
  lcd.clear();
  lcd.print("Alarme desligado");
  digitalWrite(Sirene,HIGH); (HIGH) //sinal alto, ele manda sinal alto para o relé e ele desliga
  delay(1000);
  lcd.clear();
  lcd.print("     Bem-vindo");
  Porta = false;
  Alarme = false;
  }

  if(Salvo!=Senha) { //digitou a senhha errada, vai fica nessa função e ele volta para cima, e chama a função teclado
    lcd.clear();
    lcd.print("Senha errada!")
    delay(1000);
  }
}
}
// =======================================================================Função de varredura para Teclado=====================================================================//
void TecladoMatricial(){ //uma função
  x=0;
  Salvo="";
  Dado="";
  while(x<=3){ //é um lanço de repetição, quando for colocar a senha em 3 números vai se repetir essa função, passou de 3 números a senha, ela vai passar dessa função.

//======================================================================Varredura da primeira coluna e 4 linha==============================================================//   
if (Leitura == 0) {
  digitalWrite(A3, LOW); //primeira coluna, valor baixo
  digitalWrite(A2, HIGH); //
  digitalWrite(A1, HIGH);
    if (!digitalReand(11)&& Leitura == 0) { //quando sua digital Read no pino 11 for baixa e sua leitura FOR = 0, vai 1, pq o digital 11 está relacionado ao algarismo 1
    Dado = '1' // vai salvar esse número
    Salvo+=Dado; //aqui vai salvar esse dado mais de forma concatenada
    x++; // vai valer 1
    lcd.print("Dado");
    delay(300); //delay de 300ms
    }
    else if (!digitalReand(10)&& Leitura == 0) { //vai ser baixo, vai imprimir 4
    Dado = '4';
    Salvo+Dado; //aqui vai salvar esse dado mais de forma concatenada
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
