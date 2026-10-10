# Atividade 02 - Botão

## Função
Acende o LED quando aperta o botão. 
Usa um resistor como resistor pullup externo

## Descrição e diagrama esquemático
- LED no pino 4, com resistor de 330Ω indo para o GND
- Botão no pino 21 ligado entre o pino e o GND e um resistor de 10kΩ ligado entre o pino e o 3V3. 
- `pinMode(21, INPUT)` — ativa o resistor interno
![Esquemático da atividade 02b](esquematico.svg)

## O que aprendi atividade 02 e 02b
- **Lógica contra intuitiva:** Com o pullup, o pino lê HIGH enquanto tá solto o botão e assim que aperta o botão, ele passa a receber 0 (LOW).

- **Debounce:** Fiz usando um switch do teclado e notei pouco ruído. Com um botão padrão, teria mais chance de haver em cada click. O debounce serve para cortar esse ruído, guardando o último estado estável (10ms) antes de considerar o botão apertado de fato.

- **Máquina de estados finitos:** Preciso ler mais disso, serve para manter um estado enquanto o loop acontece. É a base do debounce.

- **Pullup:** Serve para que a leitura seja um valor com o botão apertado e outro com o botão solto.

## Dificuldades
- Ler mais sobre máquina de estados finitos.