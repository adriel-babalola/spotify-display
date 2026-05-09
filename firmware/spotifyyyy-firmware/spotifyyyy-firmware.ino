#include <Arduino.h>
#include <ArduinoJson.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <WiFi.h>  
#include <SpotifyEsp32.h>
#include <SPI.h>

#define TFT_CS 1
#define TFT_RST 2
#define TFT_DC 3
#define TFT_SCLK 4
#define TFT_MOSI 5

char* SSID = "Infinx Note 8";
char* PASSWORD = "somethingByMeWinkWink";
const char* CLIENT_ID = "myId"; 
const char* CLIENT_SECRET = "mySecret";

String lastArtist = "";
String lastTrackname = ""; 

Spotify sp(CLIENT_ID, CLIENT_SECRET);
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST); 

void setup() {
  Serial.begin(115200);

  tft.initR(INITR_BLACKTAB);
  tft.setRotation(1); 
  Serial.print("TFT Initialized!");
  tft.fillScreen(ST77XX_BLACK); 

  WiFi.begin(SSID, PASSWORD);
  Serial.print("Connecting to Wifi...");
  while(WiFi.status() != WL_CONNECTED)  
    delay(1000);
    Serial.print("."); 
  }
  Serial.printf("\nConnected\n"); 
  
  tft.setCursor(0,0); 
  tft.write(WiFi.localIP().toString().c_str()); 

  sp.begin();
  while(!sp.is_auth())
  {
    sp.handle_client();
    delay(1500);
  }
  Serial.println("Connected to Spotify!"); 
}

void loop() { 
  String currentArtist = sp.current_artist_names();
  String currentTrackname = sp.current_track_name();

  if (lastArtist != currentArtist && currentArtist != "Something went wrong" && !currentArtist.isEmpty()) {
     tft.fillScreen(ST77XX_BLACK);
     lastArtist = currentArtist;
     Serial.println("Artist: " + lastArtist);
     tft.write(lastArtist.c_str());
  }

  if (lastTrackname != currentTrackname && currentTrackname != "Something went wrong" && currentTrackname != "null") {
    lastTrackname = currentTrackname;
    Serial.println("Track: " + lastTrackname);
    tft.setCursor(10, 40); 
    tft.write(lastTrackname.c_str());
  }
  delay(2000); 
}
