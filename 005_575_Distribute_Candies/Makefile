TARGETS = Test

all: $(TARGETS)

%.o: %.cpp
	g++-7.1.0 $^ -c -o $@

Test: 575.o
	g++-7.1.0 $^ -o $@

clean::
	rm -fv $(TARGETS) *~ *.o