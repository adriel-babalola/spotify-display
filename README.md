# Spotifyyyyyyyyy 🎵

my version of the spotify display starter project — shows whats currently playing and lets me skip/play songs with actual keyboard switches. also threw in a buzzer for button feedback cause why not.

## Why i made this

i hate picking up my phone just to skip a song while im working or studying. wanted something that just sits on my desk, shows me whats playing, and lets me control it without touching my phone. also i wanted to finally learn how WiFi on a microcontroller works and this was the perfect excuse for that.

## How it works

- **ESP32-C3** connects to WiFi and talks to the Spotify API
- **1.8" ST7735 TFT display** shows the current track and artist
- **Gateron keyboard switches** to skip, go back, and play/pause
- **Passive buzzer** clicks whenever you press a button
- everything sits in a **3D printed case** from JLCPCB

## Screenshots
Wiring diagram using KICAD

![alt text](image-3.png)

![alt text](<Screenshot 2026-05-16 032715.png>)

![alt text](<Screenshot 2026-05-16 025709.png>)

![alt text](<Screenshot 2026-05-16 032914.png>)

![alt text](<Screenshot 2026-05-16 032938.png>)

![alt text](<Screenshot 2026-05-16 032950.png>)

## BOM
| Item # | Name | Purpose | Qty | Total (USD) | Source | Link |
|--------|------|---------|-----|-------------|--------|------|
| 1 | Wires | To make connections | 5 | $2.20 | AliExpress | [link](https://www.aliexpress.com) |
| 2 | WS2812B LED Ring | Underglow lighting for the case | 1 | $2.78 | AliExpress | [link](https://www.aliexpress.com/item/1005007206094421.html) |
| 3 | Key Caps | For the switches | 3 | $2.50 | AliExpress | [link](https://www.aliexpress.com/item/1005008827240220.html) |
| 4 | 3D Printing Case | To hold the display | 1 | $11.00 | #printing-legion | - |
| 5 | Cherry MX Switches | To switch between songs | 3 | $2.91 | AliExpress | [link](https://www.aliexpress.com/item/1005003629759439.html) |
| 6 | Wemos ESP32-C3 Development Board | MCU | 1 | $4.79 | AliExpress | [link](https://www.aliexpress.com/item/1005012043829146.html) |
| 7 | 1.8" TFT LCD Display Module ST7735S 3.3V | The display unit | 1 | $3.27 | AliExpress | [link](https://www.aliexpress.com/item/1005008042359126.html) 
| | | | | **TOTAL: $29.45** | | |