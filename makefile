FLAGS = -O2 -c -nostdlib
FINAL = -O2 -pedantic -Wall
EXTRA = -pthread -lcrypto -lssl

RELOC = main.o fsop.o hash.o work.o util.o


#	output target
#	#	#	#	#	#	#	#	#	#	#

output: ${RELOC}
	g++ ${FINAL} ${RELOC} -o output ${EXTRA}
	rm -rf *.o


#	linkable targets
#	#	#	#	#	#	#	#	#	#	#

main.o: main.hpp main.cpp
	g++ ${FLAGS} main.cpp -o main.o

fsop.o: inc/fsop.hpp src/fsop.cpp
	g++ ${FLAGS} src/fsop.cpp -o fsop.o

hash.o: inc/hash.hpp src/hash.cpp
	g++ ${FLAGS} src/hash.cpp -o hash.o

work.o: inc/work.hpp src/work.cpp
	g++ ${FLAGS} src/work.cpp -o work.o

util.o: inc/util.hpp src/util.cpp
	g++ ${FLAGS} src/util.cpp -o util.o


#	util
#	#	#	#	#	#	#	#	#	#	#

clean:
	rm -rf *.o

clear:
	rm -rf *.o output
