
CFLAGS = -g -Wall -Werror
CFILES = consist_hash_test.cpp

consist_hash_test: $(CFILES)
	$(CXX) $(CFLAGS) -o $@ $^

clean:
	rm -f consist_hash_test
