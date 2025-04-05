Lupta contra Grigore - README
Descriere
Acest joc RPG simplu "Lupta contra Grigore" te pune în rolul unui Erou care se luptă cu un Dragon. Jocul implementează un sistem de inventar pentru erou, care poate adăuga arme și armuri. Eroul și dragonul își dau atacuri reciproce până când unul dintre ei este învins.

Cerințe
  C++11 sau mai recent (pentru utilizarea funcțiilor moderne C++ cum ar fi std::uniform_int_distribution și std::this_thread::sleep_for).
  Biblioteca assert este folosită pentru a verifica anumite condiții în timpul execuției jocului.

Funcționalități
  Crearea unui personaj Erou și a unui Dragon cu nume și puncte de viață.
  Inventar: fiecare personaj are un inventar în care își poate adăuga arme și armuri.
  Atac și apărare: fiecare personaj poate ataca și poate primi daune în funcție de armele și armurile pe care le are.
  Generare aleatorie de arme și armuri.
  Testarea acțiunilor personajelor folosind assert pentru a verifica corectitudinea.
  În final, eroul și dragonul se confruntă într-o luptă până când unul dintre ei moare.

Cum funcționează
  Clasele utilizate
    Character: reprezintă un personaj (erou sau dragon). Conține informații despre numele, viața și inventarul personajului.
    Weapon: reprezintă o armă, care are un nume și o valoare de daune.
    Armor: reprezintă o armură, care are un nume și o valoare de apărare.
    Inventory: gestionază colecțiile de arme și armuri pentru un personaj.

  Pașii jocului
    Crearea personajului: Jucătorul introduce numele eroului, iar un dragon este creat automat.
    Arme și armuri: Ambele personaje primesc un arsenal de arme și armuri la început, iar pe parcurs armele și armurile pot fi generate aleatoriu.
    Lupta: Eroul și dragonul se atacă alternativ până când unul dintre ei moare. Dacă eroul sau dragonul își scade viața la zero, lupta se termină.
    Testarea: Codul conține testări automate pentru a verifica dacă jocul funcționează corect.
    Finalul jocului: La sfârșit, se anunță cine a câștigat.

  Fluxul de joc
    La început, programul te va întreba să introduci numele eroului.
    După ce ambele personaje sunt create, se va afișa starea lor inițială.
    Eroul și Dragonul vor începe lupta prin atacuri alternative.
    După fiecare atac, se va actualiza starea de sănătate a personajelor.
    Jocul se termină când unul dintre personaje ajunge la sănătatea 0.
    La final, va fi afișat cine a câștigat.

Cerințe de utilizare
  Compilează și rulează programul folosind un compilator C++ (de ex. g++) folosind comanda:
      g++ -Iinclude src/*.cpp -o rpg_game && ./rpg_game
  La pornire, te va întreba să introduci numele eroului.
  După ce începe lupta, te vei uita la atacuri și daune în timp real, cu o pauză între fiecare runda de atac (aproximativ 2 secunde).
  La final, îți va spune cine a câștigat lupta și te va încuraja să continui.

Explicație cod
  Armele și armurile sunt generare aleatoriu folosind funcțiile generateRandomWeapon și generateRandomArmor.
  Funcțiile de atac și apărare calculează daunele pe baza armelor și armurilor din inventar.
  Testele de validare sunt incluse pentru a verifica corectitudinea programului (de exemplu, asigurarea că viața personajului eroului rămâne constantă după atacuri).
  Programul este interactiv, și odată ce începe, îți va arăta în timp real cum se desfășoară lupta.

Considerații și extensii posibile
  Se pot adăuga noi clase pentru a crea personaje mai complexe (ex: Căpcăun, Magician etc.).
  Mecanisme mai complexe de combatere, de exemplu, cu abilități speciale pentru fiecare personaj.
  Suport pentru mai mulți jucători.
  Integrarea unei interfețe grafice sau a unui sistem de salvare a progresului.