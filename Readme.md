Ez a repository a Git egylet csapat munkáját tartalmazza.  

---

Csapattagok:  

	* Adorján András Bálint  
	* Kisszölgyémi Áron  
	* Nátz Kornél  
	
---

Leírás:  
A programban 2 karakter harcol egymás ellen, ennek a két karakternek a nevét, életerejét és sebzését argumentumként kell átadni a játék indításakor (példa: Maple 150 10 Sally 45 30). A játék körönként kiírja a játék aktuális állását, egészen addig, amíg az egyik karakternek el nem fogy az életereje, ekkor a játék győztest hirdet.  
  
Fájlok:  
*	**Character.h**: Class meghatározása.  
*	**Character.cpp**: A játék levezényléséhez használt függvények definiálása.  
*	**main.cpp**: Objektumok létrehozása, függvények használata, a játék végeztével az objektumok törlése.  
  
Az adatok kezelésére a "character" osztályt használjuk.  
Egy character objektum paraméterei egy string, és két int.  
Az osztály tartalmazza az ezekhez szükséges settereket és függvényeket.  
  
Függvények:  
*	**attack**:  
		Kiírja, hogy ki támad kit, majd megvizsgálja, hogy a támadás során a target meghal-e.  
		Ha a target HP-ja mínuszba menne át, azt nullára módosítja.  
		Használat: X.attack(Y), ha X a támadó fél, Y pedig a target.  
*	**isAlive**:  
		Megvizsgálja az objektum HP-ját, ha nagyobb mint 0, true értékkel tér vissza, azaz az objektum életben van.  
		Használat: X.isAlive()  
