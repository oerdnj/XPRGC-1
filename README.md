# toupper <string>

POSIX definuje funkci pro převod malých písmen na velká jako:

    int toupper(int c);

Jelikož *char* může být dle standardu signed i unsigned, tato
implementace inspirovaná implementací z glibc používá tabulku, která
je v rozsahu od CHAR_MIN do UCHAR_MAX, tedy buď <0, 255> nebo
<-127, 255>, dle platformy, na které se aplikace kompiluje.

# valec <r> <v>

Jediná trochu zajímavá věc je použití konstanty M_PI z hlavičkového
souboru <math.h>.  Při použití funkcí z <math.h> je/bylo na některých
platformách zapotřebí linkovat libm, ale protože používáme jenom
konstantu z hlavičkového souboru, tak to v tomto případě můžeme
vynechat.

# checkprime <repeats> <prime> [<prime> ...]

Program checkprime kontroluje zda-li je/jsou zadaná čísla prvočísla
několika metodami (první použité jsou adaptací zdroje [1]).

1. naivní způsob - O(n)

2. odmocnina[3] - O(n^1/2)

3. odmocnina (celočíselně) - O(sqrt(n))

4. OpenSSL BIGNUM[2] - není pro naše použití nejrychlejší, ale umí
   pracovat s libovolně velkými čísly

První zdroj uvádí ještě Wilsonův teorém, ale kvůli použití faktoriálu
implementace musí pracovat opět s BIGNUM čísly, a čas je O(n), takže
výsledek je složitější, pomalejší a náročnější než naivní implementace

1. https://www.geeksforgeeks.org/c-program-to-check-whether-a-number-is-prime-or-not/
2. https://www.openssl.org/docs/man3.0/man3/BN_is_prime.html
3. http://mathandmultimedia.com/2012/06/02/determining-primes-through-square-root/
