Debugovanie Raspberry Pi Pico
=============================

V tomto repozitári sa nachádzaju ukážkove projekty pre Visual Studio Code,
slajdy z prednášky a niektoré doplnkové súbory, ako konfigurácia debuggera pre
Raspberry Pi Picoprobe.

Obsah repozitára:

debugNative
-----------
Tento adresár obsahuje kópiu projektu založeného na CMake, ktorý je možné
utvoriť vo Visual Studio Code. Ak je vo VS Code prítomný plug-in CMake Tools,
buildovanie a debugovanie projektu je možné jednym klikom

debugPi
-------
V tomto adresári je jednoduchý projekt "blinky", ktorý je taktiež založený na
CMake. Zároveň obsahuje nastavenia pre plug-in "Cortex Debug" tak, aby VS Code
bolo schopné projekt debugovať za pomoci Picoprobe. O tom, čo je Picoprobe a
prečo je potrebné je možné dozvedieť v prezentácii.

99.picoprobe.rules
------------------
Konfiguračný súbor pre udev. Tento konfiguračný súbor sprístupní Picoprobe
neprivilegovanému používateľovi. Stačí ho nakopirovať do adresára
/etc/udev/rules.d a následne reštartovať počítač. Ak tento súbor nenakopírujete,
bude vám VS Code pri pokuse o štart debuggera vypisovať chybu s prístupovými
právami k USB zariadeniu a hlásiť, že Picoprobe nebolo nájdene, aj keď bude k
počítaču fyzicky pripojené.

debugging-pico.pdf
------------------
Slajdy z prezentácie.

launch.conf
-----------
Ukážkový konfiguračný súbor, ktorým sa nastaví plug-in "Cortex-Debug" tak, aby
debugging prebiehal pomocou Picoprobe. Je možné ho použiť pri zakladaní nového
projektu. Obsahuje komentáre, ktoré vysvetľuju význam jednotlivých volieb a
upozorňujú na miesta, ktoré je potrebné zmeniť.

picoprobe.uf2
-------------
Predkompilovaná verzia firmware-u Picoprobe. Odporúčam vždy si Picoprobe
kompilovať zo zdrojových kódov, keďže sa časom budu v kóde opravovať chyby a
pridávať nové vlastnosti. Predkompilovanú verziu zverejňujem len ako rýchlu
pomoc pre zjednodušenie práce.

