ColoredPencils: Customer.o ColoredPencils.o
	g++ Customer.o ColoredPencils.o -o ColoredPencils

Customer.o: Customer.cpp Customer.h
	g++ -c Customer.cpp

ColoredPencils.o: ColoredPencils.cpp CartItem.h Customer.h History.h Product.h
	g++ -c ColoredPencils.cpp

clean:
	rm *.o ColoredPencils