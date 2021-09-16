int A_0 = 8;
int A_1 = 9;
int A_2 = 10;
int A_3 = 11;

int B_0 = 4;           
int B_1 = 5;
int B_2 = 6;
int B_3 = 7;

int C_0 = 2;
int C_1 = 3;
int C_2 = 12;
int C_3 = A5;

int D_0 = A0;
int D_1 = A1;
int D_2 = A2;
int D_3 = A3;

int valorA = 0;
int valorB = 0;
int valorC = 0;
int valorD = 0;


void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
  pinMode(A_0, INPUT_PULLUP);
  pinMode(A_1, INPUT_PULLUP);
  pinMode(A_2, INPUT_PULLUP);
  pinMode(A_3, INPUT_PULLUP);
  
  pinMode(B_0, INPUT_PULLUP);
  pinMode(B_1, INPUT_PULLUP);
  pinMode(B_2, INPUT_PULLUP);
  pinMode(B_3, INPUT_PULLUP);
  
  pinMode(C_0, INPUT_PULLUP);
  pinMode(C_1, INPUT_PULLUP);
  pinMode(C_2, INPUT_PULLUP);
  pinMode(C_3, INPUT_PULLUP);
  
  pinMode(D_0, OUTPUT);
  pinMode(D_1, OUTPUT);
  pinMode(D_2, OUTPUT);
  pinMode(D_3, OUTPUT);
  
  Serial.println("Iniciando...");

}

void loop() {
  // put your main code here, to run repeatedly:
    valorA = digitalRead(A_0) * 1;
    valorA = valorA + (digitalRead(A_1) * 2);
    valorA = valorA + (digitalRead(A_2) * 4);
    valorA = valorA + (digitalRead(A_3) * 8);
  
    valorB = digitalRead(B_0) * 1;
    valorB = valorB + (digitalRead(B_1) * 2);
    valorB = valorB + (digitalRead(B_2) * 4);
    valorB = valorB + (digitalRead(B_3) * 8);

  
    valorC = digitalRead(C_0) * 1;
    valorC = valorC + (digitalRead(C_1) * 2);
    valorC = valorC + (digitalRead(C_2) * 4);
    valorC = valorC + (digitalRead(C_3) * 8);
  
    Serial.print(valorA);
    Serial.print(" ");
    Serial.print(valorB);
    Serial.print(" ");
    Serial.println(valorC);

switch(valorC)
    {
      case 0:
    valorD = valorA;
      break;
      case 1:
        valorD = valorA + 1;
      break;
      case 2:
        valorD = valorA + valorB;
      break;
      case 3:
        valorD = valorA + valorB + 1;
      break;
      case 4:
        valorD = valorA - valorB - 1;
      break;
      case 5:
        valorD = valorA - valorB;
      break;
      case 6:
        valorD = valorA - 1;
      break;
      case 7:
        valorD = valorA;
      break;
      case 8:
        valorD = valorA | valorB;
      break;
      case 10:
        valorD = valorA ^ valorB;
      break;
      case 12:
        valorD = valorA & valorB;
      break;
      case 14:
        valorD = ~valorA;
      break;
    }  
  digitalWrite(D_0, valorD & 1);
  digitalWrite(D_1, valorD & 2);
  digitalWrite(D_2, valorD & 4);
  digitalWrite(D_3, valorD & 8);

}

