//youtube demo link - https://youtu.be/QfrrswfyH4E
#include <pitches.h>
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// display initiators
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// initializing variables for sensor and speaker
const int buzzerPin = 2;
const int sensorPin = 15;

// assigning wait key
bool waitingForKey = false;

// random init
int randInput=random(2300);

// initializing success condition
bool success = false;

// initializing counter
float count = 0;

// notes to play
int failed[] = {
    // failed note b4 a4 g4 f4 e4 d4 c4 c4 b3 a3
    NOTE_D4, NOTE_D4, NOTE_DS4, NOTE_C4, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3};
int victory[] = {
    // victory note A3 B3 C#4 D4 E4 F#4 G#4 A4"
    NOTE_A3, NOTE_B3, NOTE_CS4, NOTE_D4, NOTE_E4, NOTE_FS4, NOTE_GS4, NOTE_A4, NOTE_A4};
int opening[] = {
    // opening note b4 a4 g4 f4 e4 d4 c4 c4 b3 a3
    NOTE_B4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_B3, NOTE_A3};

int noteDurations[] = {

    4, 4, 4, 4, 8, 8, 8, 8, 8};

void openingSoundtrack()
{
  // opening soundtrack
  for (int thisNote = 0; thisNote < 8; thisNote++)
  {

    int noteDuration = 1000 / noteDurations[thisNote];

    tone(buzzerPin, opening[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    noTone(buzzerPin);
  }
}

void victorySoundtrack()
{
  // opening soundtrack
  for (int thisNote = 0; thisNote < 8; thisNote++)
  {

    int noteDuration = 1000 / noteDurations[thisNote];

    tone(buzzerPin, victory[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    noTone(buzzerPin);
  }
}

void failedSoundtrack()
{
  // opening soundtrack
  for (int thisNote = 0; thisNote < 8; thisNote++)
  {

    int noteDuration = 1000 / noteDurations[thisNote];

    tone(buzzerPin, failed[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    noTone(buzzerPin);
  }
}

void setup()
{
  // pin and serial initialization
  pinMode(buzzerPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);

  // initiating display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();

  openingSoundtrack();
}

void renderUI(int width, int height, int sensorValue, int count)
{
  display.clearDisplay();
  int circleLoc = map(randInput, 0, 2400, 30, 100);
  int currentIndicator = map(sensorValue, 0, 2400, 30, 100);
  display.drawRect(((SCREEN_WIDTH / 2) - (width / 2)), ((SCREEN_HEIGHT / 2) - (height / 2)), width, height, WHITE);
  display.drawCircle(circleLoc, (SCREEN_HEIGHT / 2), 12, WHITE);
  display.drawCircle(circleLoc, (SCREEN_HEIGHT / 2), 11, WHITE);
  display.fillCircle(currentIndicator, (SCREEN_HEIGHT / 2), 4, WHITE);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(14, 4);
  display.print("Time:");
  display.println(count);
  display.display();
}

void renderFailed()
{
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20, 0);
  display.print("Failed");
  display.setTextSize(1);
  display.setCursor(10, 20);
  display.println("Press to continue");
  display.display();
}

void renderSuccess()
{
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20, 0);
  display.print("Success");
  display.setTextSize(1);
  display.setCursor(10, 20);
  display.println("Press to continue");
  display.display();
}

void loop()
{

  if (waitingForKey)
  {
    if (Serial.available() > 0)
    {
      // Clear buffer
      while (Serial.available() > 0)
      {
        Serial.read();
      }
      display.clearDisplay();
      display.println("Starting new game");
      display.display();
      waitingForKey = false;
      success = false;
      count = 0;
      randInput = random(2300);
      openingSoundtrack();
    }

    return; // Stop here until key is pressed
  }
  int sensorValue = analogRead(sensorPin);
  int sensorEquivalent = map(abs(sensorValue - randInput), 0, 2300, 0, 1000);
  if (sensorEquivalent >= 700)
  {
    analogWrite(buzzerPin, NOTE_B1);
  }
  else if (sensorEquivalent >= 500)
  {
    analogWrite(buzzerPin, NOTE_B2);
  }
  else if (sensorEquivalent >= 400)
  {
    analogWrite(buzzerPin, NOTE_B3);
  }
  else if (sensorEquivalent >= 300)
  {
    analogWrite(buzzerPin, NOTE_B4);
  }
  else if (sensorEquivalent >= 200)
  {
    analogWrite(buzzerPin, NOTE_B5);
  }
  else if (sensorEquivalent >= 100)
  {
    analogWrite(buzzerPin, NOTE_B6);
  }
  else if (sensorEquivalent >= 50)
  {
    analogWrite(buzzerPin, NOTE_B7);
  }
  else if (sensorEquivalent >= 20)
  {
    analogWrite(buzzerPin, NOTE_C8);
  }
  else
  {
    analogWrite(buzzerPin, 0);
    success = true;
  }
  count = count + 0.1;
  delay(100);

  if (!success)
  {
    if ((count <= 10))
    {
      renderUI(100, 30, sensorValue, count);
    }
    else if ((count > 10))
    {
      analogWrite(buzzerPin, 0);
      renderFailed();
      failedSoundtrack();
      waitingForKey = true;
    }
  } 
  else
  { 
    renderSuccess();
    victorySoundtrack();
    waitingForKey = true;
  }
}