1. Text Highlight
Chiar dacă scrierea codului poate părea câteodată o acțiune uşoară, aceasta implică multe
cunoştințe teoretice cât şi foarte multă practică, mai ales în scrierea de programe complexe.
Astfel, pentru a veni în ajutorul utilizatorilor, s-a creat highlighting-ul pe text, ceea ce înseamnă
că vor exista cuvinte cheie precum "for", "while" , "int" , "float" care vor fi scoase în evidență
pentru o înțelegere mai uşoară a codului. În această problemă ne propunem să simulăm facilitatea
de TextHighlight.
Pentru a putea simula highlighting-ul pe text, vom “sublinia” keyword-urile întâlnite pe linia
următoare. Sublinierea unui keyword se va face folosind caracterul ‘_’ (underline) pentru fiecare
caracter al cuvântului respectiv (incluzând spațiile în cazul keyword-urilor formate din mai multe
cuvinte), iar pentru restul caracterelor care nu fac parte din cuvintele cheie se va folosi ‘ ’ (spațiu).
Atenţie! Deoarece multe programe permit scrierea de secvențe cheie formate din mai multe
cuvinte cu un număr variabil de spații între ele, pentru problema noastră va fi luat în calcul şi
acest caz!
Evitați, totuşi, să scrieți cod în acest fel, deoarece devine greu de înțeles si trebuie respectat un
coding style.
Pentru această temă vom considera drept cuvinte cheie (keywords) doar următoarele cuvinte şi
secvenţe de două cuvinte: first of, for, for each, from, in, is, is a, list of, unit, or, while, int,
float, double, string.


3. Autocomplete
Autocomplete-ul este o funcționalitate des folosită. Deși aceasta ajută în teorie la economisirea
timpului, poate genera și greşeli, depinzând de modul în care este folosită.
Cu timpul, mare parte dintre probleme au fost rezolvate și autocomplete-ul ajută aproape în
fiecare caz, printre cele mai utile și folosite fiind autocomplete-ul căutării pe Google. Acest
autocomplete este totuși destul de complex, folosind atât căutările precedente ale utilizatorului
curent, a celorlalți utilizatori, keyword-urile paginilor existente pe Google, cât și cele mai
populare căutări.
Astfel, în această problemă ne propunem să implementăm un autocomplete care pornește de la un
anumit număr de cuvinte (un mini-dicționar) și care se actualizează odată cu introducerea unor
cuvinte noi sau folosirea celor recente.
Fiecare cuvânt din dicționar va avea la început prioritatea 0 și va fi reprezentat sub forma aceasta:
struct dictionary_entry{
char* word;
int priority;
};
Fiecare cuvânt scris de utilizator face parte din una dintre următoarele 3 categorii:
•cuvânt -- care nu face match cu niciun cuvânt existent în dicționar, așa că va fi scris în
output la fel ca în input și va fi adăugat în dicționar cu prioritatea 1, fiind prima sa
apariție în text
•cuvânt* -- care se potrivește cu un cuvânt de prioritate mai mare, dar utilizatorul vrea
cuvântul scris de el, deși are prioritate mai mică (acest cuvânt poate exista sau nu în
dicționar, caz în care ar trebui adăugat) -> se va afişa cuvânt şi ii va creşte prioritatea
•cuv -- care se potrivește cu unul sau mai multe cuvinte din dicţionar (care încep cu cuv) şi
se alege cel care are prioritatea cea mai mare. De asemenea, prioritatea cuvântului ales din
dicționar va crește pentru cuvântul selectat.
Observaţie: Dacă avem cuvinte în dicţionar cu aceeaşi prioritate şi căutăm o potrivire
pentru un cuvânt dat, se va alege cuvântul considerat ca fiind cel mai aproape in ordine
lexicografică.
Spre exemplu, căutăm potrivire pentru „abc” şi avem două posibilităţi în dicţionar: ”abcde”
cu prioritatea 2 si „abce” tot cu prioritatea 2. Vom alege cuvântul „abcde”, deoarece este
mai mic decât „abce”.

4. Calculator pe biţi

A treia funționalitate implementată este un calculator de operații pe biți. Acesta va fi foarte simplist,
suportând până la 4 operații consecutive, pe numere de 4 biți.
Numerele și operațiile vor fi extrase dintr-un unsigned int, dat de la tastatura, număr care va fi dat
sub forma:
Numerele sunt reprezentate pe câte 4 biți, iar operațiile pe câte 2 biți, operațiile fiind codificate
astfel:
Operatie Codificare
Adunare 00
Interschimbare 01
Rotație la stânga 10
Xor 11

Adunare
Rezultatul acestei operații va fi suma celor două numere pe 4 biți. Spre exemplu, după aplicarea
operației de adunare pentru 0001 și 0101, va rezulta 0110.

Interschimbare
La aplicarea acestei operații se va interschimba bitul de pe pozița p1 cu bitul de pe poziția p2 pentru
primul număr, unde p1 reprezintă primii 2 biți din al doilea număr, iar p2 reprezintă ultimii doi biți
din al doilea număr. De exemplu, dacă se aplică operația de interschimbare pentru 0001 și 1100,
rezultatul va fi 1000. Bitul de pe poziția 11 = 3 (ultimul bit din primul număr), va fi interschimbat cu
bitul de pe poziția 00 = 0 (primul bit din primul număr).

Rotație la stânga
Dacă se aplică această operație pe două numere, nr1, respectiv nr2, rezultatul va fi nr1 rotit la stânga
de nr2 ori. De exemplu, dacă se aplică operația de rotație pe 1011 și 0101 = 5, rezultatul va fi 0111.

XOR
Rezultatul acestei operații va fi aplicarea operatorului XOR celor două numere pe 4 biți. Spre
exemplu, după aplicarea operației XOR pentru 1011 și 0101, va rezulta 1110.
