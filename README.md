# 7542 - Taller de Programación

### 2do Cuatrimestre 2018

## TP2: Simulador de cache

* #### compilar desde src/: make tp

* #### correr desde src/: ./tp &lt;config-file&gt; [<cpu-NN.bin>]
  
El objetivo es simular accesos concurrentes por parte de cada CPU hacia una única instancia de memoria caché.
  
* ### Formato config-file:

Este archivo provee la configuración de la memoria caché a ser accedida de manera concurrente por las **n** CPU's representadas por los archivos cpu-NN.bin

```
vendor_id=[vendor]
model name=[model]
cpu MHz=[frec]
cache type=[direct|associative-lru|associative-fifo]
cache size=<2^n>
line size=<2^m>
debug=[true|false]
```
* ### Formato cpu-NN.bin:

Cada archivo contiene accesos a distintas posiciones de memoria que intercepterá la caché.
En el caso que un archivo contenga una dirección no alineada a 32 bits, el caché abortará la ejecución de tal CPU.

El formato serán direcciones en hexadecimal de la siguiente forma:

```
0x########
```
