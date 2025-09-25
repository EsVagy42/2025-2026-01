# Számítógép

- általános számítógép
    - minden számításra használható
- célszámítógép
    - csak egy bizonyos cél elérésére használható

## parancsok

- `ls` kiírja a hard linkek számát is
    - számolja az os, ha kitörölnénk egy fájlt
- `chgrp` a csoport tulajdonost változtatja meg
- `umask` az ez után létrehozott fájlok jogosultságának beállítása
- `read` beolvas ha egy argumentuma van akkor az egész sor oda kerül, különben helyközönként van elválasztva

## j\*b-ok

- **amikor a shell elindít egy programot, akkor annak lesz egy j\*b száma is**
- **bash-ban `%`-ot kell egy szám elé tenni, ez jelenti azt a számú j\*b-ot**
- **`Ctrl-Z` az megállít egy processt**
- **a nice value adja meg a futási prioritást, [-20, 19] értékek lehetnek, minnél kisebb, annál nagyobb a prioritás**
- **`cron`-al időzíthetünk command-okat**

## strings

- `'` között semminek nincs speciális jelentése
- **`"` között megmarad a `$`, `\`, `\`` és a `'` jelentése**

## i/o

- **i/o deszkriptor a `&`**
    - `>&2` az stderr-re irányít

`&0`
: stdin

`&1`
: stdout

`&2`
: stderr

- **viszont a `2>` `&` nélkül irányítja a stderr-t valamelyik fájlba
