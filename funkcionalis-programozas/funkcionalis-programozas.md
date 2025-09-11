# Funkcionális programozás

- feladatot írjuk le, nem az algoritmust
- biztos, hogy jó a megoldás, az imperatívnál lehetnek hibák, nem tökéletes

## Fontos linkek

- [lambda](https://lambda.inf.elte.hu)
- [learn you a haskell](https://learnyouahaskell.com/chapters)
- [tms](tms.inf.elte.hu)

# 8 királynő probléma

4 sorban

```
inc x = x + 1
```

- `inc` függvényazonosító
- `x` formális paraméter
- `=`-től jobbra lévő a függvénytörzs
- `[1..n]`-nél `..` mindig számtani sorozatot jelöl

- **polymorph** függvények
    - több argumentum adattípussal is működik
- minden dolognak egy definíciója van, semmi sem redefiniálható
- előre definiált függvények
    - nem beépített függvény
        - a beépített függvény a nyelvnek a része
    - valaki előre definiálta a függvényt
- **formális paraméter**
    - a függvény ismeretlen paramétere a függvény definíciójánál
- **minden függvénynek egy paramétere és egy visszatérési értéke van**
- **függvénykompozíció**
    - az egyik függvény paramétere egy másik függvény visszatérési értéke
    - lusta kiszámolás miatt nem feltétlenül kell kiszámítanunk előre a visszatérési értéket
- **diszkusszió**
    - mi történik ha a függvényt az értelmezési tartományán kívüli értékkel hívjuk meg
- használható olyan függvény is, amit még nem definiáltam
- `+` nem használható két különböző típussal
- így az `inc` függvényünk csak egészekkel fog működni
- **kezdeti kifejezés**
    - egy kifejezés lehet
    - ezt számoljuk ki
- a kiértékelés úgy történik, hogy a függvényhívásokat a definíciójukkal helyettesítjük
- **normál forma**
    - nincs több olyan definíció, amit alkalmazhatnánk, lecserélhetnénk
- **gráfátírás**
    - a függvényhívások gráfként jelennek meg
        - így ha valamit kiszámolunk, már nem kell mégegyszer
        - lehet párhuzamosan számolni a gráf csúcsait
            - **párhuzamos kiértékelés**
- kiértékelés lehet
    - **mohó**
    - **lusta**
