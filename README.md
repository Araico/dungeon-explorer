Descripción del Proyecto:


Dungeon Explorer es un proyecto integral de estructuras de datos diseñado para mejorar la experiencia inmersiva de los juegos de rol de Dungeons and Dragons (D&D). Inspirándose en el intrincado mundo de D&D, este proyecto tiene como objetivo crear un sistema de base de datos versátil y eficiente que organice, gestione y recupere información relacionada con el juego, asegurando una experiencia de juego perfecta tanto para los jugadores como para los Dungeon Masters.


Características clave:


Códice de criaturas:

Desarrolle un depósito dinámico de criaturas y monstruos que se encuentran en el universo D&D. Utiliza una lista ligada para cargar un inventario de monstruos, lo que facilita el acceso rápido a los Dungeon Masters durante los encuentros. Utiliza el archivo: monsters.csv, los datos de cada criatura son:

name: name of the creature
cr: challenge rating, how difficult is the creature to defeat
type: type of creature
size: size of creature, how much space it occupies
ac: armor class, how difficult the creature is to hit
hp: hit points, how much damage the creature must take before being defeated
align: gives a clue to the default behavior of the creature

Crea el tipo de dato abstracto para representar a un monstruo. Y una lista ligada para tener un códice de monstruos que pueden salir a atacarte de un calabozo.



Repositorio de libros de hechizos y habilidades:

window donde muestra el inventario de hechizos y habilidades del jugador y el jugador puede agregar las que quiera de una lista   


Cree una estructura de datos para administrar hechizos y habilidades, lo que permite a los jugadores personalizar y mantener los libros de hechizos y habilidades únicas de sus personajes. Implemente un mecanismo eficiente de búsqueda y filtrado para una selección rápida de hechizos durante el juego. Investiga 15 hechizos y habilidades qué puedes utilizar. Crea el tipo de dato abstracto para representar un hechizo y/o habilidad. Deben ser cargadas en una lista de ligada para su acceso.


Mapa de calabozos y seguimiento de ubicación:

Utilice estructuras de datos basadas en una lista ligada para representar el mundo del juego y sus ubicaciones son una serie de calabozos interconectados de manera secuencial. 

El número de calabozos interconectados tiene un máximo de 20 calabozos. Cada calabozo debe tener un monstruo que se selecciona aleatoriamente del códice de criaturas.


Jugador:

Debes tener un tipo de dato abstracto que representa al jugador. Un jugador cuenta con un nivel de hp (hit points) que inicia en 10 y se incrementa al ganar una batalla en un calabozo, una raza (elf, human or dwarf), nombre, lp (life points) que decrecen o se incrementan con un hechizo, inicia en 100 puntos y puede llegar a 999 y una lista de monstruos que ha derrotado.


Generador de encuentros aleatorios:

Implemente un generador versátil de encuentros aleatorios utilizando el siguiente sistema:

Carga el códice de criaturas.
Carga el mapa de calabozos, asignando un monstruo aleatorio en cada calabozo.
Cargar tu lista de mínimo 15 hechizos y habilidades.
El jugador tiene 100 puntos que se pueden ir descontando con el ataque de una criatura y se puede incrementar con una magia específica.
El algoritmo a seguir es:
Mientras el jugador tenga vida:
Lanzar un dado de 20 caras para llegar a un calabozo.
Sí la criatura del calabozo está muerta (según su hp), vuelve a tirar el dado.
Sino, si la criatura se encuentra viva, entrarás en combate.
Mientras el jugador o la criatura sigan vivos:
Ataca el monstruo, tira un dado de 10 caras para ver cuánto daño te hace.
El jugador ataca, tira un dato de 10 caras para simular cuánto daño le haces.
Si el jugador sale vivo, guarda al monstruo que ha derrotado.
El jugador puede lanzar un dado de 8 caras para recuperar su life points (lf).
El juego termina cuando el jugador muere.
Al terminar debe mostrar una lista ordenada, por nombre, de los monstruos que derrotó. Su nombre, raza y cuantos calabozos conquistó.

Tu solución:

Implementa tu solución a la simulación del juego de D&D. Recuerda aplicar todos los conceptos revisados en clase. 


Entregables:

Código Fuente.
Diagramas de clases.
Análisis de la complejidad de cada función y la complejidad total.


Beneficios:


Jugabilidad mejorada: el Compendio de Dungeon Explorer mejora la experiencia de D&D al proporcionar un acceso rápido y fácil a la información de los personajes, perfiles de criaturas, gestión de inventario y más.


Eficiencia del tiempo: Dungeon Masters puede administrar sin problemas encuentros, misiones y construcción de mundos, reduciendo el tiempo de preparación y asegurando un entorno de juego dinámico.


Narración inmersiva: las estructuras de datos organizadas del proyecto facilitan la narración coherente, lo que permite a Dungeon Masters tejer narrativas y aventuras intrincadas.


Interfaz fácil de usar: una interfaz de usuario intuitiva garantiza que los jugadores y Dungeon Masters puedan interactuar sin esfuerzo con el sistema de base de datos, incluso durante un juego de ritmo rápido.


Personalización: los jugadores pueden adaptar sus personajes, hechizos y habilidades con facilidad, promoviendo la creatividad y el pensamiento estratégico.


El Compendio de Dungeon Explorer está destinado a convertirse en una herramienta invaluable tanto para los recién llegados como para los veteranos de Dungeons and Dragons, mejorando la experiencia de juego de rol de mesa y cimentando su lugar como un compañero esencial para todos los aventureros en los reinos de la fantasía.