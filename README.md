# sadje

Na mizi je zaporedje n sadežev, vsak od njih pa je jabolko ali hruška. Iva in Ivo se
gresta naslednjo igro:
• Prva je na vrsti Iva, ki vrine v zaporedje na poljubna mesta še največ k jabolk
(lahko tudi manj, lahko celo nobenega). Teh dodatnih jabolk ji ni treba vriniti vseh
skupaj, ampak lahko vsako od njih vrine na poljubno mesto v zaporedju (lahko tudi
na začetek ali na konec zaporedja).
• Nato je na vrsti Ivo, ki pobere vsak m-ti sadež v tako nastalem zaporedju.
Ivo ima rad jabolka. Iva pa je zlobna in bi rada zaporedje spremenila tako, da bo Ivo
pobral čim manj jabolk.

## Naloga
Napišite program, ki prebere števila n, k, m ter opis začetnega zaporedja in ugotovi, kako
naj Iva vriva dodatna jabolka v zaporedje, da bo nato Ivo v svoji potezi pobral čim manj
jabolk.

## Vhodni podatki
V prvi vrstici so tri cela števila, n, k in m, ločena s po enim presledkom. V drugi vrstici je
niz n znakov, ki po vrsti navajajo vsebino začetnega zaporedja sadežev (torej zaporedja,
kakršno je na mizi, preden začne Iva vrivati dodatna jabolka). V tem nizu znak 0 pomeni
hruško, znak 1 pa jabolko.

## Omejitve vhodnih podatkov
• 1 ≤ n ≤ 10 000
• 0 ≤ k ≤ 50
• 1 ≤ m ≤ 10 000

## Izhodni podatki
V prvo vrstico izpišite število jabolk, ki jih bo Ivo pobral (po tistem, ko bo Iva na maksimalno zloben način vrinila morebitna dodatna jabolka v zaporedje). V drugo vrstico
izpišite, kako naj Iva pri tem vriva dodatna jabolka: najprej izpišite število vrinjenih
jabolk, nato pa njihove indekse v končnem zaporedju (torej takem, kakršno nastane po
vseh vrivanjih; indeksi gredo od 1 naprej).
Če je možnih več enako dobrih najboljših rešitev (dve rešitvi štejemo za enako dobri,če
Ivo pri obeh pobere enako število jabolk), je vseeno, katero od njih izpišete.
