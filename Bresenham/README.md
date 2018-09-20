# Menu

* [Atividade 1](#bresenham)
* [Atividade 2](#pipeline-gráfico)

### Grupo
Lucas Fernandes Lucena 2016023725

Karina Alves Torreão Villarim 2016024660

---

## Bresenham

---

### Introdução
A primeira atividade da disciplina de computação gráfica tinha como principal objetivo a implementação do algorimo de Bresenham, este por sua vez traz uma forma de solucionar o problema de desenhar uma reta em uma tela pixelada. A tarefa ainda propõe a criação de uma função para pintar um pixel na tela, o desenho de uma reta e o desenho de um triangulo. Além disso, pede-se que ocorra a interpolação linear das cores durante a formação de retas.

---

### Desenvolvimento
Antes de qualquer coisa, o essencial para o desenhdo de qualquer coisa é o posicionamento de um pixel na tela e que ele seja colorido com uma cor previamente determinada. Com os slides apresentados em sala foi possível implementar tal função.

<p align="center">
	<br>
	<img src="./prints/putpixel.png"/ width=544px height=93px>
	<h5 align="center">Figura 1 - PutPixel()</h5>
	<br>
</p>

Já em relação ao desenho de retas através da implementação do algoritmo de Bresenham, o código apresentado em sala aula apenas solucionava o problema quando a linha era desenhada de cima para baixo e quando o Δx era maior que o Δy, nos 1º, 2º, 5º e 6º octantes. Com essa informação, transformamos todas as entradas possíveis para o caso que apresenta uma solução com o código dado. Sendo assim, é necessário inverter os valores de x0 e x1 bem como y0 e y1 quando o trajeto da reta é de baixo para cima, também sendo necessário inverter as coordenadas x, y, como também os seus respectivos deltas quando o y crescer mais que o x no desenho da reta, isto é, quando o Δy for miaor que o Δx.

<p align="center">
	<br>
	<img src="./prints/octantes.png"/ width=363px height=334px>
	<h5 align="center">Figura 2 - Octantes</h5>
	<br>
</p>

Entretanto, mesmo após esses tratamentos, os 3º, 4º, 7º e 8º octantes ainda permaneciam sem solução, pois  um caso especial em que quando a coordenada x aumenta a y diminui e vice e versa. Então foi criado mais um if de tratamento em que quando o Δx multiplicado pelo Δy fosse negativo significa que a reta estava em um desses octantes. 

A interpolação linear das cores foi solucionada com uma simples lógica matemática em que a posição atual da reta é dividida pelo tamanho total gerando assim números de 0 a 1 chamado no código de "t"  e esse número é multiplicado pela cor final e (1-t) é multiplicado pela cor inicial. Dessa forma, ocorre a transição da cor inicial para a final. 

<p align="center">
	<br>
	<img src="./prints/interpolar.png"/ width=924px height=266px>
	<h5 align="center">Figura 3 - Interpolate()</h5>
	<br>
</p>

A última etapa da tarefa era o desenho de o um triângulo que é só chamar a função de desenhar linha três vezes.
<p align="center">
	<br>
	<img src="./prints/drawtriangle.png"/ width=1018px height=89px>
	<h5 align="center">Figura 4 - DrawTriangle()</h5>
	<br>
</p>

---

### Resultados
Após a compreensão tanto do problema quanto do código ficou mais tranquila a resolução da tarefa. Com o famoso de divisão e conquista, o problema se apresentou em problemas menores e mais fáceis. A maior dificuldade foi entender o algoritmo de Bresenham em si e assim criar várias estruturas condicionas para que a entrada fosse polída e pudesse se encaixar neste algoritmo. Acreditamos que o código poderia se apresentar de forma mais enxuta com menos if visto que qualquer redução de código feita será bem vista.

<p align="center">
	<br>
	<img src="./prints/pontos.png"/ width=412px height=449px>
	<h5 align="center">Figura 5 - Pontos</h5>
	<br>
</p>

<p align="center">
	<br>
	<img src="./prints/retas.png"/ width=412px height=449px>
	<h5 align="center">Figura 6 - Retas</h5>
	<br>
</p>

<p align="center">
	<br>
	<img src="./prints/triangulo.png"/ width=412px height=449px>
	<h5 align="center">Figura 7 - Triangulo</h5>
	<br>
</p>

---

### Referências

https://rosettacode.org/wiki/Bitmap/Bresenham%27s_line_algorithm

https://en.wikipedia.org/wiki/Rasterisation
<br>
<br>
---

## Pipeline Gráfico

O Pipeline Gráfico é caracterizado por um conjunto de passos que transformam os vértices de um objeto, através de cálculos algébricos, de modo que ele possa ser representado no espaço de tela com uma representação próxima à realidade, ou seja, uma cena em 3D é transformada em 2D. 

 

Figura 1: Estrutura do Pipeline Gráfico 

---

### Espaço do Objeto/Espaço do Universo 

Inicialmente, cada objeto é representado de forma independente, cada um com seu designado eixo. Para juntarmos todos os objetos em uma cena conjunta, é necessário transformá-los para o Espaço do Universo, em que todas as peças serão padronizadas e inseridas em um único eixo. 

 

Figura 2: Representação da transformação do Espaço do Objeto para o Universo 

#### Matriz Model 

A Matriz Model (modelagem) compõe todas as transformações geométricas desejadas para um determinado objeto. Ela pode ser composta de rotações, translações, escalas, shears. Se não é necessário nenhum tipo de transformação, a Matriz Model é a identidade, não alterando nenhuma coordenada do objeto em questão. Neste caso, a Matriz Model foi a própria identidade. 

 

 

 

 

 

--- 

### Espaço do Universo/Espaço da Câmera 

O Espaço da Câmera é caracterizado por eixos de coordenadas, em que a câmera está posicionada na origem e olhando para o sentido negativo do eixo z. A transformação do Espaço do Universo para o da Câmera representa uma mudança de sistemas de coordenadas que irá levar os vértices do objeto para o sistema de coordenadas definido pela base da câmera, este processo é denominado “mudança de base”. 

 

Figura 3: Representação da transformação do Espaço do Universo para o da Câmera 

 

#### Matriz View 

Esse processo de mudança de base é montado na Matriz View. Com os objetos no Espaço do Universo, precisamos definir a posição da câmera no espaço através dos vetores: Posição da Câmera, Direção da Câmera (Look At - Posição da Câmera), Up. 

 

Figura 4: Cálculo dos eixos do sistema de coordenadas da câmera 

 

 

                          

Figura 5: Matriz View 

 

Figura 6: Código da construção da Matriz View 

--- 

### Espaço da Câmera/Espaço de Recorte/Espaço Canônico 

Multiplicando os vértices pela Matriz de Projeção, teremos o objeto agora no Espaço de Recorte. Dependendo da matriz em questão, podemos obter dois tipos de projeção, perspectiva, que permite uma sensação de profundidade, e ortogonal, que preserva o paralelismo das retas. Nesse caso, utilizaremos uma matriz mais simples, que oferece uma projeção ortogonal do objeto. Após a multiplicação, a coordenada “w” será provavelmente diferente de 1. 

 

Figura 7: Tipos de perspectivas 

 

 

Figura 8: Matriz de Projeção Simples 

 

... 

Figura 9: Código da Matriz de Projeção 

 

A transformação para o Espaço Canônico não necessita de uma matriz como nas transformações anteriores. A sua conversão é realizada através da homogeneização da coordenada “w” (coordenada homogênea), ou seja, é feita uma divisão de todas as coordenadas do vetor por “w”, para que esta volte a ser 1, gerando um cubo quem contém os objetos que serão visualizados no Espaço de Tela. 

Não sei se precisa do código se quiser colocar bota aí 

Figura 10 (?) 

---

### Espaço Canônico/Espaço de Tela 

No Espaço Canônico é garantido que todos os vértices da cena visível, dentro do cubo gerado, possuem os valores de suas coordenadas entre -1 e 1. 

 

 

Figura 11: Representação da transformação do Espaço Canônico para o da Tela 

 

#### Matriz ViewPort 

Para levarmos os vértices para o Espaço de Tela é necessário fazermos algumas modificações. Como visto na imagem acima, o eixo “y” da tela cresce para baixo, o inverso de um sistema de coordenadas comum, então precisamos de uma matriz que inverta o sentido deste eixo. Numa tela comum os pixels são numerados de 0 a 511, então devemos escalar os valores de “x” e “y”, que variam de –1 até 1, para 0 até 511, multiplicando por outra matriz. Por último, como o cubo do Espaço Canônico está centrado na origem do seu sistema de coordenada, devemos transladá-lo para o centro da tela utilizando uma matriz de translação. 

 

 

Figura 11: Matriz ViewPort 

 

... 

Figura 12: Código 

 

### Dificuldades e Conclusão
