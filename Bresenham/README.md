### Grupo
Lucas Fernandes Lucena 2016023725

Karina Alves Torreão Villarim 2016024660

---

### Introdução
A primeira atividade da disciplina de computação tinha como objetivo a implementação do algorimo de Bresenham, este por sua vez traz uma forma de solucionar o problema de desenhar uma reta em uma tela. A tarefa propõe a ciação de uma função para pintar um pixel na tela, o desenho de uma reta e o desenho de um triangulo. Além disso, pede-se que ocorra a interpolação linear das cores durante a formação de retas.

---

### Estratégias
Antes de qualquer coisa, o essencial para o desenhdo de qualquer coisa é o posicionamento de um pixel na tela em uma determinada cor previamente setada. Com os slides apresentados em sala foi possível implementar tal função.

<p align="center">
	<br>
	<img src="./prints/putpixel.png"/ width=544px height=93px>
	<h5 align="center">Figura 1 - PutPixel()</h5>
	<br>
</p>

O código apresentado em sala aula apenas solucionava o problema quando a linha era desenhada de cima para baixo e quando o Δx era maior que o Δy. Com essa informação, transformamos todas as entradas possíveis para o caso que apresentava uma solução. Sendo assim, é necessário inverter os valores de x0 e x1 bem como y0 e y1 quando o trajeto da reta é de baixo para cima, também sendo necessário inverter as coordenadas x, y, como também os seus respectivos deltas quando o y crescer mais que o x no desenho da reta, isto é, quando o Δy for miaor que o Δx.

<p align="center">
	<br>
	<img src="./prints/octantes.png"/ width=363px height=334px>
	<h5 align="center">Figura 2 - Octantes</h5>
	<br>
</p>

Entretanto, mesmo após esses tratamentos, os 3º, 4º, 7º e 8º octantes ainda permaneciam sem solução, pois  um caso especial em que quando a coordenada x aumenta a y diminui e vice e versa. Então foi criado mais um if de tratamento em que quando o Δx multiplicado pelo Δy fosse negativo significa que a reta estava em um desses octantes. 

---

### Resultados
Após a compreensão tanto do problema quanto do código ficou mais tranquila a resolução da tarefa. Com o famoso de divisão e conquista, o problema se apresentou em problemas menores e mais fáceis. A maior dificuldade foi entender o algoritmo de Bresenham em si e assim criar várias estruturas condicionas para que a entrada fosse polída e pudesse se encaixar neste algoritmo. Acreditamos que o código poderia se apresentar de forma mais enxuta com menos if visto que qualquer redução de código feita será bem vista.

<p align="center">
	<br>
	<img src="./prints/pontos.png"/ width=412px height=449px>
	<h5 align="center">Figura 3 - Pontos</h5>
	<br>
</p>
<p align="center">
	<br>
	<img src="./prints/interpolar.png"/ width=924px height=266px>
	<h5 align="center">Figura 4 - Interpolate()</h5>
	<br>
</p>
<p align="center">
	<br>
	<img src="./prints/retas.png"/ width=412px height=449px>
	<h5 align="center">Figura 5 - Retas</h5>
	<br>
</p>
<p align="center">
	<br>
	<img src="./prints/drawtriangle.png"/ width=1018px height=89px>
	<h5 align="center">Figura 6 - DrawTriangle()</h5>
	<br>
</p>
<p align="center">
	<br>
	<img src="./prints/triangulo.png"/ width=412px height=449px>
	<h5 align="center">Figura 7 - Triangulo</h5>
	<br>
</p>
