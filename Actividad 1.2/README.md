# Dynamic Programming and Greedy Algorithm

La implementación del programa utilizando el método dinámico y el algoritmo avaro tiene como
objetivo dar el cambio de dinero exacto para una compra donde se establece el precio del producto
y la moneda o billete utilizado para pagar. 
El programa debe recibir un número entero N, seguido por N valores enteros para definir las diferentes
denominaciones de las monedas para proporcionar el cambio, estos valores no estan en orden descendente. 
Después, el programa debe recibir dos valores entereos P y Q para definir el precio del producto a comprar
 y por la moneda o billete que es entregado para hacer la compra respectivamente. 

## Uso
1. Compilar archivo main.cpp y ejecutar
-  g++ main.cpp -o coinChange
- ./coinChange

2. Ejecutar con archivo de texto como entrada
- g++ main.cpp -o coinChange
- ./coinChange < ruta_al_archivo
- ./coinChange  < ./tests/test-1.txt

## Casos de prueba 
1. ./coinChange ./tests/test-1.txt
Este primer caso evalua el funcionamiento correcto normal de la programación 
dinámica y el algoritmo avaro. Se otorgan 4 valores de monedas sin orden junto
con un precio y pago para dar un cambio exacto de 18, dando una cantidad exacta de 
1 moneda por cada denominacion.
Salida esperada:
```
Cambio calculado en programacion dinamica: 
10: 1
5: 1
2: 1
1: 1
Cambio calculado en algoritmo avaro: 
10: 1
5: 1
2: 1
1: 1
```
2. ./coinChange ./tests/test-2.txt
El segundo caso de prueba evalua el cambio monetario de una compra grande con un 
billete grande, dando un precio de 328 pagado con un billete de 500. Se espera 
cambio de 172 con las denominaciones de monedas iguales al problema anterior. 
```
Cambio calculado en programacion dinamica: 
10: 17
5: 0
2: 1
1: 0
Cambio calculado en algoritmo avaro: 
10: 17
5: 0
2: 1
1: 0
```

3. ./coinChange ./tests/test-3.txt
Este caso de prueba evalua el comportamiento diferente de la programación dinámica 
y el algoritmo avaro al ingresar monedas con denominación irregular. Se espera que la
programación dinámica otorgue el cambio exacto y correcto, mientras que el algoritmo
avaro no logre dar el cambio completo. 
Salida esperada:
```
Cambio calculado en programacion dinamica: 
11: 1
8: 0
3: 3
Cambio calculado en algoritmo avaro: 
11: 1
8: 1
3: 0
```

4. /coinChange ./test/test-4,txt
En este caso de prueba se evalua de igual manera el funcionamiento 
correcto bajo las denominaciones de monedas irregulares para un cambio de valor 15. 
En la programación dinámica se observa una respuesta óptima y correcta, en cambio
el algoritmo avaro dará una respuesta correcta pero no óptima al utilizar mayor cantidad de monedas.  
Salida esperada:
```
Cambio calculado en programacion dinamica: 
10: 0
7: 2
1: 1
Cambio calculado en algoritmo avaro: 
10: 1
7: 0
1: 5
```

5. ./coinChange ./tests/test-3.txt
Este último caso de prueba evalua un cambio que es imposible tanto para la
programación dinámica como para el algoritmo avaro poder generar debido a que
la moneda más pequeña no es capaz de ofrecer un valor menor.
Salida esperada:
```
Cambio calculado en programacion dinamica: 
11: -1
8: -1
3: -1
Cambio calculado en algoritmo avaro: 
11: -1
8: -1
3: -1
``` 

# Author:
- Brandon Magaña
- Santiago González de Cosío