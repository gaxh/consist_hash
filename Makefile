
CFLAGS = -g -Wall -Werror
CFILES = consist_hash_test.cpp
CHEADERS = consist_hash.h

consist_hash_test: $(CFILES) $(CHEADERS)
	$(CXX) $(CFLAGS) -o $@ $(CFILES)

clean:
	rm -f consist_hash_test
