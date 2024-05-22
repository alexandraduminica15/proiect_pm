#define pin_gas 2
  #define pin_relay 3
  #define pin_buzzer 4
  #define pin_led_green 9
  #define pin_led_yellow 10
  #define pin_led_red 11
    
  void set_yellow_color() {
    digitalWrite(pin_led_yellow, HIGH);
    digitalWrite(pin_led_red, LOW);
    digitalWrite(pin_led_green, LOW);
  }
  void set_green_color() {
    digitalWrite(pin_led_yellow, LOW);
    digitalWrite(pin_led_red, LOW);
    digitalWrite(pin_led_green, HIGH);
  }
  void set_red_color() {
    digitalWrite(pin_led_yellow, LOW);
    digitalWrite(pin_led_red, HIGH);
    digitalWrite(pin_led_green, LOW);
  }
  void turn_off_led() {
    digitalWrite(pin_led_yellow, LOW);
    digitalWrite(pin_led_red, LOW);
    digitalWrite(pin_led_green, LOW);
  }

  void setup() {
    pinMode(pin_gas, INPUT);
    pinMode(pin_relay, OUTPUT);
    pinMode(pin_buzzer, OUTPUT);
    pinMode(pin_led_green, OUTPUT);
    pinMode(pin_led_yellow, OUTPUT);
    pinMode(pin_led_red, OUTPUT);

    noTone(pin_buzzer);
    turn_off_led();
    digitalWrite(pin_relay, HIGH);
  
    Serial.begin(9600);
  }

bool getGasLevel() {
  bool status = digitalRead(pin_gas);
  Serial.print("Nivel gaz = ");
  Serial.println(status);
  return status;
}

void loop() {
    
  bool gasLevel = getGasLevel();
    
  if (gasLevel == 0) {
    set_red_color();
    digitalWrite(pin_relay, LOW);
    for(int i = 0; i < 10; i++) {
      digitalWrite(pin_buzzer, HIGH);
      delay(10);
    }
    digitalWrite(pin_buzzer, LOW);
  } else {
    digitalWrite(pin_relay, HIGH);
    set_green_color();
  }  
    delay(100); 
}