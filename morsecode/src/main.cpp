#include <Arduino.h>

// assigning input number
int ledPin = 2;
// assigning dots and dashes
int dot = 100;
int dash = 300;
//  setup performs initializations
void setup()
{
  // initialize the serial port setting its speed to 9600 Baud:
  Serial.begin(9600);
  // initializing ledPin
  pinMode(ledPin, OUTPUT);
}
// the loop() method runs over and over again,
// as long as the Arduino has power
void loop()
{
  if (Serial.available() > 0)
  {
    // Read the incoming byte
    String morseString = Serial.readString();
    Serial.print("You entered: ");
    Serial.println(morseString);
    delay(1000);
    for (int i = 0; i < morseString.length(); i++)
    {
      // assigning each number with its morse pattern
      switch (morseString[i])
      {
      case '0':
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        break;

      case '1':
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        break;

      case '2':
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        break;

      case '3':
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        break;

      case '4':
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        break;

      case '5':
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        break;

      case '6':
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        break;

      case '7':
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        break;

      case '8':
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        break;

      case '9':
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        break;

      case 'A':
      case 'a':
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        break;

      case 'B':
      case 'b':
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        break;

      case 'C':
      case 'c':
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        break;

      case 'D':
      case 'd':
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        break;

      case 'E':
      case 'e':
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        break;

      case 'F':
      case 'f':
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        break;

      case 'G':
      case 'g':
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        break;

      case 'H':
      case 'h':
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        break;

      case 'I':
      case 'i':
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        break;

      case 'J':
      case 'j':
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        break;

      case 'K':
      case 'k':
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        break;

      case 'L':
      case 'l':
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        break;

      case 'M':
      case 'm':
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        break;

      case 'N':
      case 'n':
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        break;

      case 'O':
      case 'o':
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        break;

      case 'P':
      case 'p':
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        break;

      case 'Q':
      case 'q':
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        break;

      case 'R':
      case 'r':
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        break;

      case 'S':
      case 's':
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        break;

      case 'T':
      case 't':
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        break;

      case 'U':
      case 'u':
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        break;

      case 'V':
      case 'v':
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        break;

      case 'W':
      case 'w':
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        break;

      case 'X':
      case 'x':
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        break;

      case 'Y':
      case 'y':
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        break;

      case 'Z':
      case 'z':
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dash);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        delay(dot);
        digitalWrite(ledPin, HIGH);
        delay(dot);
        digitalWrite(ledPin, LOW);
        break;

      default:
        break;
      }
      delay(dash);
    }
  }
}


