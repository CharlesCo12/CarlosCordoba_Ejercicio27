imagen.png: datos.dat plot.py
	python plot.py

%.dat : a.out
	./a.out

a.out: CarlosCordoba_Ejercicio27.cpp
	g++ CarlosCordoba_Ejercicio27.cpp

clear:
	rm -rf *.dat *.png *.out