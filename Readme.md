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

*	**[main.cpp](main.cpp)**: @hegyhati által megadott, a játék egészét levezénylő fájl.<br />
*	**[Hero.h](Hero.h)**: Hero osztály header fájlja.<br />
*	**[Hero.cpp](Hero.cpp)**: Hero osztály elemeinek és függvényeinek leírását tartalmazó fájl.<br />
*	**[JSON.h](JSON.h)**: JSON osztály header fájlja.<br />
*	**[JSON.cpp](JSON.cpp)**: JSON osztály elemeinek és függvényeinek leírását tartalmazó fájl.<br />
*	**[Monster.h](Monster.h)**: Monster osztály header fájlja.<br />
*	**[Monster.cpp](Monster.cpp)**: Monster osztály elemeinek és függvényeinek leírását tartalmazó fájl.<br />
*	**[Map.h](Map.h)**: Map osztály header fájlja. Az osztály konstruktorát, függvények deklarációit és egy exception függvényt tartalmaz.<br />
*	**[Map.cpp](Map.cpp)**: Map osztály elemeinek és függvényeinek leírását tartalmazó fájl. A pálya beolvasásáért és kezeléséért felel.<br />
*	**[Damage.h](Damage.h)**: Damage osztály header fájlja.<br />
*	**[Damage.cpp](Damage.cpp)**: Damage osztály elemeinek és függvényeinek leírását tartalmazó fájl.<br />
*	**[Game.h](Game.h)**: Game osztály header fájlja.<br />
*	**[Game.cpp](Game.cpp)**: Game osztály elemeinek és függvényeinek leírását tartalmazó fájl.<br />
*	**[Readme.md](Readme.md)**: Github oldal által megjelenített dokumentációt tartalmazó fájl.<br />
*	**[Report.md](Report.md)**: A félév során elvégzett feladatokról és a teljes munkákról készült jelentés.<br />
*	**[doxconf](doxconf)**: Doxygen dokumentáció létrehozásához szükséges konfigurációs fájl.<br />
*	**[Blood_Raven.json](Blood_Raven.json)**: @hegyhati által megadott karakter tulajdonságait tartalmazó fájl.<br />
*	**[Dark_Wanderer.json](Dark_Wanderer.json)**: @hegyhati által megadott karakter tulajdonságait tartalmazó fájl.<br />
*	**[Fallen.json](Fallen.json)**: @hegyhati által megadott karakter tulajdonságait tartalmazó fájl.<br />
*	**[Zombie.json](Zombie.json)**: @hegyhati által megadott karakter tulajdonságait tartalmazó fájl.<br />
*	**[Makefile](Makefile)**: A make parancsok kiadásához szükséges fájl.<br />
*	**[Newtest.yml](.github/workflows/Newtest.yml)**: A "Unit tests" nevű workflow futtatási fájlja.<br />
*	**[pushdocs.yml](.github/workflows/pushdocs.yml)**: A "pushdocs workflow" nevű workflow futtatási fájlja.<br />
*	**[Test.yml](.github/workflows/Test.yml)**: A "build, static code analysis, leakcheck" nevű workflow futtatási fájlja.<br />
*	**[dox_docker](docker/dox_docker)**: Docker container létrehozásához szükséges fájl.<br />
*	**[sca_docker](docker/sca_docker)**: Docker container létrehozásához szükséges fájl.<br />
*	**[unittest_docker](docker/unittest_docker)**: Docker container létrehozásához szükséges fájl.<br />
*	**[output1.txt](scenarios/output1.txt)**: @hegyhati által megadott elvárt kimenetet tartalmazó fájl.<br />
*	**[output2.txt](scenarios/output2.txt)**: @hegyhati által megadott elvárt kimenetet tartalmazó fájl.<br />
*	**[scenario1.json](scenarios/scenario1.json)**: @hegyhati által megadott játékmenetet tartalmazó fájl.<br />
*	**[scenario2.json](scenarios/scenario2.json)**: @hegyhati által megadott játékmenetet tartalmazó fájl.<br />
*	**[CMakeLists.txt](tests/CMakeLists.txt)**: A "Unit tests" nevű workflow segédfájlja. A tesztek helyes lefutásának ellenőrzéséhez szükséges.<br />
*	**[errorcheck.sh](tests/errorcheck.sh)**: A "build, static code analysis, leakcheck" nevű workflow segédfájlja. Az errorok ellenőrzéséhez szükséges.<br />
*	**[task4_inout.sh](tests/task4_inout.sh)**: A "build, static code analysis, leakcheck" nevű workflow segédfájlja. A játék kimenetének ellenőrzéséhez szükséges.<br />
*	**[unit_tests.cpp](tests/unit_tests.cpp)**: A "Unit tests" nevű workflow segédfájlja. Ez tartalmazza a konkrét google teszteket.<br />
*	**[warningcheck.sh](tests/warningcheck.sh)**: A "build, static code analysis, leakcheck" nevű workflow segédfájlja. A warningok ellenőrzéséhez szükséges.<br />
*	**[good_output.txt](units/good_output.txt)**: Csapatunk által kitalált 3 karakter egymás elleni harcainak elvárt kimenetét tartalmazó fájl.<br />
*	**[Player_1_Kakarott.json](units/Player_1_Kakarott.json)**: Csapatunk által kitalált karakter tulajdonságait tartalmazó fájl.<br />
*	**[Player_2_Sally.json](units/Player_2_Sally.json)**: Csapatunk által kitalált karakter tulajdonságait tartalmazó fájl.<br />
*	**[Player_3_Maple.json](units/Player_3_Maple.json)**: Csapatunk által kitalált karakter tulajdonságait tartalmazó fájl.<br />
*	**[Player_4_Enigma.json](units/error/Player_4_Enigma.json)**: Csapatunk által kitalált karakter tulajdonságait tartalmazó fájl, tartalma direkt nem helyes.<br />
*	**[NCPlayer_1_Mixi.json](units/not_correct_units/NCPlayer_1_Mixi.json)**: Csapatunk által kitalált karakter tulajdonságait tartalmazó fájl, amiben az adatok sorrendje fel van cserélve.<br />
*	**[NCPlayer_2_Spacy.json](units/not_correct_units/NCPlayer_2_Spacy.json)**: Csapatunk által kitalált karakter tulajdonságait tartalmazó fájl, amelyben felesleges whitespacek találhatóak.<br />
*	**[NCPlayer_3_Mixpacy.json](units/not_correct_units/NCPlayer_3_Mixpacy.json)**: Csapatunk által kitalált karakter tulajdonságait tartalmazó fájl, amiben az adatok sorrendje fel van cserélve és emellett felesleges whitespacek is találhatóak benne.<br />
*	**[level1.txt](maps/level1.txt)**: @hegyhati által megadott példa map-ot tartalmazza.<br />

---

Osztályok:<br />

*	**Damage**: Monster típusú karakter Damage objektumát és a hozzá tartozó függvényeket és operátorokat tartalmazó osztály.<br />
*	**Game**: A játék levezényléséért felelős osztály.<br />
*	**Hero**: Hero típusú karakter objektumait és függvényeit tartalmazó osztály.<br />
*	**JSON**: A .json kiterjesztésű fájlokban tárolt adatok beolvasásáért felelős osztály.<br />
*	**Map**: A maps/ directory-n belül található map-ok beolvasásáért és kezeléséért felelős osztály.<br />
*	**Monster**: Monster típusú karakter objektumait és függvényeit tartalmazó osztály.<br />

Az osztályok és függvényeik működéséről részletesebb információk a doxygen segítségével létrehozott GitHub Pages dokumentációnkban érhetőek el: https://teaching-projects.github.io/SZE-MOSZE-2020-Git-egylet/index.html<br />

---

Actions - Workflows:<br />
*	**Unit tests**: A google tesztek futtatásáért és ellenőrzéséért felelős workflow.<br />
*	**pushdocs workflow**: A doxygen-es GitHub Pages dokumentáció létrehozásáért felelős workflow.<br />
*	**build, static code analysis, leakcheck**: A kód szintaktikáját és helyes futását ellenőrző workflow.<br />

---

A félév során elvégzett feladatokról és a teljes munkákról készült jelentés a [Report.md](Report.md) fájlban olvasható. <br /> 
