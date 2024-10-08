uGit (ugit) 🛠️

uGit (ugit) es un simulador de un sistema de control de versiones que emula funcionalidades básicas de Git. Este proyecto está diseñado para proporcionar una experiencia práctica en la manipulación de estructuras de datos como arreglos y tablas hash en el lenguaje C.

## Generar documentación con Doxygen

Para generar la documentación del proyecto, sigue estos pasos:

1. Asegúrate de tener [Doxygen](http://www.doxygen.nl/download.html) instalado en tu sistema. Puedes instalarlo a través de tu gestor de paquetes o desde el sitio oficial.

2. Clona el repositorio:

  - git clone https://github.com/Diego0119/ugit.git

  - cd ugit

3. Ejecuta doxygen usando el archivo de configuración:

  - doxygen Doxyfile

4. Abre el archivo principal

  - open html/index.html

## Ejecutar el proyecto localmente

Para ejecutar el proyecto localmente debera seguir los siguientes pasos:

1. Asegurate de tener [gcc](https://gcc.gnu.org/onlinedocs/) instalado en tu dispositivo.

2. Ejecuta: make folders

3. Ahora ejecuta: make (con esto se crearan los ejecutables)

4. Finalmente para correr el programa se debe hacer un: make run

5. Para limpiar el proyecto se puede hacer un: make clean (si se hace el make clean se debera volver a hacer el make)



Objetivos 🎯

- Comprender el concepto de control de versiones y cómo los sistemas como Git gestionan diferentes versiones de un proyecto.
- Implementar y manipular estructuras de datos como arreglos y tablas hash para almacenar y gestionar eficientemente la información versionada.
- Desarrollar habilidades en programación en C, centrándose en el manejo de memoria, punteros, y eficiencia algorítmica.
- Simular operaciones de un sistema de control de versiones para obtener una comprensión más profunda de su funcionamiento interno.

Descripción del Proyecto 📚

uGit permite realizar operaciones básicas de control de versiones como:
- Agregar archivos
- Crear commits
- Ver el historial de versiones
- Cambiar entre versiones

Estas funcionalidades se implementan utilizando estructuras de datos básicas en C. La finalidad del proyecto es proporcionar a los estudiantes una experiencia práctica en la implementación de conceptos fundamentales de control de versiones.

Normativas de Codificación en C 🧩

-Consistencia en el estilo de código:
  - Usar nombres de variables y funciones descriptivos.
  - Mantener una indentación de 4 espacios por nivel.
-Modularidad:
  - Dividir el código en funciones pequeñas y manejables.
  - Evitar funciones que superen las 50 líneas de código.
-Documentación:
  - Identificar cada código con el programador.
  - Incluir comentarios claros y precisos.
  - Documentar cada función con propósito, parámetros de entrada, valores de retorno y posibles errores.
- Gestión de errores:
  - Implementar mecanismos robustos para capturar y manejar errores.
-Uso eficiente de memoria:
  - Evitar el uso innecesario de variables globales.
  - Liberar memoria dinámica cuando ya no sea necesaria.
-Optimización:
  - Escribir código optimizado en términos de tiempo y espacio.


