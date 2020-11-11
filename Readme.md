Ez a repository a Git egylet csapat munkáját tartalmazza.<br />

---

Csapattagok:<br />

	* Adorján András Bálint
	* Kisszölgyémi Áron
	* Nátz Kornél

---

Leírás:<br />
<br />
A programban egy hős harcol egy vagy több szörny ellen. A játékmenetek és az elvért kimenetelek a scenarios mappában vannak letárolva. A karakterek tulajdonságai a gyökér mappában, json fájlokban vannak eltárolva. A program futtatásakor parancssori argumentumként a futtatni kívánt scenario nevét kell megadni. A harc addig tart amíg a hős meg nem hal, vagy le nem győzi az összes szörnyet. A harc után a játék felsorolja, hogy a hős kik ellen és milyen aktuális szinttel harcolt, majd a végső szintet, hp-t, dmg-t és acd-t.<br />
<br />
Fájlok:<br />
*	**Character.h**: Class meghatározása.<br />
*	**Character.cpp**: A játék levezényléséhez használt függvények definiálása.<br />
*	**main.cpp**: Objektumok létrehozása, függvények használata.<br />
<br />
Az adatok kezelésére a "character" osztályt használjuk.<br />
Egy character objektum paraméterei egy string, és két int.<br />
Az osztály tartalmazza az ezekhez szükséges settereket és függvényeket.<br />
<br />
Függvények:<br />
*	**attack**:  
		Alapvető támadás.<br />
		Ha a target HP-ja mínuszba menne át, azt nullára módosítja.<br />
		Használat: X.attack(Y), ha X a támadó fél, Y pedig a target.<br />
*	**isAlive**:<br />
		Megvizsgálja az objektum HP-ját, ha nagyobb mint 0, true értékkel tér vissza, azaz az objektum életben van.<br />
		Használat: X.isAlive()<br />
*	**parseUnit**
		Paraméterül kap egy json fájlt, amit megpróbál megnyitni,<br />
			ha sikertelen, akkor egy hibaüzenettel kilép,<br />
			ha pedig sikeres, return-öli a name, HP, és DMG-hez tartozó értékeket, külön változókban.<br />

---

Actions - Workflow:<br />
*	**Build the program**:<br />
		Az Actions-ben lévő workflow lefordítja a kódot g++ -std=c++17 *.cpp segítségével.<br />
*	**Run task2 shell script**:<br />
		Lefuttatja a bash shell script-ként megírt task2.sh nevezetű shell scriptet.<br />
		A shell script lekezeli hogy létezik-e már előző futtatás által keletkezett native_output.txt, avagy sem.<br />
		Ezután lefuttatja a programot a unit_test_* elnevezésű json fájlokban található bemenetekkel.<br />
		A kimeneteket ideiglenesen kiírja egy native_output.txt fájlba.<br />
*	**Compare native_output.txt with units good_output.txt**:<br />
		Összehasonlítja a test által generált kimeneteket a good_output.txt-ben előre definiált kimenetekkel.<br />

---

GitHub Pages Dokumentáció: https://teaching-projects.github.io/SZE-MOSZE-2020-Git-egylet/index.html<br />

---

Readme is loading... Waiting for commits...<br /> 
