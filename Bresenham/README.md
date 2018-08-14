### Grupo
Lucas Fernandes Lucena 2016023725

Karina Alves Torreão Villarim 2016024660

---

### Introdução
A primeira atividade da disciplina de computação tinha como objetivo a implementação do algorimo de Bresenham, este por sua vez traz uma forma de solucionar o problema de desenhar uma reta em uma tela. Além disso, pede-se que ocorra a interpolação linear das cores durante a formação da reta.

---

### Estratégias
O código apresentado em sala aula apenas solucionava o problema quando a linha era desenhada de cima para baixo e quando o Δx era maior que o Δy. Com essa informação, transformamos todas as entradas possíveis para o caso que apresentava uma solução. Sendo assim, é necessário inverter os valores de x0 e x1 bem como y0 e y1 quando o trajeto da reta é de baixo para cima, também sendo necessário inverter as coordenadas x, y, como também os seus respectivos deltas quando o y crescer mais que o x no desenho da reta, isto é, quando o Δy for miaor que o Δx.

<p align="center">
	<br>
	<img src="./prints/octantes.png"/ width=736px height=667px>
	<h5 align="center">Figura 1 - Octantes</h5>
	<br>
</p>

Entretanto, mesmo após esses tratamentos, os 3º, 4º, 7º e 8º octantes ainda permaneciam sem solução, pois  um caso especial em que quando a coordenada x aumenta a y diminui e vice e versa. Então foi criado mais um if de tratamento em que quando o Δx multiplicado pelo Δy fosse negativo significa que a reta estava em um desses octantes. 

---

### Resultados
Após a compreensão tanto do problema quanto do código ficou mais tranquila a resolução da tarefa. 

