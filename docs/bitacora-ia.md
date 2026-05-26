
# BITACORA-IA

----------------------------------------------------------------------------------------
*¿Para qué usaron IA genera va?*

Usamos inteligencia artificial principalmente como una herramienta de apoyo para revisar y organizar mejor el proyecto. Al comienzo teníamos la idea general de EcoMisión y las clases principales, pero necesitábamos confirmar si la estructura que estábamos armando sí tenía sentido para los conceptos que pedía el taller, como herencia, polimorfismo, asociación, agregación, sobrecarga y el uso de unordered_map.

La IA nos sirvió para revisar el diagrama UML, comparar lo que habíamos diseñado con lo que finalmente quedó escrito en el código y detectar cosas que se nos podían pasar, como métodos que estaban en los archivos .h pero no se estaban mostrando en el diagrama, o relaciones entre clases que sí existían, pero que nosotros no habíamos representado claramente.

También la usamos para entender mejor algunas partes del código que sabíamos implementar, pero que todavía nos costaba explicar con seguridad. Por ejemplo, por qué Zona almacena un vector<ElementoInteractivo*>, por qué ElementoInteractivo debe ser una clase abstracta y por qué su destructor aparece como virtual. En ese sentido, la IA no fue simplemente para copiar código, sino para aterrizar mejor lo que estábamos haciendo y poderlo defender después.

-----------------------------------------------------------------------------------------
*¿Qué decisión de diseño revisaron con IA?*

Una de las decisiones principales que revisamos con IA fue la forma en que las zonas iban a almacenar e interactuar con los elementos del recorrido. Nosotros teníamos clases distintas como AnimalHerido, PlantaMedicinal y PortalRuta, pero necesitábamos que una misma zona pudiera contener todos esos objetos sin tener un vector diferente para cada tipo de elemento.

Por eso revisamos la decisión de manejar en Zona un:

vector<ElementoInteractivo*> elementos;

Esta decisión permite que todos los elementos se guarden bajo la clase padre ElementoInteractivo, aunque cada uno tenga un comportamiento diferente cuando el explorador interactúa con él. Así, cuando se llama al método interactuar(), cada objeto responde según su propia clase. Por ejemplo, el animal aumenta el puntaje y consume energía, la planta recupera energía y el portal cambia de zona.

También revisamos el uso de:

unordered_map<string, Zona*> zonas;

En la clase Reserva. Esta decisión era importante porque el enunciado pedía que las zonas se registraran mediante códigos. Con el unordered_map, la reserva puede relacionar códigos como "pantano" o "bosque" con sus respectivos objetos de tipo Zona.

Esta revisión nos ayudó a entender que esas decisiones no estaban puestas solo porque el taller las pedía, sino porque realmente hacen que el programa quede más ordenado y tenga sentido desde programación orientada a objetos.

---------------------------------------------------------------------------------------
*¿Qué sugerencia de IA aceptaron y por qué?*

Una sugerencia que aceptamos fue ajustar el UML final para que coincidiera realmente con el código fuente que ya teníamos. En una versión anterior del diagrama faltaban varios métodos, no estaban completas algunas relaciones y aparecía la clase PortalDeRuta, cuando en el código la clase que realmente implementamos se llama PortalRuta.

Aceptamos esa corrección porque nos dimos cuenta de que no tenía sentido entregar un diagrama que dijera una cosa y un código que mostrara otra. Por ejemplo, en el código PortalRuta tiene un atributo:

Zona* destino;

porque necesita saber hacia qué zona va a mover al explorador. Entonces, en el UML final también debía aparecer la relación entre PortalRuta y Zona.

Otra sugerencia que aceptamos fue mostrar mejor los métodos de la clase Explorador, como:

getEnergia();
getPuntajeAmbiental();
getZonaActual();
aumentarPuntaje();

Estos métodos sí están implementados y son necesarios para mostrar el avance del jugador y permitir que los elementos interactivos modifiquen su estado. Al agregarlos al UML, el diseño quedó mucho más conectado con el funcionamiento real del programa.

----------------------------------------------------------------------------------------
*¿Qué sugerencia de IA corrigieron o rechazaron y por qué?*

No tomamos todas las sugerencias de IA como algo automático. Una recomendación que revisamos con cuidado fue la de agregar más clases o más funcionalidades para hacer el proyecto más amplio, como nuevos tipos de elementos ambientales o más zonas. Aunque podían ser ideas buenas, decidimos no meterlas por ahora porque el programa ya cumplía con la estructura principal solicitada y agregar cosas a última hora podía volver el código más difícil de explicar o dejar funciones incompletas.

También corregimos la manera en que se estaba mostrando la evolución de los diagramas UML. Si dejábamos el UML intermedio muy básico y el final demasiado completo, parecía que el proyecto hubiera cambiado de un momento a otro sin mostrar un proceso real. Por eso preferimos reconstruir el UML intermedio para que ya mostrara las clases derivadas, las relaciones principales y el almacenamiento de elementos, pero dejando para el UML final los métodos y ajustes que representan el cierre completo del código.

Además, la IA nos señaló que en EcoMision está declarado el método:

void ejecutarInteracciones();

pero todavía no aparece implementado en el archivo .cpp. Esa observación la tomamos como una alerta, no como algo para ignorar. Antes de entregar debemos decidir si realmente lo implementamos o si lo eliminamos de la declaración, porque no queremos mostrar en el diseño algo que después no podamos explicar o ejecutar.

De la misma forma, se nos recomendó registrar las zonas dentro de la reserva usando agregarZona(). Esa recomendación sí tiene sentido, pero todavía depende de que nosotros la implementemos y probemos correctamente antes de afirmar que ya está terminada. Preferimos dejar claro qué cosas ya están funcionando y cuáles todavía tenemos que ajustar.

-----------------------------------------------------------------------------------------
*¿Qué parte del proyecto debe poder defender cada integrante?*

Aunque entre nosotros se pueden repartir algunas partes para organizar mejor la sustentación, consideramos que los tres integrantes debemos conocer el funcionamiento general del proyecto. La profesora puede preguntarle a cualquiera por el diseño, el código o alguna modificación en vivo, entonces no sería buena idea que cada uno solo entendiera una clase y ya.

*Juan Alejandro Valencia*

Debe poder explicar principalmente la clase EcoMision y la forma en que se coordina todo el programa desde main.cpp. También debe entender cómo se crean las zonas, cómo se ubica inicialmente al explorador, cómo se ejecutan las interacciones y cómo se muestra el recorrido final. Además, debe poder explicar por qué EcoMision funciona como la clase que reúne y controla los componentes principales del prototipo.

*Sofía Paredes*

Debe poder defender las clases Reserva y Zona. En especial, debe explicar por qué se utiliza unordered_map<string, Zona*> para registrar y buscar zonas mediante códigos, y por qué Zona utiliza un vector<ElementoInteractivo*> para almacenar diferentes elementos. También debe poder explicar la sobrecarga del método interactuarConElemento(), ya que se puede interactuar buscando por índice o por nombre.

*Natalia Toro*

Debe poder explicar la clase Explorador, la clase abstracta ElementoInteractivo y las clases derivadas AnimalHerido, PlantaMedicinal y PortalRuta. Debe tener claro cómo cada elemento modifica de forma diferente el estado del explorador y cómo eso evidencia herencia, sobreescritura y polimorfismo. También debe poder explicar por qué PortalRuta necesita conocer una zona de destino.

----------------------------------------------------------------------------------------
*Responsabilidad de los tres integrantes*

Independientemente de esta división, los tres debemos poder explicar:
-Qué hace el programa en general.
-Cuáles son los cuatro pilares de POO que aparecen en el proyecto.
-Qué relaciones existen entre las clases.
-Dónde aparece la sobrecarga.
-Dónde aparece el polimorfismo.
-Por qué se usó unordered_map.
-Qué cambios hicimos con ayuda de IA.
-Qué parte entendimos, ajustamos o decidimos no implementar todavía.
