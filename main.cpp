#include <SPI.h>
#include <MFRC522.h>
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>
#include <mp3tf16p.h>

MP3Player mp3(2, 3); //derecha, izquierda

#define RST_PIN	9    //el reset
#define SS_PIN	10   //SS (SDA)
MFRC522 mfrc522(SS_PIN, RST_PIN);

byte tarjetas[10][7] = {
{0x04, 0x91, 0xFA, 0x01, 0x8E, 0x04, 0x03},
{0x04, 0x32, 0x13, 0x01, 0x8D, 0x4B, 0x03},
{0x04, 0x12, 0xE2, 0x01, 0x9D, 0x4B, 0x03},
{0x04, 0x22, 0x42, 0x01, 0x01, 0x4B, 0x03},
{0x04, 0xF1, 0x2F, 0x01, 0xE3, 0x46, 0x03},
{0x04, 0xB1, 0x12, 0x01, 0xD7, 0x03, 0x03},
{0x04, 0xB1, 0x15, 0x01, 0xBC, 0x03, 0x03},
{0x04, 0xB0, 0x78, 0x01, 0xBC, 0x07, 0x03},
{0x04, 0x32, 0x02, 0x01, 0xDB, 0x4B, 0x03},
{0x04, 0xB1, 0x81, 0x01, 0xFA, 0x03, 0x03}
};

int numero = 0;
bool id;

void setup(void)
{
  Serial.begin(9600);
  mp3.initialize();
  SPI.begin();
  mfrc522.PCD_Init();
  mp3.player.pause();
}

void loop() {
	if ( mfrc522.PICC_IsNewCardPresent()) {
      if ( mfrc522.PICC_ReadCardSerial()) {
         for (int x = 0; x < 10; x++){
            id = true;
            for (int i = 0; i < 7; i++) {
               if (mfrc522.uid.uidByte[i] != tarjetas[x][i]){
                  id = false;
                  break;
               }
            }
            if (id){
               numero = x + 1;
               break;
            }
         }
         mp3.player.playMp3Folder(numero);
         mp3.player.volume(25);
         while (true){
            delay(100);
         }
      }      
	}
}