final:	main.o Character.o Timmy.o Harold.o Dragon.o Borc.o Dorc.o Porc.o GameControl.o Control.o View.o Medic.o ExtraStrength.o Chaser.o Armour.o
	g++ -Wall -o final main.o Character.o Timmy.o Harold.o Dragon.o Borc.o Dorc.o Porc.o GameControl.o Control.o View.o Medic.o ExtraStrength.o Chaser.o Armour.o

main.o:	main.cc Control.h Display.h
	g++ -c main.cc

Character.o: Character.h Character.cc
	g++ -c Character.cc

Timmy.o: Timmy.h Timmy.cc Character.h
	g++ -c Timmy.cc

Harold.o: Harold.h Harold.cc Character.h
	g++ -c Harold.cc

Dragon.o: Dragon.h Dragon.cc Character.h
	g++ -c Dragon.cc

Borc.o: Borc.h Borc.cc Character.h
	g++ -c Borc.cc

Dorc.o: Dorc.h Dorc.cc Character.h
	g++ -c Dorc.cc

Porc.o: Porc.h Porc.cc Character.h
	g++ -c Porc.cc

Medic.o: Medic.h Medic.cc Character.h
	g++ -c Medic.cc

ExtraStrength.o: ExtraStrength.h ExtraStrength.cc Character.h
	g++ -c ExtraStrength.cc

Armour.o: Armour.h Armour.cc Character.h
	g++ -c Armour.cc

Chaser.o: Chaser.h Chaser.cc Character.h
	g++ -c Chaser.cc

GameControl.o: GameControl.h GameControl.cc Character.h random.cc
	g++ -c GameControl.cc

Control.o: Control.h Control.cc GameControl.h
	g++ -c Control.cc

View.o: View.h View.cc
	g++ -c View.cc

clean:
	rm -f *.o final
