OUTDIR=dist
CFLAGS= -O2

.PHONY: default clean

default: test clean

$(OUTDIR):
	@mkdir -p $(OUTDIR)

test: $(OUTDIR) $(OUTDIR)/hamming.o $(OUTDIR)/main.o
	gcc $(CFLAGS) $(OUTDIR)/hamming.o $(OUTDIR)/main.o -o test
	./test

$(OUTDIR)/hamming.o: hamming.c
	gcc $(CFLAGS) -o $(OUTDIR)/hamming.o -c $^

$(OUTDIR)/main.o: main.c
	gcc $(CFLAGS) -o $(OUTDIR)/main.o -c $^ 

clean:
	@rm -f test
	@rm -rf $(OUTDIR)
