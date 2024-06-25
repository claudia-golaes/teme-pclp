# Text Highlight

Chiar dacă scrierea codului poate părea câteodată o acțiune uşoară, aceasta implică multe cunoştințe teoretice cât şi foarte multă practică, mai ales în scrierea de programe complexe. Astfel, pentru a veni în ajutorul utilizatorilor, s-a creat highlighting-ul pe text, ceea ce înseamnă că vor exista cuvinte cheie precum "for", "while", "int", "float" care vor fi scoase în evidență pentru o înțelegere mai uşoară a codului. În această problemă ne propunem să simulăm facilitatea de TextHighlight.

Pentru a putea simula highlighting-ul pe text, vom “sublinia” keyword-urile întâlnite pe linia următoare. Sublinierea unui keyword se va face folosind caracterul `_` (underline) pentru fiecare caracter al cuvântului respectiv (incluzând spațiile în cazul keyword-urilor formate din mai multe cuvinte), iar pentru restul caracterelor care nu fac parte din cuvintele cheie se va folosi ` ` (spațiu). 

**Atenţie!** Deoarece multe programe permit scrierea de secvențe cheie formate din mai multe cuvinte cu un număr variabil de spații între ele, pentru problema noastră va fi luat în calcul şi acest caz! Evitați, totuși, să scrieți cod în acest fel, deoarece devine greu de înțeles si trebuie respectat un coding style.

Pentru această temă vom considera drept cuvinte cheie (keywords) doar următoarele cuvinte şi secvenţe de două cuvinte: `first of`, `for`, `for each`, `from`, `in`, `is`, `is a`, `list of`, `unit`, `or`, `while`, `int`, `float`, `double`, `string`.

---

# Autocomplete

Autocomplete-ul este o funcționalitate des folosită. Deși aceasta ajută în teorie la economisirea timpului, poate genera și greșeli, depinzând de modul în care este folosită. Cu timpul, mare parte dintre probleme au fost rezolvate și autocomplete-ul ajută aproape în fiecare caz, printre cele mai utile și folosite fiind autocomplete-ul căutării pe Google. Acest autocomplete este totuși destul de complex, folosind atât căutările precedente ale utilizatorului curent, a celorlalți utilizatori, keyword-urile paginilor existente pe Google, cât și cele mai populare căutări.

Astfel, în această problemă ne propunem să implementăm un autocomplete care pornește de la un anumit număr de cuvinte (un mini-dicționar) și care se actualizează odată cu introducerea unor cuvinte noi sau folosirea celor recente. Fiecare cuvânt din dicționar va avea la început prioritatea 0 și va fi reprezentat sub forma aceasta:

```c
struct dictionary_entry {
    char* word;
    int priority;
};
```

Fiecare cuvânt scris de utilizator poate fi încadrat în una dintre următoarele 3 categorii:

- **cuvânt** - nu există nicio potrivire în dicționar, deci va fi reprodus în output exact cum a fost introdus și va fi adăugat cu prioritatea 1 în dicționar, deoarece este prima sa apariție în text.

- **cuvânt\*** - se potrivește cu un cuvânt din dicționar care are o prioritate mai mare, dar utilizatorul dorește să utilizeze forma sa proprie, deși are o prioritate mai mică (cuvântul poate sau nu exista în dicționar, în acest caz va fi adăugat). Va fi afișat cuvântul și îi va crește prioritatea.

- **cuv** - se potrivește cu unul sau mai multe cuvinte din dicționar (care încep cu cuv) și se va selecta cel care are cea mai mare prioritate. De asemenea, prioritatea cuvântului selectat din dicționar va crește.

**Observație:** În cazul în care există cuvinte în dicționar cu aceeași prioritate și se caută o potrivire pentru un cuvânt dat, va fi selectat cuvântul considerat cel mai apropiat în ordine lexicografică. Spre exemplu, căutăm potrivire pentru „abc” și avem două posibilități în dicționar: „abcde” cu prioritatea 2 și „abce” tot cu prioritatea 2. Va fi selectat cuvântul „abcde”, deoarece este mai mic decât „abce”.

---

# Calculator pe biți

A treia funcționalitate implementată este un calculator pentru operații pe biți. Acesta este foarte simplu și suportă până la 4 operații consecutive, pe numere de 4 biți.

Numerele și operațiile sunt extrase dintr-un unsigned int, introdus de la tastatură, cu forma:

- Numerele sunt reprezentate pe câte 4 biți.
- Operațiile sunt reprezentate pe câte 2 biți, având următoarea codificare:

| Operație         | Codificare |
| ---------------- | ---------- |
| Adunare          | 00         |
| Interschimbare   | 01         |
| Rotație la stânga | 10         |
| XOR              | 11         |

### Adunare

Rezultatul acestei operații va fi suma celor două numere pe 4 biți. Spre exemplu, după aplicarea operației de adunare pentru `0001` și `0101`, rezultatul va fi `0110`.

### Interschimbare

În cazul acestei operații, bitul de pe poziția p1 va fi interschimbat cu bitul de pe poziția p2 pentru primul număr, unde p1 reprezintă primii 2 biți din al doilea număr, iar p2 reprezintă ultimii doi biți din al doilea număr. De exemplu, aplicând operația de interschimbare pentru `0001` și `1100`, rezultatul va fi `1000`. Bitul de pe poziția 11 = 3 (ultimul bit din primul număr) va fi interschimbat cu bitul de pe poziția 00 = 0 (primul bit din primul număr).

### Rotație la stânga

Aplicând această operație pe două numere, nr1 și nr2, rezultatul va fi nr1 rotit la stânga de nr2 ori. De exemplu, aplicând operația de rotație pentru `1011` și `0101` = 5, rezultatul va fi `0111`.

### XOR

Rezultatul acestei operații va fi aplicarea operatorului XOR asupra celor două numere pe 4 biți. Spre exemplu, după aplicarea operației XOR pentru `1011` și `0101`, rezultatul va fi `1110`.
