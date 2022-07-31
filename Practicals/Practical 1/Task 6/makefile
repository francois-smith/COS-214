output: User.o UserManager.o Snapshot.o AuditableSnapshot.o main.o
	g++ main.o User.o UserManager.o AuditableSnapshot.o Snapshot.o -o output

User.o: User.cpp User.h
	g++ -c User.cpp

UserManager.o: UserManager.cpp UserManager.h
	g++ -c UserManager.cpp

AuditableSnapshot.o: AuditableSnapshot.cpp AuditableSnapshot.h
	g++ -c AuditableSnapshot.cpp

Snapshot.o: Snapshot.cpp Snapshot.h
	g++ -c Snapshot.cpp

main.o: main.cpp
	g++ -c main.cpp

run:
	./output

clean:
	rm *.o output