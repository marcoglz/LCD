//En el presente pograma se pueden seleccionar, tanto vizulizar la hora,
//la temperatura, y los mensajes que se mandan desde un apliacion en java
//mediante la comunicacion del serial, y el puerto al que esta conectado el 
//arduino, el cual en un LCD se reflejara la informaion que se seleccione
//La temepratura esta dada en grados C
//Obtines la hora y la fecha del sistema que se guardo en el relog


#include <RTClib.h>//Libreria del reloj 
#include <LiquidCrystal.h>//Libreria LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);//Pines declarados del LCD
int imprimir = 0;//Imprecion del mensaje
String Mensaje = "";//Captura el mensaje
int seleccion=0;//Indica la opcion seleccionada
RTC_DS1307 RTC;//Se establece el modelo del relog

float centi() {//Conversion de temperatura a grados
  int dato;
  float c;
  dato = analogRead (A0);//Pin donde se conecto el sensor
  //esto es para convertir a centimetros, que te lo da en voltaje
  c = (500.0 * dato) / 1023;
  return (c);//Retorna los valores capturados por el sensor
}




void setup() {
  lcd.begin(16, 2);//Se construlle el LCD
  Serial.begin(9600);//Se inicializa el serial 
  RTC.begin();//Se inicializa el reloj
}

void loop() {
  float centigrados = centi();
  DateTime now = RTC.now(); // Obtiene la fecha y hora del RTC
  //Compara las opciones seleccionadas
  if (Serial.available() > 0) {
      seleccion = Serial.read();

    if (seleccion == '0'){//Imprime el mensaje en la pantalla
      lcd.clear();
      lcd.print("Elige una opcion");
    }else if(seleccion=='1'){//Imprime la temperatura
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("Temperatura");

      lcd.setCursor(0, 1);
      lcd.print(centigrados);
      delay(200);
    }else if(seleccion=='2'){//Imprime la fecha
      lcd.clear();
      Serial.print(now.year(), DEC); // Año
      Serial.print('/');
      Serial.print(now.month(), DEC); // Mes
      Serial.print('/');
      Serial.print(now.day(), DEC); // Dia
      Serial.print(' ');
      Serial.print(now.hour(), DEC); // Horas
      Serial.print(':');

      Serial.print(now.minute(), DEC); // Minutos
      Serial.print(':');
      Serial.print(now.second(), DEC); // Segundos
      Serial.println();
      lcd.setCursor(0, 0);
      lcd.print("Fecha: ");
      lcd.print(now.year(), DEC);
      lcd.print("/");
      lcd.print(now.month(), DEC);
      lcd.print("/");
      lcd.print(now.day(), DEC);
      lcd.print("   ");
      lcd.setCursor(0, 1);
      lcd.print("Hora: ");
      lcd.print(now.hour(), DEC);
      lcd.print(":");
      lcd.print(now.minute(), DEC);
      lcd.print(":");
      lcd.print(now.second(), DEC);
      delay(1000); // La información se actualiza cada 1 seg.
      lcd.setCursor(0, 0);
      lcd.print("                  ");
      lcd.setCursor(0, 1);
      lcd.print("                  ");

      
    }else{//Captura los mensajes que lee el serial o la aplicacion del java
      lcd.clear();
      int cuenta = 0;
      int caracteres = 0;
      //En este lado mandas a llamar el mensaje que estas escribiendo en el cual los mensajes se muestran en el ciclo.
      while (Serial.available() > 0) {
      Mensaje = Mensaje + Decimal_to_ASCII(Serial.read());
        cuenta++;
      }
      caracteres = Mensaje.length(); // manda a llamar cuantos caracteres tiene la palabara no tiene que ser mas de 16 digitos, si pasa se brinca a la siguiente linea
      if (caracteres > 16) {
        if (Mensaje != "") {
          lcd.clear();
          lcd.print(Mensaje.substring(0, 16));
          lcd.setCursor(0, 1);
          lcd.print(Mensaje.substring(16, caracteres));
        }
      }
      else
      {
        if (Mensaje != "") {
          lcd.clear();
          lcd.print(Mensaje);
        }
      }
      delay(1000);// se espera un tiempo en el cual puede leer los caracteres
      Mensaje = "";
    }
  }

  }

  // en esta parte se declara todas las letras de abecedario,tambien algunos simbolos y tambien los numeros 0-9, que es lo que hace?? dibuja todas las letras que entren al arduino
  char Decimal_to_ASCII(int entrada) {
  char salida = ' ';
  switch (entrada) {
    case 32:
      salida = ' ';
      break;
    case 33:
      salida = '!';
      break;
    case 34:
      salida = '"';
      break;
    case 35:
      salida = '#';
      break;
    case 36:
      salida = '$';
      break;
    case 37:
      salida = '%';
      break;
    case 38:
      salida = '&';
      break;
    case 39:
      salida = ' ';
      break;
    case 40:
      salida = '(';
      break;
    case 41:
      salida = ')';
      break;
    case 42:
      salida = '*';
      break;
    case 43:
      salida = '+';
      break;
    case 44:
      salida = ',';
      break;
    case 45:
      salida = '-';
      break;
    case 46:
      salida = '.';
      break;
    case 47:
      salida = '/';
      break;
    case 48:
      salida = '0';
      break;
    case 49:
      salida = '1';
      break;
    case 50:
      salida = '2';
      break;
    case 51:
      salida = '3';
      break;
    case 52:
      salida = '4';
      break;
    case 53:
      salida = '5';
      break;
    case 54:
      salida = '6';
      break;
    case 55:
      salida = '7';
      break;
    case 56:
      salida = '8';
      break;
    case 57:
      salida = '9';
      break;
    case 58:
      salida = ':';
      break;
    case 59:
      salida = ';';
      break;
    case 60:
      salida = '<';
      break;
    case 61:
      salida = '=';
      break;
    case 62:
      salida = '>';
      break;
    case 63:
      salida = '?';
      break;
    case 64:
      salida = '@';
      break;
    case 65:
      salida = 'A';
      break;
    case 66:
      salida = 'B';
      break;
    case 67:
      salida = 'C';
      break;
    case 68:
      salida = 'D';
      break;
    case 69:
      salida = 'E';
      break;
    case 70:
      salida = 'F';
      break;
    case 71:
      salida = 'G';
      break;
    case 72:
      salida = 'H';
      break;
    case 73:
      salida = 'I';
      break;
    case 74:
      salida = 'J';
      break;
    case 75:
      salida = 'K';
      break;
    case 76:
      salida = 'L';
      break;
    case 77:
      salida = 'M';
      break;
    case 78:
      salida = 'N';
      break;
    case 79:
      salida = 'O';
      break;
    case 80:
      salida = 'P';
      break;
    case 81:
      salida = 'Q';
      break;
    case 82:
      salida = 'R';
      break;
    case 83:
      salida = 'S';
      break;
    case 84:
      salida = 'T';
      break;
    case 85:
      salida = 'U';
      break;
    case 86:
      salida = 'V';
      break;
    case 87:
      salida = 'W';
      break;
    case 88:
      salida = 'X';
      break;
    case 89:
      salida = 'Y';
      break;
    case 90:
      salida = 'Z';
      break;
    case 91:
      salida = '[';
      break;
    case 92:
      salida = ' ';
      break;
    case 93:
      salida = ']';
      break;
    case 94:
      salida = '^';
      break;
    case 95:
      salida = '_';
      break;
    case 96:
      salida = '`';
      break;
    case 97:
      salida = 'a';
      break;
    case 98:
      salida = 'b';
      break;
    case 99:
      salida = 'c';
      break;
    case 100:
      salida = 'd';
      break;
    case 101:
      salida = 'e';
      break;
    case 102:
      salida = 'f';
      break;
    case 103:
      salida = 'g';
      break;
    case 104:
      salida = 'h';
      break;
    case 105:
      salida = 'i';
      break;
    case 106:
      salida = 'j';
      break;
    case 107:
      salida = 'k';
      break;
    case 108:
      salida = 'l';
      break;
    case 109:
      salida = 'm';
      break;
    case 110:
      salida = 'n';
      break;
    case 111:
      salida = 'o';
      break;
    case 112:
      salida = 'p';
      break;
    case 113:
      salida = 'q';
      break;
    case 114:
      salida = 'r';
      break;
    case 115:
      salida = 's';
      break;
    case 116:
      salida = 't';
      break;
    case 117:
      salida = 'u';
      break;
    case 118:
      salida = 'v';
      break;
    case 119:
      salida = 'w';
      break;
    case 120:
      salida = 'x';
      break;
    case 121:
      salida = 'y';
      break;
    case 122:
      salida = 'z';
      break;
    case 123:
      salida = '{';
      break;
    case 124:
      salida = '|';
      break;
    case 125:
      salida = '}';
      break;
    case 126:
      salida = '~';
      break;
  }
  return salida;
}
