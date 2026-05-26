#Inicial

```mermaid
classDiagram 

    class EcoMision {
        - Reserva* reserva
        - Explorador* explorador
        + iniciar()
    }

    class Reserva {
        - unordered_map<string, Zona*> zonas
        + agregarZona(string, Zona*)
    }

    class Zona {
        - string nombre
        - vector<ElementoInteractivo*> elementos
        + agregarElemento(ElementoInteractivo*)
    }

    class Explorador {
        - string nombre
        - int energia
        - int puntajeAmbiental
        + cambiarZona(Zona*)
    }

    class ElementoInteractivo {
        <<abstract>>
        + interactuar(Explorador*)
    }

    ElementoInteractivo <|-- AnimalHerido
    ElementoInteractivo <|-- PlantaMedicinal
    ElementoInteractivo <|-- PortalRuta

    EcoMision --> Reserva
    EcoMision --> Explorador
    Reserva --> Zona
    Zona --> ElementoInteractivo
```

#Intermedio

```mermaid
classDiagram

    class EcoMision {
        - Reserva* reserva
        - Explorador* explorador
        + EcoMision()
        + void iniciar()
        + void mostrarRecorrido()
    }

    class Reserva {
        - unordered_map~string, Zona*~ zonas
        + Reserva()
        + void agregarZona(string codigo, Zona* zona)
        + void mostrarZonas()
    }

    class Zona {
        - string nombre
        - vector~ElementoInteractivo*~ elementos
        + Zona(string nombre)
        + void agregarElemento(ElementoInteractivo* elemento)
        + void mostrarElementos()
        + void interactuarConElemento(int indice, Explorador* explorador)
    }

    class Explorador {
        - string nombre
        - int energia
        - int puntajeAmbiental
        - Zona* zonaActual
        + Explorador(string nombre)
        + void cambiarZona(Zona* nuevaZona)
        + void modificarEnergia(int valor)
    }

    class ElementoInteractivo {
        <<abstract>>
        # string nombre
        + ElementoInteractivo(string nombre)
        + void interactuar(Explorador* explorador)*
        + string getNombre()
        + ~ElementoInteractivo()
    }

    class AnimalHerido {
        + AnimalHerido()
        + void interactuar(Explorador* explorador)
    }

    class PlantaMedicinal {
        + PlantaMedicinal()
        + void interactuar(Explorador* explorador)
    }

    class PortalRuta {
        - Zona* destino
        + PortalRuta(Zona* destino)
        + void interactuar(Explorador* explorador)
    }

    EcoMision *-- Reserva 
    EcoMision *-- Explorador : crea y controla

    Reserva o-- Zona : registra zonas
    Zona o-- ElementoInteractivo : contiene

    Explorador --> Zona 
    PortalRuta --> Zona : destino

    ElementoInteractivo <|-- AnimalHerido
    ElementoInteractivo <|-- PlantaMedicinal
    ElementoInteractivo <|-- PortalRuta

    ElementoInteractivo ..> Explorador 
    Zona ..> Explorador 
```

#Final

```mermaid
classDiagram

    class EcoMision {
        - Reserva* reserva
        - Explorador* explorador
        + EcoMision()
        + void iniciar()
        + void mostrarRecorrido()
        + void ejecutarInteracciones()
    }

    class Reserva {
        - unordered_map~string, Zona*~ zonas
        + Reserva()
        + void agregarZona(string codigo, Zona* zona)
        + Zona* buscarZona(string codigoZona)
        + void mostrarZonas()
    }

    class Zona {
        - string nombre
        - vector~ElementoInteractivo*~ elementos
        + Zona(string nombre)
        + void agregarElemento(ElementoInteractivo* elemento)
        + void mostrarElementos()
        + void interactuarConElemento(int indice, Explorador* explorador)
        + void interactuarConElemento(string nombre, Explorador* explorador)
        + string getNombre()
    }

    class Explorador {
        - string nombre
        - int energia
        - int puntajeAmbiental
        - Zona* zonaActual
        + Explorador(string nombre)
        + void cambiarZona(Zona* nuevaZona)
        + void modificarEnergia(int valor)
        + void aumentarPuntaje(int puntos)
        + string getNombre()
        + int getEnergia()
        + int getPuntajeAmbiental()
        + Zona* getZonaActual()
    }

    class ElementoInteractivo {
        <<abstract>>
        # string nombre
        + ElementoInteractivo(string nombre)
        + void interactuar(Explorador* explorador)*
        + string getNombre()
        + ~ElementoInteractivo()
    }

    class AnimalHerido {
        + AnimalHerido()
        + void interactuar(Explorador* explorador)
    }

    class PlantaMedicinal {
        + PlantaMedicinal()
        + void interactuar(Explorador* explorador)
    }

    class PortalRuta {
        - Zona* destino
        + PortalRuta(Zona* destino)
        + void interactuar(Explorador* explorador)
    }

    EcoMision *-- Reserva : coordina
    EcoMision *-- Explorador : crea y controla
    EcoMision ..> Zona : configura recorrido

    Reserva o-- Zona : registra por codigo
    Zona o-- ElementoInteractivo : contiene

    Explorador --> Zona : zonaActual
    PortalRuta --> Zona : destino

    ElementoInteractivo <|-- AnimalHerido
    ElementoInteractivo <|-- PlantaMedicinal
    ElementoInteractivo <|-- PortalRuta

    ElementoInteractivo ..> Explorador : modifica estado
    Zona ..> Explorador : ejecuta interaccion
```
