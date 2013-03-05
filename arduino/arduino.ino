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
int not_SH1 = base+6;
int not_SH2 = base+2;
int not_SH3 = base;

int OS1 = A0;
int OS2 = A1;
int OS3 = A3;

void setup() {
    pinMode(ledPin, OUTPUT);  

    pinMode(CLK, OUTPUT);
    pinMode(SW, OUTPUT);
    pinMode(CP, OUTPUT);
    pinMode(RS, OUTPUT);
    pinMode(not_SH1, OUTPUT);
    pinMode(not_SH2, OUTPUT);
    pinMode(not_SH3, OUTPUT);

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
int RS_pulseWidth = 5; // typical: 100 ns
int OS_settleTime = RS_pulseWidth; // typical: 100 ns
int CLK_pulseWidth = 5*RS_pulseWidth; // typical: 1000 ns
int SH_pulseWidth = 50*CLK_pulseWidth; // typical: 5000 ns

int CLK_RS_delay = 0;
int settle_CLK_delay = CLK_pulseWidth-RS_pulseWidth-OS_settleTime;

void loop() {
  ledLevel = ledLevel xor 1;
  digitalWrite(ledPin, ledLevel);

  digitalWrite(not_SH1, LOW);
  digitalWrite(not_SH2, LOW);
  digitalWrite(not_SH3, LOW);
  digitalWrite(CLK, HIGH);
  digitalWrite(RS, LOW);
  digitalWrite(CP, HIGH);
  digitalWrite(SW, LOW);

  delay(SH_pulseWidth);

  digitalWrite(not_SH1, HIGH);
  digitalWrite(not_SH2, HIGH);
  digitalWrite(not_SH3, HIGH);
  digitalWrite(CP, LOW);
  
  int clock = HIGH;
  for (int P=0; P < pixels; P++) {
    // invert clock
    digitalWrite(CLK, clock);
    clock = clock xor 1;
    delay(CLK_RS_delay);
    
    // reset pulse
//    digitalWrite(RS, HIGH);
    delay(RS_pulseWidth);
//    digitalWrite(RS, LOW);
    delay(OS_settleTime);
    
    // read analog data
    // analogRead(OS1);
    // analogRead(OS2);
    // analogRead(OS3);
    
    delay(settle_CLK_delay);
    }
}
