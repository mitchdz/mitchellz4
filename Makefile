CC=gcc

mlz4: mitchellz4.c
	$(CC) $< -o $@

test: mlz4
	echo "Hello world" > test.txt
	./mlz4 -i test.txt -o out.txt
