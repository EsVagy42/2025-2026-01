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
- a kiértékelési sorrend közömbös
    - mert a függvények tiszták
        - értékek nem változhatnak
        - mellékhatások teljes hiánya
    - **ha kijön az eredmény**
        - nem mindig jön ki az eredmény mohóval, viszont gyorsabb
        - a lustával kijön az eredmény, ha van
        - `g x = g x`
            - nem kiszámítható
- clean vs haskell
    - clean-ban a számok és az alap függvények a standard könyvtár része
    - haskell-ben ez a nyelv része
- **precedencia**
    - műveletek kötése, zárójelezés szabálya
    - meghatározza, hogy melyik függvény melyik argumentuma
- **`..` még mindig számtani sorozat**
- **a `[]` azt jelenti, hogy a tárolási módszer lista**
    - tehát a `[1..10]` beleteszi egy listába a számtani sorozat értékeit
- **a konstansok függvények, amik magukat adják vissza**
- `[0:[1, 2]] ++ [3, 4, 5]`
    - a `:` egy számot és egy listát fűz össze
        - balról egy számot jobbról egy listát vár *mindig*
        - gyorsabb mint a `++`
    - a `++` két listát fűz össze
- magasabb rendű függvény
    - egy függvény a paramétere
