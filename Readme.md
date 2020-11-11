Ez a repository a Git egylet csapat munkáját tartalmazza.\

---

Csapattagok:\

	* Adorján András Bálint\
	* Kisszölgyémi Áron\
	* Nátz Kornél\

---

Leírás:\
\
A programban egy hős harcol egy vagy több szörny ellen. A játékmenetek és az elvért kimenetelek a scenarios mappában vannak letárolva. A karakterek tulajdonságai a gyökér mappában, json fájlokban vannak eltárolva. A program futtatásakor parancssori argumentumként a futtatni kívánt scenario nevét kell megadni. A harc addig tart amíg a hős meg nem hal, vagy le nem győzi az összes szörnyet. A harc után a játék felsorolja, hogy a hős kik ellen és milyen aktuális szinttel harcolt, majd a végső szintet, hp-t, dmg-t és acd-t.\
\
Fájlok:\
*	**Character.h**: Class meghatározása.\
*	**Character.cpp**: A játék levezényléséhez használt függvények definiálása.\
*	**main.cpp**: Objektumok létrehozása, függvények használata.\
\
Az adatok kezelésére a "character" osztályt használjuk.\
Egy character objektum paraméterei egy string, és két int.\
Az osztály tartalmazza az ezekhez szükséges settereket és függvényeket.\
\
Függvények:\
*	**attack**:\
		Alapvető támadás.\
		Ha a target HP-ja mínuszba menne át, azt nullára módosítja.\
		Használat: X.attack(Y), ha X a támadó fél, Y pedig a target.\
*	**isAlive**:\
		Megvizsgálja az objektum HP-ját, ha nagyobb mint 0, true értékkel tér vissza, azaz az objektum életben van.\
		Használat: X.isAlive()\
*	**parseUnit**
		Paraméterül kap egy json fájlt, amit megpróbál megnyitni,\
			ha sikertelen, akkor egy hibaüzenettel kilép,\
			ha pedig sikeres, return-öli a name, HP, és DMG-hez tartozó értékeket, külön változókban.\

---

Actions - Workflow:\
*	**Build the program**:\
		Az Actions-ben lévő workflow lefordítja a kódot g++ -std=c++17 *.cpp segítségével.\
*	**Run task2 shell script**:\
		Lefuttatja a bash shell script-ként megírt task2.sh nevezetű shell scriptet.\
		A shell script lekezeli hogy létezik-e már előző futtatás által keletkezett native_output.txt, avagy sem.\
		Ezután lefuttatja a programot a unit_test_* elnevezésű json fájlokban található bemenetekkel.\
		A kimeneteket ideiglenesen kiírja egy native_output.txt fájlba.\
*	**Compare native_output.txt with units\good_output.txt**:\
		Összehasonlítja a test által generált kimeneteket a good_output.txt-ben előre definiált kimenetekkel.\

---

GitHub Pages Dokumentáció: https:\\teaching-projects.github.io\SZE-MOSZE-2020-Git-egylet\index.html\

---

Readme is loading... Waiting for commits...\ 
