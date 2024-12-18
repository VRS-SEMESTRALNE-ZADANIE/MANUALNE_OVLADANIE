OVLADANIE-AUTICKA
Ovládanie autíčka pomocou joysticku cez RFM bezdrôtovú komunikáciu

Popis

Tento projekt umožňuje ovládanie modelu autíčka pomocou joysticku, pričom komunikácia medzi joystickom a autíčkom prebieha bezdrôtovo cez moduly RFM . Projekt využíva mikrokontroléry pre implementáciu oboch častí systému – ovládania (joystick) a prijímača (autíčko).

Požiadavky

• Hardvér:

o 2x mikrokontrolér (STM32F303K8)

o 2x RFM modul (prístupný v škole)

o Joystick modul (4 tlačítka)

o Model autíčka s motormi a ovládacími obvodmi (model prístupný v škole alebo vytvoriť vlastný???)

Ďalšie body závisia od odpovede na bod 4:

o Napájanie pre mikrokontrolér a motory(batéria)

o Konektory, vodiče a potenciálne ďalšie komponenty podľa potreby

o Návrh diferenciálneho podvozku

Funkčnosť

• Ovládač (joystick) odosiela cez RFM modul údaje o pohybe joysticku a stlačení tlačidla.

• Autíčko (prijímač) prijíma tieto údaje cez druhý RFM modul a interpretuje ich, aby ovládalo pohyb motorov.

o Pohyb na osi X joysticku riadi rýchlosť a smer pohybu autíčka vpred a vzad.

o Pohyb na osi Y joysticku riadi otáčanie autíčka vľavo alebo vpravo.

Rozdelenie práce:

Tím : Žolo(Zoltán Sármány), Matúš (Matúš Tetliak), Džihi(Samuel Mihálik), Kubo (Jakub Tinák)

Konfigurácia pinov/ prehľadávanie registrov: Žolo

Logika pohybu: Matúš

Logika RFM komunikácie/práca s gitom :Džihi

Zapájanie hardwaru/vyhľadávanie informácií: Kubo
