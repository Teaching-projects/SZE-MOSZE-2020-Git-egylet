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

---

Osztályok:<br />

*	**Hero**: Hero típusú karakter objektumait és függvényeit tartalmazó osztály.<br />
*	**Monster**: Monster típusú karakter objektumait és függvényeit tartalmazó osztály.<br />
*	**JSON**: A .json kiterjesztésű fájlokban tárolt adatok beolvasásáért felelős osztály.<br />

Az osztályok és függvényeik működéséről részletesebb információk a doxygen segítségével létrehozott GitHub Pages dokumentációnkban érhetőek el: https://teaching-projects.github.io/SZE-MOSZE-2020-Git-egylet/index.html<br />

---

Actions - Workflows:<br />
*	**Unit tests**: A google tesztek futtatásáért és ellenőrzéséért felelős workflow.<br />
*	**pushdocs workflow**: A doxygen-es GitHub Pages dokumentáció létrehozásáért felelős workflow.<br />
*	**build, static code analysis, leakcheck**: A kód szintaktikáját és helyes futását ellenőrző workflow.<br />

---

Readme is up to date to task "Defense (#20)". Waiting for commits...<br /> 
