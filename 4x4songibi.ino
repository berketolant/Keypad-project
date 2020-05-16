//MCE 202 BERKE TOLANT

const int b3 = 988;   const int a93 = 932;   const int a3 = 880;   
const int g93 = 831;  const int g3 = 784;    const int f93 = 740; 
const int f3 = 698;   const int e3 = 659;    const int d93 = 622; 
const int d3 = 587;   const int c93 = 554;   const int c3 = 523;
const int b2 = 494;   const int a92 = 466;   const int a2 = 440;
const int g92 = 415;  const int g2 = 392;    const int f92 = 370;
const int f2 = 349;   const int e2 = 329;    const int d92 = 311;
const int d2 = 294;   const int c92 = 277;   const int c2 = 262;
const int b = 247;    const int a9 = 233;    const int a = 220;
const int g9 = 208;   const int g = 196;     const int f9 = 185;
const int f = 175;    const int e = 165;     const int d9 = 156;
const int d = 147;    const int c9 = 139;    const int c = 131;
const int x = 0;          // our notes and their frequencies(Hz)

const byte piezoPin = 3;  // Defining LED and piezo pins
const byte redLED   = 2;  
const byte greenLED = 12;
const byte blueLED  = 13;

int counter = 0;          // counter for led & buzzer synchronization

const byte column1 = 7;   // Defining column pins
const byte column2 = 6;
const byte column3 = 5;
const byte column4 = 4;

const byte row1 = 11;     // Defining row pins
const byte row2 = 10;
const byte row3 = 9;
const byte row4 = 8;

void setup() {
  Serial.begin(9600);               // to use serial monitor

  pinMode(row1, OUTPUT);            // here we set row pins as OUTPUT
  pinMode(row2, OUTPUT);
  pinMode(row3, OUTPUT);
  pinMode(row4, OUTPUT);

  pinMode(column1, INPUT_PULLUP);   // here we set column pins as PULLUP so they can stay HIGH till the input signal
  pinMode(column2, INPUT_PULLUP);
  pinMode(column3, INPUT_PULLUP);
  pinMode(column4, INPUT_PULLUP);

  pinMode(piezoPin, OUTPUT);        // here we set piezo and LED pins as OUTPUT
  pinMode(redLED,   OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED,  OUTPUT);
  }

void loop() {
  row1Check();          // in our loop, we are calling our row functions one by one for controlling row pin states 
  row2Check();
  row3Check();
  row4Check();
}

void row1Check() {
  digitalWrite(row1, LOW);               //   here we set row1 as LOW, others as HIGH for getting a path to column pins
  digitalWrite(row2, HIGH);
  digitalWrite(row3, HIGH);
  digitalWrite(row4, HIGH);
  
  if (digitalRead(column1) == LOW) {      //  here we are checking state of column1. If it is LOW then;
    Serial.println("1 PRESSED -> COLOUR : RED"); 
    LEDon(redLED, 0, 0);
    delay(500);                           //  we have delay for each action -> catching difference between one-click and long-press
    LEDoff(redLED, 0, 0);
  }
  if (digitalRead(column2) == LOW) {      //  here we are checking state of column2. If it is LOW then;
    Serial.println("2 PRESSED -> COLOUR : GREEN"); 
    LEDon(0, greenLED, 0);
    delay(500);        
    LEDoff(0, greenLED, 0);
  }
  if (digitalRead(column3) == LOW) {      //  here we are checking state of column3. If it is LOW then;
    Serial.println("3 PRESSED -> COLOUR : BLUE"); 
    LEDon(0, 0, blueLED);
    delay(500);        
    LEDoff(0, 0, blueLED);
  }
  if (digitalRead(column4) == LOW) {      //  here we are checking state of column4. If it is LOW then;
    Serial.println("A PRESSED -> COLOUR BLINK : RED"); 
    LEDblink(redLED, 0, 0);
    delay(500);        
    }
  }

void row2Check() {
  digitalWrite(row1, HIGH);
  digitalWrite(row2, LOW);
  digitalWrite(row3, HIGH);
  digitalWrite(row4, HIGH);

  if (digitalRead(column1) == LOW) {     
    Serial.println("4 PRESSED -> COLOUR : YELLOW"); 
    LEDon(redLED, greenLED, 0);
    delay(500);        
    LEDoff(redLED, greenLED, 0);
  }
  if (digitalRead(column2) == LOW) {      
    Serial.println("5 PRESSED -> COLOUR : PURPLE"); 
    LEDon(redLED, 0, blueLED);
    delay(500);        
    LEDoff(redLED, 0, blueLED);
  }
  if (digitalRead(column3) == LOW) {      
    Serial.println("6 PRESSED -> COLOUR : CYAN (my fav.)"); 
    LEDon(0, greenLED, blueLED);
    delay(500);        
    LEDoff(0, greenLED, blueLED);
  }
  if (digitalRead(column4) == LOW) {      
    Serial.println("B PRESSED -> COLOUR BLINK : GREEN"); 
    LEDblink(0, greenLED, 0);
    delay(500);        
    }
  }

void row3Check() {
  digitalWrite(row1, HIGH);
  digitalWrite(row2, HIGH);
  digitalWrite(row3, LOW);
  digitalWrite(row4, HIGH);

  if (digitalRead(column1) == LOW) {     
    Serial.println("7 PRESSED -> NOTE C (DO)");
    beep(c3, 500);
    delay(500);
  }
  if (digitalRead(column2) == LOW) {      
    Serial.println("8 PRESSED -> NOTE D (RE)"); 
    beep(d3, 500);
    delay(500);        
    }
  if (digitalRead(column3) == LOW) {      
    Serial.println("9 PRESSED -> NOTE E (MI)"); 
    beep(e3, 500);
    delay(500);
  }
  if (digitalRead(column4) == LOW) {      
    Serial.println("C PRESSED -> C D E MELODY"); 
    beep(c3, 500);
    beep(d3, 500);
    beep(e3, 500);
    delay(500);        
    }
  }

void row4Check() {
  digitalWrite(row1, HIGH);
  digitalWrite(row2, HIGH);
  digitalWrite(row3, HIGH);
  digitalWrite(row4, LOW);

  if (digitalRead(column1) == LOW) {
    Serial.println("* PRESSED -> LETS CALL THE POLICE");
    delay(500);
    EveryBreathYouTake();
  }
  if (digitalRead(column2) == LOW) {
    Serial.println("0 PRESSED"); 
    delay(500);
  }
  if (digitalRead(column3) == LOW) {
    Serial.println("# PRESSED -> LETS CALL COFFIN GUYS"); 
    delay(500);
    CoffinDance();
    CoffinDance();
  }
  if (digitalRead(column4) == LOW) {   
    Serial.println("D PRESSED"); 
    delay(500);
  }
}

void LEDon(byte R, byte G, byte B)
{
  digitalWrite(R, HIGH);  // a function for turn on LED
  digitalWrite(G, HIGH);
  digitalWrite(B, HIGH);
  }

void LEDoff(byte R, byte G, byte B)
{
  digitalWrite(R, LOW);  // a function for turn off LED
  digitalWrite(G, LOW);
  digitalWrite(B, LOW);
  }

void LEDblink(byte R, byte G, byte B)
{
  for(int i=0; i<3; i++){
  digitalWrite(R, HIGH); // a function for blinking LED
  digitalWrite(G, HIGH);
  digitalWrite(B, HIGH);
  delay(500);
  digitalWrite(R, LOW);
  digitalWrite(G, LOW);
  digitalWrite(B, LOW);
  delay(500);
  }
  }

void beep(int note, int duration)
{
tone(piezoPin, note, duration);  // a function for getting notes from piezo and led synchronization
 
if(counter % 2 == 0){
digitalWrite(blueLED, HIGH);
delay(duration);
digitalWrite(blueLED, LOW);
}
else{
digitalWrite(greenLED, HIGH);
delay(duration);
digitalWrite(greenLED, LOW);
}

noTone(piezoPin);
delay(50);
counter++;
}

void EveryBreathYouTake()
{
  ///////////////1
beep(a, 210);       // The Police - Every Breath You Take melody
beep(e2, 210);
beep(b2, 210);
beep(e2, 210);
beep(c92, 210);
beep(b2, 210);
beep(e2, 210);
beep(b2, 210);
/////////////////2
beep(a, 210);
beep(e2, 210);
beep(b2, 210);
beep(e2, 210);
beep(c92, 210);
beep(b2, 210);
beep(e2, 210);
beep(a2, 210);
////////////////3
beep(f9, 210);
beep(c92, 210);
beep(g92, 210);
beep(c92, 210);
beep(a2, 210);
beep(g92, 210);
beep(c92, 210);
beep(g92, 210);
////////////////4
beep(f9, 210);
beep(c92, 210);
beep(g92, 210);
beep(c92, 210);
beep(a2, 210);
beep(g92, 210);
beep(c92, 210);
beep(e2, 210);
////////////////5
beep(d2, 210);
beep(f92, 210);
beep(e3, 210);
beep(f92, 210);
beep(d3, 210);
beep(a2, 210);
beep(f92, 210);
beep(a2, 210);
////////////////6
beep(e2, 210);
beep(b2, 210);
beep(f93, 210);
beep(b2, 210);
beep(e3, 210);
beep(b2, 210);
beep(e2, 210);
beep(a2, 210);
  ///////////////7
beep(a, 210);
beep(e2, 210);
beep(b2, 210);
beep(e2, 210);
beep(c92, 210);
beep(b2, 210);
beep(e2, 210);
beep(b2, 210);
}

void CoffinDance()
{
  beep(e2, 200);   // i think you know what it is
  delay(200);
 
  beep(e2, 200);
  beep(b2, 200);
  beep(a2, 200);
  delay(200);

  beep(g2, 200);
  delay(200);

  beep(f92, 200);
  delay(200);

  beep(f92, 200);
  beep(f92, 200);
  beep(a2, 200);
  delay(200);

  beep(g2, 200);
  beep(f92,210);
  beep(e2, 200);
  delay(200);

  beep(e2, 200);
  beep(g3, 210);
  beep(f93, 200);
  beep(g3, 205);
  beep(f93, 200);
  beep(g3, 200);
  delay(75);
  
  beep(e2, 200);
  delay(200);

  beep(e2, 200);
  beep(g3, 210);
  beep(f93, 200);
  beep(g3, 205);
  beep(f93, 200);
  beep(g3, 200);
  delay(200);
  }
