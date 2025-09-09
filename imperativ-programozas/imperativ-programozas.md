# Imperatív programozás

- [tudnivalók](https://canvas.elte.hu/courses/59082)
- a nyelvek alapjait tanuljuk
    - nyelvek
        - c
        - python

## Imperatív

- utasításokkal írjuk le a dolgokat
    - lépéseket írjuk le
- központjában a memória áll

## Programok felépítése

### Alapelemek

- kulcsszavak
- literálok
- operátorok
- azonosítók
    - nevek, pl. változónevek

### Építőelemek

- kifejezések
- utasítások
- alprogramok
    - függvények
    - eljárások
- modulok
    - könyvtárak
    - osztályok
    - csomagok

## Példa

```python
    def factorial(n):
        result = 1
        for i in range(2, n+1):
            result *= i
        return result
```

```c
    int factorial(int n) {
        int result = 1;
        for(int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }
```

- a lokális változók a stack-en vannak
- hiearchikus felépítés
- utasítások után `;` c-ben
- pythonban indentálás számít
- **a kapcsoszárójelek között lévő utasítások egy utasítást alkotnak**
- c-ben az else a hozzá legközelebb álló *if*hez tartozik

## I/O

```python
    print(factorial(10))
    print("10! = ", factorial(10), ", ln(10) = ", ln(10))
```

```c
    printf("%d\n", factorial(10));
    printf("10! = %d, ln(10) = %f\n", factorial(10), ln(10));
```

## Típusok

- c-ben a szöveg null terminált
- az adat értelmét/értelmezési módját határozza meg
- van pointer
- big/little endian bájtoknál is

## Modulok

- egybezárás, függetlenség, szűk interfacek
- library

### C

- header fájlok
