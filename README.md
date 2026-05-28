# EcoMisión  
## Experiencia interactiva sobre el cuidado ambiental

### Programación Orientada a Objetos - 2026-1

## Integrantes

- Juan Alejandro Valencia  
- Sofia Paredes  
- Natalia Toro  

---

## ¿Qué es EcoMisión?

EcoMisión es un proyecto que desarrollamos para la materia de Programación Orientada a Objetos. La idea del programa es representar una pequeña experiencia interactiva en consola, donde una persona exploradora recorre diferentes zonas de una reserva natural y se encuentra con situaciones relacionadas con el cuidado ambiental.

En nuestro caso, el explorador inicia en una zona llamada **Pantano** y allí encuentra diferentes elementos con los que puede interactuar. Algunos de esos elementos ayudan a mejorar su puntaje ambiental, otros le recuperan energía y otros permiten que se mueva hacia una zona diferente.

No queríamos que el programa fuera solamente imprimir mensajes en consola, sino que realmente se pudiera ver que las decisiones del explorador cambian su estado dentro del recorrido. Por eso manejamos tres datos importantes:

- La energía del explorador.
- Su puntaje ambiental.
- La zona en la que se encuentra actualmente.

Durante la demostración, el explorador ayuda a un animal herido, recoge una planta medicinal y finalmente utiliza un portal que lo lleva hacia el Bosque. Cada una de esas acciones produce un cambio diferente en el programa.

---

## ¿Cómo funciona la experiencia?

Cuando se ejecuta el programa, se crea un objeto de la clase `EcoMision`. Esta clase es la que se encarga de organizar todo el recorrido, porque desde ahí se crea el explorador, se preparan las zonas y se agregan los elementos interactivos.

El explorador que usamos en la demostración se llama **Juan**. Él inicia con:

| Estado inicial | Valor |
|---|---:|
| Energía | 100 |
| Puntaje ambiental | 0 |
| Zona actual | Pantano |

En el Pantano se encuentran tres elementos:

1. Un animal herido.
2. Una planta medicinal.
3. Un portal de ruta que conduce hacia el Bosque.

La secuencia de la demostración funciona así:

### 1. Interacción con el animal herido

El explorador encuentra un animal que necesita ayuda. Cuando interactúa con él, el programa muestra que el animal fue atendido.

Esta acción tiene dos consecuencias:

- El explorador gana `20` puntos ambientales, porque realizó una acción positiva para el entorno.
- El explorador pierde `10` puntos de energía, porque ayudar al animal requiere esfuerzo.

Después de esta interacción, el explorador queda con:

| Estado | Valor |
|---|---:|
| Energía | 90 |
| Puntaje ambiental | 20 |

### 2. Interacción con la planta medicinal

Luego, el explorador recoge una planta medicinal. En el proyecto decidimos que este elemento serviría para recuperar energía.

La planta aumenta la energía del explorador en `20` puntos.

Después de recogerla, el explorador queda con:

| Estado | Valor |
|---|---:|
| Energía | 110 |
| Puntaje ambiental | 20 |

### 3. Interacción con el portal de ruta

Finalmente, el explorador encuentra un portal. Este elemento no cambia su energía ni su puntaje, sino que modifica su ubicación dentro de la reserva.

En este caso, el portal tiene como destino el **Bosque**, por lo que después de interactuar con él el explorador deja el Pantano y pasa a esa nueva zona.

El estado final del recorrido es:

| Estado final | Valor |
|---|---:|
| Nombre del explorador | Juan |
| Energía | 110 |
| Puntaje ambiental | 20 |
| Zona actual | Bosque |

---

## ¿Qué quisimos lograr con el proyecto?

Con EcoMisión queríamos construir un programa sencillo, pero que nos permitiera aplicar de verdad los conceptos vistos en clase. Al comienzo parecía suficiente crear unas cuantas clases y hacer que imprimieran mensajes, pero mientras fuimos avanzando nos dimos cuenta de que era importante organizar bien quién hacía cada cosa.

Por ejemplo, no tenía sentido que `main.cpp` tuviera toda la lógica del programa, porque se volvería muy largo y difícil de organizar. Tampoco tenía sentido crear una sola clase para todos los elementos ambientales, porque un animal herido no se comporta igual que una planta o que un portal.

Por eso decidimos dividir el sistema en varias clases, donde cada una tiene una responsabilidad más clara:

- `EcoMision` coordina la experiencia completa.
- `Reserva` administra las zonas.
- `Zona` almacena los elementos disponibles en cada lugar.
- `Explorador` guarda el estado de la persona que recorre la reserva.
- `ElementoInteractivo` sirve como base para todos los elementos del entorno.
- `AnimalHerido`, `PlantaMedicinal` y `PortalRuta` representan interacciones distintas.

Esta organización nos permitió que el programa fuera más fácil de entender y también más fácil de explicar en la sustentación.

---

## Clases principales del proyecto

### Clase `EcoMision`

Esta es la clase principal del prototipo. Se puede decir que es la que arma la experiencia completa.

Dentro de esta clase se crea:

- La reserva.
- El explorador.
- Las zonas utilizadas en la demostración.
- Los elementos que aparecen dentro de las zonas.

Además, desde `EcoMision` se ejecutan las interacciones y se muestra el estado final del recorrido.

En nuestro código, esta clase tiene dos atributos principales:

```cpp
Reserva* reserva;
Explorador* explorador;
```

Esto significa que `EcoMision` conoce y coordina tanto la reserva como al explorador.

Sus métodos principales son:

```cpp
EcoMision();
void iniciar();
void mostrarRecorrido();
void ejecutarInteracciones();
```

Actualmente, la demostración principal se realiza desde `iniciar()`, porque allí se crean las zonas, se agregan los elementos y se ejecutan las interacciones del explorador.

---

### Clase `Reserva`

La clase `Reserva` representa el conjunto de zonas que pueden existir dentro de EcoMisión.

Para organizar las zonas, utilizamos:

```cpp
unordered_map<string, Zona*> zonas;
```

Escogimos esta estructura porque las zonas se pueden identificar mediante un código. Por ejemplo, una zona puede guardarse con el código `"pantano"` y otra con el código `"bosque"`.

Los métodos que tiene esta clase son:

```cpp
void agregarZona(string codigo, Zona* zona);
Zona* buscarZona(string codigoZona);
void mostrarZonas();
```

La idea de esta clase es que, en lugar de manejar las zonas de manera desordenada, la reserva pueda registrarlas y buscarlas según el código que les corresponde.

Como ajuste final del proyecto, debemos conectar completamente esta clase con la demostración principal, registrando en `EcoMision::iniciar()` las zonas que ya se crean allí. Es decir, además de crear `Pantano` y `Bosque`, debemos agregarlas a la reserva para que el uso del `unordered_map` se vea reflejado también en la ejecución.

---

### Clase `Zona`

La clase `Zona` representa cada lugar por el que puede pasar el explorador. En la demostración actual tenemos dos zonas:

- Pantano.
- Bosque.

Cada zona tiene un nombre y una colección de elementos con los que se puede interactuar:

```cpp
string nombre;
vector<ElementoInteractivo*> elementos;
```

Esta decisión fue importante porque una misma zona puede tener elementos diferentes. Por ejemplo, el Pantano puede tener un animal herido, una planta medicinal y un portal de ruta, sin necesidad de crear un vector distinto para cada uno.

Los métodos principales de esta clase son:

```cpp
void agregarElemento(ElementoInteractivo* elemento);
void mostrarElementos();
void interactuarConElemento(int indice, Explorador* explorador);
void interactuarConElemento(string nombre, Explorador* explorador);
string getNombre();
```

En esta clase también aplicamos la **sobrecarga**, porque existen dos métodos llamados `interactuarConElemento()`, pero reciben parámetros diferentes.

Uno permite interactuar buscando el elemento por su posición:

```cpp
void interactuarConElemento(int indice, Explorador* explorador);
```

Y el otro permite buscarlo por su nombre:

```cpp
void interactuarConElemento(string nombre, Explorador* explorador);
```

Esto hace que la clase sea más flexible y, al mismo tiempo, cumple con uno de los requisitos solicitados en el proyecto.

---

### Clase `Explorador`

La clase `Explorador` representa a la persona que recorre la reserva.

En nuestro programa, el explorador se llama **Juan** y comienza con `100` puntos de energía y `0` puntos ambientales.

Sus atributos son:

```cpp
string nombre;
int energia;
int puntajeAmbiental;
Zona* zonaActual;
```

Estos atributos permiten saber quién está recorriendo la reserva, cuál es su estado y en qué zona se encuentra.

Los métodos más importantes son:

```cpp
void cambiarZona(Zona* nuevaZona);
void modificarEnergia(int valor);
void aumentarPuntaje(int puntos);
string getNombre();
int getEnergia();
int getPuntajeAmbiental();
Zona* getZonaActual();
```

Algo importante es que las demás clases no modifican directamente los atributos privados del explorador. Por ejemplo, `AnimalHerido` no entra directamente a cambiar la energía o el puntaje, sino que utiliza los métodos:

```cpp
explorador->aumentarPuntaje(20);
explorador->modificarEnergia(-10);
```

Esto nos permite aplicar encapsulamiento, porque el estado del explorador se modifica mediante métodos definidos dentro de su propia clase.

---

### Clase `ElementoInteractivo`

`ElementoInteractivo` es la clase base para todos los elementos con los que el explorador puede interactuar.

La definimos como una clase abstracta porque un elemento interactivo general no tiene una acción única. Es decir, no se puede decir que todos los elementos hacen exactamente lo mismo. Un animal herido necesita ayuda, una planta recupera energía y un portal cambia de zona.

Por esa razón, esta clase tiene el método virtual puro:

```cpp
virtual void interactuar(Explorador* explorador) = 0;
```

Este método obliga a que cada clase derivada escriba su propia forma de interactuar.

También tiene un atributo llamado `nombre`, que sirve para identificar cada elemento cuando se muestra en consola:

```cpp
string nombre;
```

Además, cuenta con un destructor virtual:

```cpp
virtual ~ElementoInteractivo() {};
```

Esto es importante porque los elementos se están manejando mediante punteros de la clase padre. De esta manera, si más adelante se eliminan objetos derivados desde un puntero de tipo `ElementoInteractivo*`, se pueden liberar correctamente.

---

### Clase `AnimalHerido`

`AnimalHerido` es una clase que hereda de `ElementoInteractivo`.

Cuando el explorador interactúa con este elemento, ocurre lo siguiente:

```cpp
explorador->aumentarPuntaje(20);
explorador->modificarEnergia(-10);
```

Decidimos hacerlo así porque ayudar a un animal representa una acción positiva para el medio ambiente, pero también requiere esfuerzo por parte del explorador.

Por eso, esta interacción mejora el puntaje ambiental, aunque disminuye un poco la energía.

---

### Clase `PlantaMedicinal`

`PlantaMedicinal` también hereda de `ElementoInteractivo`.

En este caso, la interacción es más sencilla: cuando el explorador encuentra la planta, recupera energía.

```cpp
explorador->modificarEnergia(20);
```

Esta clase nos permitió mostrar que no todos los elementos tienen que afectar de la misma forma al explorador. Mientras el animal modifica energía y puntaje, la planta solamente modifica la energía.

---

### Clase `PortalRuta`

`PortalRuta` es la tercera clase derivada de `ElementoInteractivo`.

Su función es permitir que el explorador se mueva de una zona a otra. Para lograrlo, el portal tiene un atributo que guarda hacia dónde conduce:

```cpp
Zona* destino;
```

En la demostración actual, el portal que está en el Pantano conduce hacia el Bosque.

Cuando el explorador interactúa con el portal, se ejecuta:

```cpp
explorador->cambiarZona(destino);
```

Con esto logramos que el recorrido no ocurra solamente en una zona fija, sino que el explorador pueda avanzar dentro de la reserva.

---

## Conceptos de POO que aplicamos

## Abstracción

La abstracción aparece principalmente en la clase `ElementoInteractivo`.

Nosotros sabemos que en la reserva existen diferentes objetos con los que el explorador puede interactuar, pero no todos reaccionan igual. Por eso creamos una clase general que representa la idea de “elemento interactivo” y dejamos que cada clase específica defina su propio comportamiento.

La clase abstracta funciona como una base común para:

- `AnimalHerido`.
- `PlantaMedicinal`.
- `PortalRuta`.

---

## Encapsulamiento

El encapsulamiento se puede ver en la clase `Explorador`, porque sus atributos están definidos como privados.

Esto quiere decir que la energía, el puntaje y la zona actual no deberían cambiarse directamente desde cualquier parte del programa.

En vez de hacer eso, utilizamos métodos como:

```cpp
modificarEnergia();
aumentarPuntaje();
cambiarZona();
```

De esta manera, el propio explorador controla los cambios en su estado.

---

## Herencia

La herencia aparece cuando las clases específicas de los elementos se construyen a partir de la clase `ElementoInteractivo`.

```cpp
class AnimalHerido : public ElementoInteractivo
class PlantaMedicinal : public ElementoInteractivo
class PortalRuta : public ElementoInteractivo
```

Todas comparten la característica de ser elementos de la reserva, pero cada una tiene su propia manera de reaccionar.

---

## Polimorfismo

El polimorfismo aparece en la clase `Zona`, porque allí guardamos elementos diferentes dentro de una misma colección:

```cpp
vector<ElementoInteractivo*> elementos;
```

Gracias a esto, la zona puede tener un animal, una planta y un portal dentro del mismo vector.

Luego, cuando se ejecuta:

```cpp
elementos[indice]->interactuar(explorador);
```

cada objeto responde de acuerdo con su clase real.

Esto significa que la zona no necesita preguntar si el elemento es un animal, una planta o un portal. Simplemente llama al mismo método y cada elemento sabe qué debe hacer.

---

## Sobrecarga

La sobrecarga aparece en la clase `Zona`.

Tenemos dos métodos que se llaman igual, pero reciben parámetros diferentes:

```cpp
void interactuarConElemento(int indice, Explorador* explorador);
void interactuarConElemento(string nombre, Explorador* explorador);
```

El primero sirve para interactuar con un elemento según su posición dentro del vector.

El segundo sirve para buscar un elemento por su nombre.

Con esto podemos usar la interacción de diferentes maneras sin tener que crear métodos con nombres completamente distintos.

---

## Uso de `unordered_map`

El uso de `unordered_map` aparece en la clase `Reserva`:

```cpp
unordered_map<string, Zona*> zonas;
```

La razón de utilizarlo es que queríamos que cada zona se pudiera identificar mediante un código. Así no dependemos de que el Pantano sea la posición `0` o el Bosque la posición `1`, sino que podemos relacionar directamente un texto con la zona correspondiente.

Por ejemplo:

```cpp
reserva->agregarZona("pantano", pantano);
reserva->agregarZona("bosque", bosque);
```

Este ajuste debe quedar agregado en la versión final de `EcoMision.cpp` para que el uso de la reserva también se evidencie durante la demostración.

---

## Relación con nuestro diagrama UML

El diseño del proyecto no salió completamente terminado desde el inicio. Primero planteamos las clases principales y después fuimos ajustando el UML a medida que avanzamos en el código.

En la versión inicial del diagrama aparecían las ideas principales:

- Una clase `EcoMision`.
- Una reserva.
- Un explorador.
- Zonas.
- Una clase abstracta para elementos interactivos.

En la versión intermedia ya se comenzaron a mostrar los elementos derivados, el manejo de la zona actual del explorador y la colección de elementos dentro de cada zona.

Finalmente, en el UML final se representan las clases y métodos que realmente quedaron en el código, incluyendo:

- Los métodos del explorador.
- La sobrecarga en `Zona`.
- El destino del `PortalRuta`.
- La relación entre el explorador y su zona actual.
- El uso de `unordered_map` en `Reserva`.

Los tres diagramas se encuentran en:

```text
docs/diseno.md
```

---

## Matriz de decisiones

Además del UML, elaboramos una matriz de decisiones para explicar por qué escogimos ciertas formas de organizar el programa.

Algunas de las decisiones más importantes fueron:

| Decisión | Elección realizada | Razón principal |
|---|---|---|
| Cómo guardar las zonas | `unordered_map<string, Zona*>` | Permite identificar y buscar zonas mediante códigos. |
| Cómo representar los elementos | Herencia desde `ElementoInteractivo` | Cada elemento comparte una base, pero se comporta diferente. |
| Cómo guardar elementos en una zona | `vector<ElementoInteractivo*>` | Permite almacenar distintos tipos de elementos en una misma zona. |
| Cómo ejecutar interacciones | Polimorfismo | Cada elemento responde por sí mismo al método `interactuar()`. |
| Cómo relacionar al explorador con su ubicación | `Zona* zonaActual` | Permite cambiar de zona sin copiar objetos completos. |
| Cómo mostrar la sobrecarga | Dos versiones de `interactuarConElemento()` | Se puede interactuar por índice o por nombre. |

La matriz completa se encuentra en la documentación del proyecto junto con el diseño.

---

## Estructura del repositorio

El repositorio está organizado en dos carpetas principales: una para el código fuente y otra para la documentación del proyecto.

```text
Proyecto_poo/
│
├── README.md
│
├── src/
│   ├── main.cpp
│   ├── EcoMision.h
│   ├── EcoMision.cpp
│   ├── Reserva.h
│   ├── Reserva.cpp
│   ├── Zona.h
│   ├── Zona.cpp
│   ├── Explorador.h
│   ├── Explorador.cpp
│   ├── ElementoInteractivo.h
│   ├── ElementoInteractivo.cpp
│   ├── AnimalHerido.h
│   ├── AnimalHerido.cpp
│   ├── PlantaMedicinal.h
│   ├── PlantaMedicinal.cpp
│   ├── PortalRuta.h
│   └── PortalRuta.cpp
│
└── docs/
    ├── diseno.md
    ├── bitacora-ia.md
    └── imagenes/
        ├── inicio-recorrido.png
        └── resultado-final.png
```

En la carpeta `src` se encuentra todo el código necesario para compilar y ejecutar el programa.

En la carpeta `docs` se encuentra la parte de diseño y reflexión del proyecto, incluyendo los diagramas UML, la matriz de decisiones y la bitácora sobre el uso de inteligencia artificial.

---

## Archivos principales

| Archivo | Para qué sirve |
|---|---|
| `main.cpp` | Es el punto de inicio del programa. Crea un objeto `EcoMision` y llama a `iniciar()`. |
| `EcoMision.h` / `EcoMision.cpp` | Coordinan toda la demostración del recorrido. |
| `Reserva.h` / `Reserva.cpp` | Permiten registrar y buscar zonas mediante códigos. |
| `Zona.h` / `Zona.cpp` | Manejan los espacios de la reserva y los elementos disponibles en cada uno. |
| `Explorador.h` / `Explorador.cpp` | Guardan la información y el estado del explorador. |
| `ElementoInteractivo.h` / `ElementoInteractivo.cpp` | Definen la clase abstracta que sirve como base para los elementos del entorno. |
| `AnimalHerido.h` / `AnimalHerido.cpp` | Representan la interacción de ayudar a un animal. |
| `PlantaMedicinal.h` / `PlantaMedicinal.cpp` | Representan la interacción de recuperar energía con una planta. |
| `PortalRuta.h` / `PortalRuta.cpp` | Representan la interacción de cambiar de zona mediante un portal. |

---

## Cómo compilar el proyecto

Para compilar el programa se necesita tener instalado un compilador de C++, como `g++`.

Desde la carpeta principal del repositorio, se puede ejecutar el siguiente comando:

```bash
g++ -std=c++11 src/*.cpp -o EcoMision
```

Este comando toma todos los archivos `.cpp` de la carpeta `src` y crea un ejecutable llamado `EcoMision`.

### Para ejecutar en Windows

```bash
.\EcoMision.exe
```

### Para ejecutar en Linux o macOS

```bash
./EcoMision
```

---

## Ejecución esperada

Cuando se ejecuta el proyecto, la consola debe mostrar una secuencia parecida a esta:

```text
Ecomision iniciada
Elemento 1. Animal Herido
Elemento 2. Planta Medicinal
Elemento 3. Portal de Ruta
Ayudaste a un animal herido
Has recogido una planta medicinal.
Cambiaste de zona
-- Iniciar Recorrido --
Explorador: Juan
Energia: 110
Puntaje Ambiental: 20
Zona Actual: Bosque
Elementos Disponibles:
Elemento 1. Planta Medicinal
```

Esta salida permite comprobar que el programa sí está funcionando, porque se puede ver que:

- El explorador encuentra diferentes elementos.
- Las interacciones producen cambios en su estado.
- La energía cambia durante el recorrido.
- El puntaje ambiental aumenta al ayudar al animal.
- El portal mueve al explorador hacia otra zona.

---

## Imágenes del proyecto funcionando

### Inicio del recorrido

En esta captura se puede observar el momento en que inicia EcoMisión y se muestran los elementos disponibles en el Pantano.

![Inicio del recorrido](docs/imagenes/inicio-recorrido.png)

### Resultado después de las interacciones

En esta captura se muestra el estado final del explorador, luego de ayudar al animal, recoger la planta medicinal y utilizar el portal hacia el Bosque.

![Resultado final del recorrido](docs/imagenes/resultado-final.png)

---

## Uso de inteligencia artificial durante el proyecto

Durante el desarrollo utilizamos inteligencia artificial como una herramienta de apoyo, principalmente para revisar si nuestro diseño realmente coincidía con el código que habíamos construido.

La usamos para revisar los diagramas UML, identificar métodos o relaciones que no habíamos representado bien y entender mejor algunas decisiones del programa, como el uso de:

```cpp
vector<ElementoInteractivo*> elementos;
```

y:

```cpp
virtual ~ElementoInteractivo() {};
```

También nos ayudó a detectar detalles que debíamos corregir antes de entregar, por ejemplo, que en el UML aparecía `PortalDeRuta`, pero en el código la clase realmente se llama `PortalRuta`.

No tomamos todas las recomendaciones de manera automática. Algunas ideas, como agregar más clases o más funcionalidades, decidimos no incluirlas porque preferimos entregar un proyecto que podamos explicar bien y no un programa más grande que después no sepamos sustentar completamente.

La reflexión más completa sobre este proceso se encuentra en:

```text
docs/bitacora-ia.md
```

---

## Ajustes finales que detectamos antes de entregar

Mientras revisábamos el proyecto, encontramos algunos detalles que debemos terminar de corregir para que el código, el UML y la documentación coincidan totalmente.

### Registrar las zonas dentro de la reserva

La clase `Reserva` ya tiene los métodos necesarios para guardar y buscar zonas mediante códigos, pero en la demostración principal todavía debemos registrar las zonas creadas.

En `EcoMision::iniciar()` debemos agregar:

```cpp
reserva->agregarZona("pantano", pantano);
reserva->agregarZona("bosque", bosque);
```

De esta manera, la reserva no queda solamente creada, sino que realmente administra las zonas de la experiencia.

### Revisar el método `ejecutarInteracciones()`

En el archivo `EcoMision.h` aparece declarado:

```cpp
void ejecutarInteracciones();
```

Sin embargo, en la implementación actual las interacciones se están ejecutando directamente dentro del método `iniciar()`.

Antes de la entrega debemos decidir si separamos esas acciones dentro de `ejecutarInteracciones()` o si retiramos ese método del diseño y del archivo `.h`. Lo importante es que el código final y el UML muestren exactamente lo mismo.

### Corregir mayúsculas en algunos `include`

También debemos revisar que los nombres incluidos en los archivos `.cpp` coincidan exactamente con los nombres reales de los archivos `.h`.

Por ejemplo, debe quedar:

```cpp
#include "EcoMision.h"
#include "Zona.h"
```

Esto evita errores si el proyecto se compila en un computador que sí distingue entre letras mayúsculas y minúsculas.

---

## Conclusión

EcoMisión fue un proyecto que nos permitió entender mejor cómo pasar de una idea general a un programa organizado por clases.

Al inicio solo teníamos claro que queríamos un explorador recorriendo zonas y encontrando elementos ambientales. Después, al comenzar a programar, tuvimos que tomar decisiones más concretas: cómo guardar las zonas, cómo hacer que distintos elementos reaccionaran diferente, cómo modificar el estado del explorador y cómo mostrar esos cambios en consola.

El programa final es sencillo, pero cumple una función importante dentro del aprendizaje, porque nos permitió aplicar conceptos de programación orientada a objetos en una situación concreta. En EcoMisión no todos los objetos hacen lo mismo: cada clase tiene su responsabilidad, cada interacción produce un cambio y todo el recorrido se organiza a partir de las relaciones entre los objetos.

Además, el proceso de revisar el UML, la matriz de decisiones y la bitácora nos ayudó a entender que programar no es solamente hacer que el código funcione, sino también poder explicar por qué se diseñó de esa manera y qué mejoraríamos antes de entregar.


