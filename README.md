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
