#define PIN_LED 7
unsigned int count, toggle,period,duty_int;
double q,duty;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  toggle = 1;
  period=100;
  q=500000/period;
  duty=0;
}

void loop() {
  toggle = toggle_state(toggle);
  duty_int=set_duty(duty);
  digitalWrite(PIN_LED, toggle);
  delayMicroseconds(double(period/100)*(duty_int));
  toggle = toggle_state(toggle);
  digitalWrite(PIN_LED, toggle);
  delayMicroseconds(double(period/100)*(100-duty_int));
}

int toggle_state(int toggle) {
  return !toggle;
}



int set_duty(double duty1){
  duty=duty1+(100/q);
  if(duty>=100 || duty<=0) q= -q;
  return int(duty);
} 
