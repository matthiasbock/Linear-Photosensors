int ledPin = 13;
int ledLevel = LOW;

//
// Pins where the CCD board is connected to the Arduino
//
int base = 46;
int CLK = base+1;
int SW = base+3;
int CP = base+4;
int RS = base+5;
int SH1 = base+6;
int SH2 = base+2;
int SH3 = base;

int OS1 = A0;
int OS2 = A1;
int OS3 = A3;

void setup() {
    pinMode(ledPin, OUTPUT);  

    pinMode(CLK, OUTPUT);
    pinMode(SW, OUTPUT);
    pinMode(CP, OUTPUT);
    pinMode(RS, OUTPUT);
    pinMode(SH1, OUTPUT);
    pinMode(SH2, OUTPUT);
    pinMode(SH3, OUTPUT);

    pinMode(OS1, INPUT);
    pinMode(OS2, INPUT);
    pinMode(OS3, INPUT);
}

//
// line clamp mode
// TCD2905D datasheet page 8
//
// one line readout period has 10878 peaks
int dummy1 = 64;
int signal = 10800;
int dummy2 = 14;
int pixels = dummy1 + signal + dummy2;

// timing in nanoseconds (ns)
int RS_pulseWidth = 3; // typical: 100 ns
int OS_settleTime = 0; // typical: 100 ns
int CLK_pulseWidth = 6; // typical: 1000 ns
int SH_pulseWidth = 6; // typical: 5000 ns

int half = (CLK_pulseWidth-RS_pulseWidth)/2;

void loop() {
  ledLevel = ledLevel xor 1;
  digitalWrite(ledPin, ledLevel);

  digitalWrite(SH1, HIGH);
  digitalWrite(SH2, HIGH);
  digitalWrite(SH3, HIGH);
  digitalWrite(CLK, HIGH);
  digitalWrite(RS, LOW);
  digitalWrite(CP, HIGH);
  digitalWrite(SW, LOW);

  delay(SH_pulseWidth);

  digitalWrite(SH1, LOW);
  digitalWrite(SH2, LOW);
  digitalWrite(SH3, LOW);
  digitalWrite(CP, LOW);
  
  int clock = HIGH;
  for (int P=0; P < pixels; P++) {
    //
    // invert clock
    // with every clock inversion another value is kicked out of the CCD
    //
    clock = clock xor 1;
    digitalWrite(CLK, clock);

//    delay(OS_settleTime);
    // read analog data
    // analogRead(OS1);
    // analogRead(OS2);
    // analogRead(OS3);

    delay(3);
    
    //
    // reset pulse
    // depletes the current value's capacitor
    //
    digitalWrite(RS, HIGH);
    delay(3);
    digitalWrite(RS, LOW);
    }
}
