#include <Keypad.h>

// Pines del semáforo
int vehiculoRojo = 11;
int vehiculoAmarillo = 12;
int vehiculoVerde = 13;

// Configuración del teclado matricial
const byte filas = 4;
const byte columnas = 4;
byte pinesFilas[] = {9, 8, 7, 6};
byte pinesColumnas[] = {5, 4, 3, 2};
char teclas[4][4] = {{'1', '2', '3', 'A'},
                     {'4', '5', '6', 'B'},
                     {'7', '8', '9', 'C'},
                     {'*', '0', '#', 'D'}};
Keypad teclado1 = Keypad(makeKeymap(teclas), pinesFilas, pinesColumnas, filas, columnas);

int horaActual = 0;

void setup() {
  Serial.begin(9600);
  pinMode(vehiculoRojo, OUTPUT);
  pinMode(vehiculoAmarillo, OUTPUT);
  pinMode(vehiculoVerde, OUTPUT);

  Serial.println("Ingrese la hora actual (0-23):");
}

void loop() {
  char teclaPresionada = teclado1.getKey();

  if (teclaPresionada) {
    if (teclaPresionada >= '0' && teclaPresionada <= '9') {
      horaActual = horaActual * 10 + (teclaPresionada - '0');
      Serial.print(teclaPresionada);
    }
    if (teclaPresionada == '#') {
      Serial.println();
      Serial.print("Hora ingresada: ");
      Serial.println(horaActual);

      if (horaActual >= 3 && horaActual < 16) {
        semaforoNormal(10000, 5000, 2000);  // Funcionamiento normal
      } else if (horaActual >= 16 && horaActual < 24) {
        semaforoNormal(20000, 10000, 4000); // Tiempos duplicados
      } else {
        semaforoModoLibre(); // Funcionamiento libre
      }

      horaActual = 0;  // Reiniciar la hora para otra entrada
      Serial.println("Ingrese la hora actual (0-23):");
    }
  }
}

// Función para el funcionamiento normal del semáforo
void semaforoNormal(int tiempoRojo, int tiempoVerde, int tiempoAmarillo) {
  while (true) {
    digitalWrite(vehiculoRojo, HIGH);
    delay(tiempoRojo);
    digitalWrite(vehiculoRojo, LOW);

    digitalWrite(vehiculoVerde, HIGH);
    delay(tiempoVerde);
    digitalWrite(vehiculoVerde, LOW);

    digitalWrite(vehiculoAmarillo, HIGH);
    delay(tiempoAmarillo);
    digitalWrite(vehiculoAmarillo, LOW);    
    char teclaPresionada = teclado1.getKey();
    if (teclaPresionada == '*') 
      break;
  }
}

// Función para el modo libre (luz amarilla parpadeando)
void semaforoModoLibre() {
  while (true) {
    digitalWrite(vehiculoAmarillo, HIGH);
    delay(500);
    digitalWrite(vehiculoAmarillo, LOW);
    delay(500);
    char teclaPresionada = teclado1.getKey();
    if (teclaPresionada == '*') 
      break;
  }
}