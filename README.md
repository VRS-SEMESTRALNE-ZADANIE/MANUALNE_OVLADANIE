# OVLÁDANIE AUTÍČKA

Tento projekt umožňuje ovládanie modelu autíčka pomocou joysticku, ktorý je priamo napojený na mikrokontrolér STM32. Pôvodne bola zamýšľaná komunikácia cez RFM moduly s využitím SPI protokolu, avšak tento prístup bol nakoniec zjednodušený. Výsledný systém priamo prenáša signály z joysticku do mikrokontroléra pomocou káblov a ovláda rýchlosť a smer pohybu autíčka cez riadiacu dosku MD25, ktorá ovláda motory. Taktiež sme doimplementovali ovládanie pomocou tlaćítok.

## Funkčnosť

### Popis zapojenia
Joystick bol napojený priamo na STM32 cez analógové vstupy, kde bol jeho signál spracovaný cez prevodník ADC . Signál z joysticku špecifikuje dve osy:
- **X-os**: Rýchlosť a smer pohybu autíčka dopredu alebo dozadu.
- **Y-os**: Otáčanie autíčka doľava alebo doprava.

Joystick bol napojený priamo na STM32 cez analógové vstupy, kde bol jeho signál spracovaný cez prevodník ADC . Signál z joysticku špecifikuje dve osy:
- **X-os**: Rýchlosť a smer pohybu autíčka dopredu alebo dozadu.
- **Y-os**: Otáčanie autíčka doľava alebo doprava.

Prevodník ADC konvertuje analógové hodnoty z joysticku na digitálne signály, ktoré sa následne posielajú do druhého STM32 mikrokontroléra nachádzajúceho sa na autíčku. Tento STM32 prijíma tieto hodnoty cez káblové prepojenie a cez protokol USART odosiela príkazy do riadiacej dosky MD25.

Riadiaca doska MD25 je priamo pripojená na motory autíčka a interpretuje príkazy od mikrokontroléra. Na základe prijatých hodnôt nastavuje:
- **Rýchlosť motorov**: Pohyb dopredu alebo dozadu.
- **Diferenciálne riadenie**: Otáčanie autíčka podľa rozdielnej rýchlosti ľavého a pravého motora.

### Ovládanie cez tlačidlá
Okrem ovládania joystickom sme implementovali aj ovládanie cez štyri tlačidlá, ktoré boli napojené na STM32 cez digitálne vstupy. Každé tlačidlo vykonáva jednu zo špecifických funkcií:
- **Tlačidlo 1**: Pohyb dopredu.
- **Tlačidlo 2**: Pohyb dozadu.
- **Tlačidlo 3**: Otáčanie doľava.
- **Tlačidlo 4**: Otáčanie doprava.

STM32 pri stlačení tlačidla deteguje zmenu stavu a následne vygeneruje príslušný príkaz, ktorý sa cez USART protokol odosiela do dosky MD25 na ovládanie motorov. Medzi ovládaním cez joystick a tlačídlami sa dá prepínať stlačením joysticku.

### Detailný priebeh spracovania signálov
1. **Joystick a ADC spracovanie:**
   - Pri pohybe joysticku sa mení jeho napätie na osiach X a Y.
   - ADC v STM32 tieto analógové signály konvertuje na digitálne hodnoty (0 – 1024).
   - Tieto hodnoty určujú smer a intenzitu pohybu.

2. **Prenos signálov do STM na autíčku:**
   - Digitálne hodnoty sa cez káble posielajú do STM32 na autíčku.
   - Mikrokontrolér ich interpretuje a cez USART protokol odosiela príkazy do dosky MD25.

3. **MD25 a motory:**
   - MD25 riadi rýchlosť a smery motorov na základe prijatých príkazov, tým že priamo do ovládacích registorv nahrávame konkrétne hodnoty.
   - Motory sa pohybujú synchronizovane alebo diferencovane v závislosti od hodnôt príkazov.

4. **Pohyb autíčka:**
   - Rýchlosť pohybu je riadená zmenou PWM signálu na doske MD25.
   - Diferenciálne ovládanie zabezpečuje otáčanie podľa rozdielu medzi rýchlosťou ľavého a pravého motora.


