all: server

clean:
	@rm -rf bin/*.o
	@rm -rf bin/server

server: bin/main.o bin/httpd.o bin/utils.o bin/router.o
	gcc -o bin/server $^ -lsqlite3

bin/main.o: src/main.c src/httpd.h
	gcc -c -o bin/main.o src/main.c -lsqlite3

bin/httpd.o: src/httpd.c src/httpd.h
	gcc -c -o bin/httpd.o src/httpd.c -lsqlite3 

bin/utils.o: src/utils.c src/utils.h
	gcc -c -o bin/utils.o src/utils.c -lsqlite3 

bin/router.o: src/router.c src/router.h
	gcc -c -o bin/router.o src/router.c -lsqlite3 

