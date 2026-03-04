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
const int buttonPin = 15;

// assigning wait key
bool waitingForKey = false;

// random init
int randInput = map(random(70), 0, 70, 30, 100);

// initializing success condition
bool success = false;

// adding spawn buffer, spawning target circle with a growing animation
int spawnBuffer = 60;

// point initiating
int points = 0;

// initiating hit duration
int hitIndicator = 0;

// initiating hit duration
int missIndicator = 0;

// initializing last hit marker
int hitMarker = 0;
int missMarker = 0;

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
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);

  // initiating display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();

  openingSoundtrack();
}

void renderUI(int width, int height, int currentIndicator, int count, bool hit, bool miss)
{
  display.clearDisplay();
  int circleLoc = randInput;
  
  //frame - indicator of moving circle
  display.drawRoundRect(((SCREEN_WIDTH / 2) - (width / 2)), ((SCREEN_HEIGHT / 2) - (height / 2)), width, height, 20, WHITE);
  
  //target circle
  display.drawCircle(circleLoc, (SCREEN_HEIGHT / 2), 12 -(spawnBuffer / 10), WHITE);
  display.drawCircle(circleLoc, (SCREEN_HEIGHT / 2), 11 - (spawnBuffer / 10), WHITE);
  display.drawCircle(circleLoc, (SCREEN_HEIGHT / 2), (spawnBuffer / 10) - 10, WHITE);

  //moving circle
  display.fillCircle(currentIndicator, (SCREEN_HEIGHT / 2), 4, WHITE);
  if(spawnBuffer>0)
  {
    spawnBuffer--;
  }
  // adding hit indicator and miss indicator buffers inorder to tackle brute forcing input
  if (hit && hitIndicator < 10)
  {
    missIndicator = 0;
    hitIndicator = 50;
    spawnBuffer = 60;
    points += 1;
    display.fillCircle(currentIndicator, (SCREEN_HEIGHT / 2), hitIndicator / 10, WHITE);
    hitMarker = currentIndicator;
    hitIndicator--;
  }
  // adding hit indicator buffer to avoid overlaping
  if (miss &&missIndicator<15&& hitIndicator < 20)
  {
    missIndicator = 50;
    missMarker = currentIndicator;
    display.drawLine(missMarker - missIndicator / 10, (SCREEN_HEIGHT / 2) - missIndicator / 10, missMarker + missIndicator / 10, (SCREEN_HEIGHT / 2) + missIndicator / 10, WHITE);
    display.drawLine(missMarker + missIndicator / 10, (SCREEN_HEIGHT / 2) - missIndicator / 10, missMarker - missIndicator / 10, (SCREEN_HEIGHT / 2) + missIndicator / 10, WHITE);
    missIndicator--;
  }
  if (hitIndicator > 0)
  {
    display.fillCircle(hitMarker, (SCREEN_HEIGHT / 2), (hitIndicator / 10), WHITE);
    hitIndicator--;
  }

  if (missIndicator > 0)
  {
    display.drawLine(missMarker - missIndicator / 10, (SCREEN_HEIGHT / 2) - missIndicator / 10, missMarker + missIndicator / 10, (SCREEN_HEIGHT / 2) + missIndicator / 10, WHITE);
    display.drawLine(missMarker + missIndicator / 10, (SCREEN_HEIGHT / 2) - missIndicator / 10, missMarker - missIndicator / 10, (SCREEN_HEIGHT / 2) + missIndicator / 10, WHITE);
    missIndicator--;
  }
  // display.setTextSize(1);
  // display.setTextColor(WHITE);
  // display.setCursor(14, 4);
  // display.print("Time:");
  // display.println(count);

  display.drawRoundRect( 14, 3, width, 5, 3, WHITE);
  display.fillRoundRect( 14, 3, count*(width/10), 5, 3, WHITE);

  //points
  display.setTextSize(1.5);
  display.setTextColor(WHITE);
  display.setCursor(40, 55);
  display.print("Points:");
  display.println(points);
  display.display();
}

void renderRoundOver()
{
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10, 0);
  display.print("Game Over");
  display.setTextSize(1);
  display.setCursor(10, 30);
  display.print("Your Score: ");
  display.print(points);
  display.setCursor(10, 50);
  display.print("Press to continue");
  display.display();
}



void loop()
{

  if (waitingForKey)
  {
    if (digitalRead(buttonPin) == LOW)
    {
      // Clear buffer
      while (digitalRead(buttonPin) == LOW)
      {
        if (digitalRead(buttonPin) == HIGH)
        {
          break;
        }
      }
      display.clearDisplay();
      display.setCursor(10, 30);
      display.print("Starting new game");
      display.display();
      waitingForKey = false;
      success = false;
      count = 0;
      points = 0;
      hitIndicator = 0;
      missIndicator = 0;
      hitMarker = 0;
      missMarker = 0;
      randInput = map(random(70), 0, 70, 30, 100);
      openingSoundtrack();
    }

    return; // Stop here until key is pressed
  }
  if (!success && count < 10)
  {
    for (int i = 30; i <= 100; i += 3)
    {
      if ((count > 10))
      {
        analogWrite(buzzerPin, 0);
        renderRoundOver();
        failedSoundtrack();
        waitingForKey = true;
        break;
      }
      if (digitalRead(buttonPin) == HIGH)
      {
        if (abs(i - randInput) < 10)
        {
          analogWrite(buzzerPin, NOTE_B0);
          renderUI(100, 30, i, count, true, false);
          randInput = map(random(70), 0, 70, 30, 100);
          analogWrite(buzzerPin, 0);
        }
        else if (abs(i - randInput) > 20)
        {
          analogWrite(buzzerPin, NOTE_B4);
          analogWrite(buzzerPin, NOTE_C4);
          analogWrite(buzzerPin, NOTE_B3);
          renderUI(100, 30, i, count, false, true);
          analogWrite(buzzerPin, 0);
        }
      }
      else
      {
        renderUI(100, 30, i, count, false, false);
      }
      count = count + 0.016;
    }
  }
  if (!success && count < 10)
  {
    for (int i = 100; i >= 30; i -= 3)
    {
      if ((count > 10))
      {
        analogWrite(buzzerPin, 0);
        renderRoundOver();
        failedSoundtrack();
        waitingForKey = true;
        break;
      }
      if (digitalRead(buttonPin) == HIGH)
      {
        if (abs(i - randInput) < 10)
        {
          analogWrite(buzzerPin, NOTE_B0);
          renderUI(100, 30, i, count, true, false);
          randInput = map(random(70), 0, 70, 30, 100);
          analogWrite(buzzerPin, 0);
        }
        else if (abs(i - randInput) > 20)
        {
          analogWrite(buzzerPin, NOTE_B4);
          analogWrite(buzzerPin, NOTE_C4);
          analogWrite(buzzerPin, NOTE_B3);
          renderUI(100, 30, i, count, false, true);
          analogWrite(buzzerPin, 0);
        }
      }
      else
      {
        renderUI(100, 30, i, count, false, false);
      }
      count = count + 0.016;
    }
  }
}