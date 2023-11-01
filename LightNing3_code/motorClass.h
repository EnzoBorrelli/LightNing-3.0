class Motor {
private:
  int _pwmMotor;
  int _pwmPin;
  int _pinMotorA;
  int _pinMotorB;
  long _freq;
  int _res;
  bool classDebug = true;

public:
  Motor(int pwmMotor, int pwmPin, int pinMotorA, int pinMotorB, long freq, int res) {
    _pwmMotor = pwmMotor;
    _pwmPin = pwmPin;
    _pinMotorA = pinMotorA;
    _pinMotorB = pinMotorB;
    _freq = freq;
    _res = res;

    ledcSetup(_pwmMotor, _freq, _res);
    ledcAttachPin(_pwmPin, _pwmMotorB);
  }

  void MotorUp(int speed) {
    ledcWrite(_pwmMotor, speed);
    digitalWrite(pinMotorA, HIGH);
    digitalWrite(pinMotorB, LOW);
    if (classDebug) Serial.println("motor UP");
  }
  void MotorDown(int speed) {
    ledcWrite(_pwmMotor, speed);
    digitalWrite(pinMotorB, HIGH);
    digitalWrite(pinMotorA, LOW);
    if (classDebug) Serial.println("motor DOWN");
  }
  void MotorStop() {
    ledcWrite(_pwmMotor, LOW);
    digitalWrite(pinMotorA, LOW);
    digitalWrite(pinMotorB, LOW);
    if (classDebug) Serial.println("motor STOP");
  }
};