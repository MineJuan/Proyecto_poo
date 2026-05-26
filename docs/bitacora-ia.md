
¿Para qué usaron IA genera va?

Usamos inteligencia artificial principalmente como una herramienta de apoyo para revisar y organizar mejor el proyecto. Al comienzo teníamos la idea general de EcoMisión y las clases principales, pero necesitábamos confirmar si la estructura que estábamos armando sí tenía sentido para los conceptos que pedía el taller, como herencia, polimorfismo, asociación, agregación, sobrecarga y el uso de unordered_map.

La IA nos sirvió para revisar el diagrama UML, comparar lo que habíamos diseñado con lo que finalmente quedó escrito en el código y detectar cosas que se nos podían pasar, como métodos que estaban en los archivos .h pero no se estaban mostrando en el diagrama, o relaciones entre clases que sí existían, pero que nosotros no habíamos representado claramente.

También la usamos para entender mejor algunas partes del código que sabíamos implementar, pero que todavía nos costaba explicar con seguridad. Por ejemplo, por qué Zona almacena un vector<ElementoInteractivo*>, por qué ElementoInteractivo debe ser una clase abstracta y por qué su destructor aparece como virtual. En ese sentido, la IA no fue simplemente para copiar código, sino para aterrizar mejor lo que estábamos haciendo y poderlo defender después.

¿Qué decisión de diseño revisaron con IA?
Una de las decisiones principales que revisamos con IA fue la forma en que las zonas iban a almacenar e interactuar con los elementos del recorrido. Nosotros teníamos clases distintas como AnimalHerido, PlantaMedicinal y PortalRuta, pero necesitábamos que una misma zona pudiera contener todos esos objetos sin tener un vector diferente para cada tipo de elemento.

Por eso revisamos la decisión de manejar en Zona un:

vector<ElementoInteractivo*> elementos;

Esta decisión permite que todos los elementos se guarden bajo la clase padre ElementoInteractivo, aunque cada uno tenga un comportamiento diferente cuando el explorador interactúa con él. Así, cuando se llama al método interactuar(), cada objeto responde según su propia clase. Por ejemplo, el animal aumenta el puntaje y consume energía, la planta recupera energía y el portal cambia de zona.


¿Qué sugerencia de IA aceptaron y por qué?


¿Qué sugerencia de IA corrigieron o rechazaron y por qué?


¿Qué parte del proyecto debe poder defender cada integrante?
