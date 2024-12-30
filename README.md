# Pirma užduotis:
Suskaičiuoti kiek kartų kiekvienas žodis pasikartoja tekste. Rezultato faile lieka tik tie žodžiai, kurie pasikartoja daugiau nei vieną kartą.

### Algoritmo eiliškumas:
1. Perskaitome duomenis iš failo, panaikiname punktuaciją ir galiausiai pridedame juos į map duomenų struktūrą;
2. Tikriname, ar žodis pasikartoja daugiau nei vieną kartą. Jei sąlyga nėra tenkinama, tas žodis yra panaikinamas;
3. Įrašome gautus rezultatus į failą.
</br>

# Antra užduotis:
Sukurti cross-reference lentelę, kurioje būtų nurodyta kuriuose eilutėse žodžiai buvo paminėti.

### Algoritmo eiliškumas:
1. Skaitome pradinio failo duomenis pažodžiui;
2. Kiekvienam rastam žodžiui priskiriame papildomą reikšmę, kuri nusako kuriuose eilutėse tas žodis buvo paminėtas;
3. Įrašome gautus rezultatus į failą.
</br>

# Trečia užduotis:
Surasti url adresus duotame tekstiniame faile.

### Algoritmo eiliškumas:
1. Iteruojame per pradinį duomenų failą eilutėmis;
2. Kiekvienoje eilutėje patikriname, ar ji turi url adresą;
3. Jeigu sąlyga tenkinama, pridedame rastą url į vektorių;
4. Įrašome gautus rezultatus į failą.
