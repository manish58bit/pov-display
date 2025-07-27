#define NUM_LEDS 10
#define HALL_PIN 2
#define ALWAYS_ON_LED 13

// LED pins from D3 to D12
const int ledPins[NUM_LEDS] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

// Delay between columns (tune as per rotation speed)
const int columnDelay = 5; // in milliseconds

// "JAI HIND" — 10-bit column data per character (bottom LED = bit 0, top LED = bit 9)
const uint16_t jaiHind[] = {
  // J
  0b0000000000,
  0b0011111110,
  0b0000001000,
  0b0000001000,
  0b0000001000,
  0b0100001000,
  0b0011110000,
  0b0000000000,

  // Space
  0b0000000000,

  // A
  0b0001100000,
  0b0010010000,
  0b0100001000,
  0b0111111000,
  0b0100001000,
  0b0100001000,
  0b0000000000,

  // Space
  0b0000000000,

  // I
  0b0111111100,
  0b0000100000,
  0b0000100000,
  0b0000100000,
  0b0111111100,
  0b0000000000,

  // Space
  0b0000000000,

  // H
  0b0100000100,
  0b0100000100,
  0b0100000100,
  0b0111111100,
  0b0100000100,
  0b0100000100,
  0b0000000000,

  // Space
  0b0000000000,

  // I
  0b0111111100,
  0b0000100000,
  0b0000100000,
  0b0000100000,
  0b0111111100,
  0b0000000000,

  // Space
  0b0000000000,

  // N
  0b0100000100,
  0b0110000100,
  0b0101000100,
  0b0100100100,
  0b0100011100,
  0b0100000100,
  0b0000000000,

  // Space
  0b0000000000,

  // D
  0b0111110000,
  0b0100001000,
  0b0100000100,
  0b0100000100,
  0b0100001000,
  0b0111110000,
  0b0000000000,
};

const int messageLength = sizeof(jaiHind) / sizeof(jaiHind[0]);

void setup() {
  // Set LED pins as output
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }

  pinMode(HALL_PIN, INPUT_PULLUP);         // Hall sensor
  pinMode(ALWAYS_ON_LED, OUTPUT);          // Always-on LED
  digitalWrite(ALWAYS_ON_LED, HIGH);       // Turn on always-on LED at start
}

void displayColumn(uint16_t colData) {
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(ledPins[i], (colData >> i) & 0x01);
  }
}

void clearAllLEDs() {
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}

void loop() {
  // Wait for the Hall sensor to detect the magnet
  while (digitalRead(HALL_PIN) == HIGH);  // Wait for LOW signal
  delay(5);  // Debounce
  while (digitalRead(HALL_PIN) == LOW);   // Wait until magnet passes

  // Display "JAI HIND" column by column
  for (int i = 0; i < messageLength; i++) {
    displayColumn(jaiHind[i]);
    delay(columnDelay);
    clearAllLEDs();
  }
}
