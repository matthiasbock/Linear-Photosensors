//
// Pins where the CCD board is connected to the Arduino
//
int CLK = 0;
int SW = 0;
int CP = 0;
int RS = 0;

int not_SH1 = 0;
int not_SH2 = 0;
int not_SH3 = 0;

int OS1 = 0;
int OS2 = 0;
int OS3 = 0;

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
int SH_pulseWidth = 5000;
int CLK_pulseWidth = 1000;
int RS_pulseWidth = 1000;
int SH_CLK_timing = 1000;

void delayNs(int ns) {
  delay(ns/1000);
}

void setup() {
}

void loop() {
  digitalWrite(not_SH1, LOW);
  digitalWrite(not_SH2, LOW);
  digitalWrite(not_SH3, LOW);
  int clock = HIGH;
  digitalWrite(CLK, clock);
  digitalWrite(RS, LOW);
  digitalWrite(CP, HIGH);
  digitalWrite(SW, LOW);

  delayNs(SH_pulseWidth);

  digitalWrite(not_SH1, HIGH);
  digitalWrite(not_SH2, HIGH);
  digitalWrite(not_SH3, HIGH);
  digitalWrite(CP, LOW);
  
  for (int P=0; P < pixels; P++) {
    delayNs(CLK_pulseWidth);
    
    // reset pulse
    digitalWrite(RS, HIGH);
    delayNs(RS_pulseWidth);
    digitalWrite(RS, LOW);
    
    // invert clock
    clock = clock xor 1;
    digitalWrite(CLK, clock);
  }
}
