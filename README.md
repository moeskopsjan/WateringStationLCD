# WateringStationLCD

Kurt Beheydt maakte in december 2018 voor TeamScheire een WateringStation.  De Arduinocode hiervoor is beschikbaar via https://github.com/TeamScheire/WateringStation
![WateringStation](https://github.com/TeamScheire/WateringStation/blob/master/footage/setup.jpg)

In deze versie voegen we een LCD toe aan het Arduinoscript.  Op deze manier kan een plantje via een LCD laten weten of hij water nodig heeft. (jawel, een communicerend plantje :thinking: :shushing_face:)
* Met BewateringSysteemLCD.ino gebruik je een standaard LCD1602  (ook bruikbaar in TinkerCAD)
* Met BewateringSysteemLCD-I2C.ino gebruik je een LCD1602 met I2C-module

## Aansluiting
Voor de aansluiting van de sensor en de servo verwijzen we naar :https://github.com/TeamScheire/WateringStation
De LCD1602 met I2C module is aangesloten op de I2C bus:
* SCL op Analog 5
* SDA op Analog 4

De mini servo is aangesloten op pin 9

## Simulatie
Een simulatie van deze opstelling, is (tijdelijk) beschikbaar via TinkerCAD: https://www.tinkercad.com/things/gIHjTOaBoHo-bewateringsysteemlcd/editel?sharecode=pFCqASstcvZtVCAVlApf_UrIONwlHltKVOnXcW-kE4I

Een afbeelding in TinkerCAD:
![Bewateringsysteem](https://github.com/moeskopsjan/WateringStationLCD/blob/main/BewateringSimulatieTinkerCAD.JPG)
Een moisture sensor is niet beschikbaar in Arduino, maar het wordt ook aangesloten op een analoge ingang.  In deze simulatie hebben we een potmeter aangesloten om de moisture sensor na te bootsen.
De waarden kunnen aangepast worden.  Zie [BewateringSysteemLCD.ino](https://github.com/moeskopsjan/WateringStationLCD/blob/main/BewateringSysteemLCD.ino)


Have FUN!
