OPCIONES = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra  -Wno-sign-compare -std=c++11

program.exe: main.o user.o users.o problem.o problems.o course.o courses.o session.o sessions.o
  g++ -o program.exe main.o user.o users.o problem.o problems.o course.o courses.o session.o sessions.o

program.o: main.cc course.hh commands.hh ... (dependencias de program.cc, todos ficheros de #include)
  g++ -c program.cc $(OPCIONES)

Clase1.o: Clase1.cc Clase1.hh Clase2.hh Clase2.o Clase3.hh Clase3.o ... (dependencias de Clase1.cc, todos ficheros de #include)
  g++ -c Clase1.cc $(OPCIONES)


Clase2.o: Clase2.cc Clase2.hh Clase3.hh Clase3.o ... (dependencias de Clase2.cc, todos ficheros de #include)
  g++ -c Clase2.cc $(OPCIONES)

<lo mismo para el resto de clases>

clean:
  rm -f *.o
  rm -f *.exe

program.tar: Makefile Doxyfile program.cc Clase1.cc Clase1.hh Clase2.cc Clase2.hh Clase3.cc Clase3.hh ... (todos ficheros .cc y .hh del vuestro programa)
   tar -cvf program.tar Makefile Doxyfile program.cc Clase1.cc Clase1.hh Clase2.cc Clase2.hh Clase3.cc Clase3.hh ... (todos ficheros .cc y .hh del vuestro programa)
