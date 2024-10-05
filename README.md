<h1 align="center">
  <img  width="120" alt="42logo"  src="https://user-images.githubusercontent.com/19689770/129336866-169b0dc7-ea41-47d4-b50a-d466508031af.png">
  
	push_swap

</h1>

 <p align="center">
<img alt="total-views" src="https://img.shields.io/badge/views-12-blue">
<img alt="total-clone" src="https://img.shields.io/badge/clone-76-blue">
<img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/nach131/push_swap">
<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/nach131/push_swap">
<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/nach131/push_swap">
<img alt="license-MIT" src="https://img.shields.io/badge/license-MIT-blue">
</p>

<span align="center">

![visitors](https://visitor-badge.glitch.me/badge?page_id=nach131.push_swap&left_color=green&right_color=blue)

![125](https://github.com/nach131/42Barcelona/blob/main/images/125.png)



</span>


## Swap

<details>
  <summary>Detalle</summary>
	
<br><br/>
	
> **sa: swap a**

 Intercambia los dos primeros elementos encima del ```stack A```. No hace nada si hay uno o menos elementos.

<img src="https://github.com/nach131/push_swap/blob/Two-Struct/img/sa__swap_a.png" alt="drawing" width="150"/>

<br><br/>

> **sb: swap b**

 Intercambia los dos primeros elementos encima del ```stack B```. No hace nada si hay uno o menos elementos.

 <img src="https://github.com/nach131/push_swap/blob/Two-Struct/img/sb__swap_b.png" alt="drawing" width="150"/>

<br><br/>

> **ss: swap sa y swap sb**

 Intercambia los dos primeros elementos encima del ```stack A``` e intercambia los dos primeros elementos encima del ```stack B```. No hace nada si hay uno o menos elementos.

 <img src="https://github.com/nach131/push_swap/blob/Two-Struct/img/ss__swap_a_&_swap_b.png" alt="drawing" width="150"/>

<br><br/>

</details>

## Push

<details>
  <summary>Detalle</summary>

<br><br/>

> **pa: push a**

Toma el primer elemento del ```stack B``` y lo pone encima del ```stack A```. No hace nada si b está vacío.

 <img src="https://github.com/nach131/push_swap/blob/Two-Struct/img/pa__push_b.png" alt="drawing" width="150"/>

<br><br/>

> **pb: push b**

Toma el primer elemento del ```stack A``` y lo pone encima del ```stack B```. No hace nada si b está vacío.

 <img src="https://github.com/nach131/push_swap/blob/Two-Struct/img/pb__push_a.png" alt="drawing" width="150"/>

<br><br/>

</details>

## Rotate

<details>
  <summary>Detalle</summary>

<br><br/>

> **ra: rotate a**

Desplaza hacia arriba todos los elementos del ```stack A``` una posición, de forma que el primer elemento se convierte en el último.

 <img src="https://github.com/nach131/push_swap/blob/Two-Struct/img/ra__rotate_a.png" alt="drawing" width="150"/>

<br><br/>

> **rb: rotate b**

Desplaza hacia arriba todos los elementos del ```stack B``` una posición, de forma que el primer elemento se convierte en el último.

 <img src="https://github.com/nach131/push_swap/blob/Two-Struct/img/rb_rotate_b.png" alt="drawing" width="150"/>

<br><br/>

> **rr: rotate a y rotate b**

Desplaza al mismo tiempo todos los elementos del ```stack A``` y del ```stack B``` una posición hacia arriba, de forma que el primer elemento se convierte en el último.

 <img src="https://github.com/nach131/push_swap/blob/Two-Struct/img/rr_rotate_a_&&_rotate_b.png" alt="drawing" width="150"/>

<br><br/>

</details>

## Reverse

<details>
  <summary>Detalle</summary>

> **rra: reverse rotate a**

Desplaza hacia abajo todos los elementos del ```stack A``` una posición, de forma que el último elemento se convierte en el primero.

 <img src="https://github.com/nach131/push_swap/blob/Two-Struct/img/rra__reverse_rotate_a.png" alt="drawing" width="150"/>
	
<br><br/>

> **rrb: reverse rotate b**

Desplaza hacia abajo todos los elementos del ```stack B```una posición, de forma que el último elemento se convierte en el primero.


 <img src="https://github.com/nach131/push_swap/blob/Two-Struct/img/rrb__reverse_rotate_b.png" alt="drawing" width="150"/>  
	
<br><br/>

 > **rrr: reverse rotate a y reverse rotate b**  
	
Desplaza hacia abajo todos los elementos del ```stack A``` una posición y desplaza hacia abajo todos los elementos del ```stack B```una posición, de forma que el último elemento se convierte en el primero.

 <img src="https://github.com/nach131/push_swap/blob/Two-Struct/img/rrr__reverse_rotate_a_&_reverse_rotate_b.png" alt="drawing" width="150"/>

</details>

## Merge Sort (Ordenado por fusión)

[Código](https://github.com/nach131/push_swap/blob/Two-Struct/funciones/merge_sort/libro_nach.c)

Merge Sort es un algoritmo de divide y vencerás. Divide el stack de entrada de longitud n por la mitad sucesivamente hasta que haya n stack de tamaño 1. Luego, los pares de stack se fusionan con el primer elemento más pequeño entre el par de stack que se agregan en cada paso. A través de la fusión sucesiva y la comparación de los primeros elementos, se construye el stack ordenado.

```mermaid
flowchart TD
    inicio[38,27,43,3,82,9,10]--> A
    inicio --> B[9,82,10]
    A[38,27,43,3] --> A1[43,3]-->A1b
    A --> A2[38,27]-->A3a[38]-->A4
    A2 --> A3b[27]-->A4[27,38]-->A5
A1-->A1a[43]-->A4b
A1b[3]-->A4b[3,43]-->A5
A5[3,27,38,43]-->fin
B-->B1a[82,9]-->B2a[82]-->B3
B1a-->B2b[9]-->B3[9,82]-->B4
B-->B1b[10]-->B4[9,10,82]-->fin[3,9,10,27,38,43,82]
```

<br><br/>

**Complejidad del tiempo:**

$$T(n) = 2T(n/2) + Θ(n)$$

La recurrencia anterior se puede resolver utilizando el método de árbol de recurrencia o el método maestro. Cae en el caso II del Método Maestro y la solución de la recurrencia es $Θ(nLogn)$.

La complejidad de tiempo de Merge Sort es $Θ(nLogn)$ en los 3 casos (peor, promedio y mejor) ya que merge sort siempre divide la matriz en dos mitades y toma un tiempo lineal para fusionar dos mitades.

## Quick Sort (Ordenado "rapida")

[Código](https://github.com/nach131/push_swap/blob/Two-Struct/funciones/quick_sort/quickSort_nach.c)

```mermaid
graph TD;
  A(38, 27, 43, 3, 82, 10, 9)
  A --> B(9, 3)
  A --> C(27, 10)
  A --> D(82, 43)
  B --> B1(3)
  B --> B2(9)
  D --> D1(43)
  D --> D2(82)
  C --> C1(10)
  C --> C2(27)
  B1 --> E(3, 9)
  D1 --> F(43, 82)
  C1 --> G(10, 27)
  E --> H(3, 9, 27)
  H --> I(3, 9, 10, 27)
  F --> J(3, 9, 10, 27, 43, 82)
  G --> K(3, 9, 10, 27, 43, 82)
  I --> fin(3, 9, 10, 27, 43, 82)
  J --> fin
  K --> fin
  ```

<br><br/>

**Complejidad del tiempo:**

$$T(n) = T(k) + T(n-k-1) + Θ(n)$$

Donde ```n``` es el tamaño de la lista a ordenar, ```k``` es la posición del pivote (el elemento elegido para dividir la stack en dos sub-stacks) después de la partición y $Θ(n)$ es el tiempo de procesamiento necesario para dividir el stack en dos sub-stack.

La fórmula indica que el tiempo de ejecución de QuickSort depende del tiempo de ejecución de los dos sub-stacks creados después de la partición, así como del tiempo necesario para dividir la lista original.

El mejor caso para QuickSort es cuando el stack está pre-ordenada o cuando todos los elementos son iguales, en cuyo caso la complejidad de tiempo es de $O(n log n)$. El peor caso es cuando la lista está ordenada en orden inverso, en cuyo caso la complejidad de tiempo es de $O(n^2)$. En el caso promedio, QuickSort tiene una complejidad de tiempo de $O(n log n)$.

## Salida error

La salida de error estándar `(stderr)` normalmente se muestra en la consola junto con la salida estándar `(stdout)`, a menos que se redirija a otro lugar como un archivo o una tubería. Por lo tanto, si un programa escribe en stderr y se ejecuta desde la consola, la salida de error debería ser visible en la consola.

Para redirigir la salida de error a un archivo.

```c
./push_swap 42 84 2> error.txt
```

	brew install coreutils

	export NUMEROS=$(jot -n 10 1 1000 | tr '\n' ' ')

	export NUMEROS=$(shuf -i 1-100 -n 100 | tr '\n' ' ')

/push_swap $ARG | wc -l

	./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`

	export NUM=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')")

 	while [ 1 ]; do ./push_swap $(ruby -e "puts (1..100).to_a.shuffle.join(' ')") | wc -l; contador=$((contador + 1)); done

https://en.wikipedia.org/wiki/Stack_(abstract_data_type)

```mermaid
graph TD;
  A(12 9 3 25 24 4 17 6 29 8 26 7 30 16 10 13 19 15 23 1 21 2 5 22 28 11 18 20 27 14)
  A-->C1(30 26 29 27 28)-->D
  A-->B1(19 16 17 20 18)-->D
  A --> A1(10 7 8 6 9)-->D
  A --> A2(3 4 1 2 5)-->D
  A --> B2(11 14 12 13 15)-->D
  A-->C2(21 22 25 24 23)-->D
D(1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30)
  ```
