Ez a repository a Git egylet csapat munkáját tartalmazza.<br />

---

Csapattagok:<br />

	* Adorján András Bálint
	* Kisszölgyémi Áron
	* Nátz Kornél

---

Leírás:<br />
<br />
A programban egy hős harcol egy vagy több szörny ellen. A játékmenetek és az elvárt kimenetelek a scenarios mappában vannak letárolva. A karakterek tulajdonságai a gyökér mappában, json fájlokban vannak eltárolva. A program futtatásakor parancssori argumentumként a futtatni kívánt scenario nevét kell megadni. A harc addig tart amíg a hős meg nem hal, vagy le nem győzi az összes szörnyet. A harc után a játék felsorolja, hogy a hős kik ellen és milyen aktuális szinttel harcolt, majd a végső szintet, hp-t, dmg-t és acd-t.<br />

---

Fájlok:<br />

*	**main.cpp**: @hegyhati által megadott, a játék egészét levezénylő fájl.<br />
*	**Hero.h**: Hero osztály header fájlja.<br />
*	**Hero.cpp**: Hero osztály elemeinek és függvényeinek leírását tartalmazó fájl.<br />
*	**JSON.h**: JSON osztály header fájlja.<br />
*	**JSON.cpp**: JSON osztály elemeinek és függvényeinek leírását tartalmazó fájl.<br />
*	**Monster.h**: Monster osztály header fájlja.<br />
*	**Monster.cpp**: Monster osztály elemeinek és függvényeinek leírását tartalmazó fájl.<br />
*	**Readme.md**: Github oldal által megjelenített dokumentációt tartalmazó fájl.<br />
*	**Blood_Raven.json**: @hegyhati által megadott karakter tulajdonságait tartalmazó fájl.<br />
*	**Dark_Wanderer.json**: @hegyhati által megadott karakter tulajdonságait tartalmazó fájl.<br />
*	**Fallen.json**: @hegyhati által megadott karakter tulajdonságait tartalmazó fájl.<br />
*	**Zombie.json**: @hegyhati által megadott karakter tulajdonságait tartalmazó fájl.<br />
*	**Makefile**: A make parancsok kiadásához szükséges fájl.<br />
*	**.github/workflows/Newtest.yml**: A "Unit tests" nevű workflow futtatási fájlja.<br />
*	**.github/workflows/pushdocs.yml**: A "pushdocs workflow" nevű workflow futtatási fájlja.<br />
*	**.github/workflows/Test.yml**: A "build, static code analysis, leakcheck" nevű workflow futtatási fájlja.<br />
*	**docker/dox_docker**: Docker container létrehozásához szükséges fájl.<br />
*	**docker/sca_docker**: Docker container létrehozásához szükséges fájl.<br />
*	**docker/unittest_docker**: Docker container létrehozásához szükséges fájl.<br />
*	**scenarios/output1.txt**: @hegyhati által megadott elvárt kimenetet tartalmazó fájl.<br />
*	**scenarios/output2.txt**: @hegyhati által megadott elvárt kimenetet tartalmazó fájl.<br />
*	**scenarios/scenario1.json**: @hegyhati által megadott játékmenetet tartalmazó fájl.<br />
*	**scenarios/scenario2.json**: @hegyhati által megadott játékmenetet tartalmazó fájl.<br />
*	**tests/CMakeLists.txt**: A "Unit tests" nevű workflow segédfájlja. A tesztek helyes lefutásának ellenőrzéséhez szükséges.<br />
*	**tests/errorcheck.sh**: A "build, static code analysis, leakcheck" nevű workflow segédfájlja. Az errorok ellenőrzéséhez szükséges.<br />
*	**tests/task4_inout.sh**: A "build, static code analysis, leakcheck" nevű workflow segédfájlja. A játék kimenetének ellenőrzéséhez szükséges.<br />
*	**tests/unit_tests.cpp**: A "Unit tests" nevű workflow segédfájlja. Ez tartalmazza a konkrét google teszteket.<br />
*	**tests/warningcheck.sh**: A "build, static code analysis, leakcheck" nevű workflow segédfájlja. A warningok ellenőrzéséhez szükséges.<br />
*	**units/good_output.txt**: Csapatunk által kitalált 3 karakter egymás elleni harcainak elvárt kimenetét tartalmazó fájl.<br />
*	**units/Player_1_Kakarott.json**: Csapatunk által kitalált karakter tulajdonságait tartalmazó fájl.<br />
*	**units/Player_2_Sally.json**: Csapatunk által kitalált karakter tulajdonságait tartalmazó fájl.<br />
*	**units/Player_3_Maple.json**: Csapatunk által kitalált karakter tulajdonságait tartalmazó fájl.<br />
*	**units/error/Player_4_Enigma.json**: Csapatunk által kitalált karakter tulajdonságait tartalmazó fájl, tartalma direkt nem helyes.<br />
*	**units/not_correct_units/NCPlayer_1_Mixi.json**: Csapatunk által kitalált karakter tulajdonságait tartalmazó fájl, amiben az adatok sorrendje fel van cserélve.<br />
*	**units/not_correct_units/NCPlayer_2_Spacy.json**: Csapatunk által kitalált karakter tulajdonságait tartalmazó fájl, amelyben felesleges whitespacek találhatóak.<br />
*	**units/not_correct_units/NCPlayer_3_Mixpacy.json**: Csapatunk által kitalált karakter tulajdonságait tartalmazó fájl, amiben az adatok sorrendje fel van cserélve és emellett felesleges whitespacek is találhatóak benne.<br />
<br />

---

Osztályok:<br />

*	**Hero**: Leírás.<br />
*	**Monster**: Leírás.<br />
*	**JSON**: Leírás.<br />


<br />
!!!Jelzősor!!!<br />
<br />


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
