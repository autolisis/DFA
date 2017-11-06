%.cc.out: %.cc %.hh
	g++ --std=c++11 -g -o $@ $<
%.cc.out: %.cc
	g++ --std=c++11 -g -o $@ $<
%.c.out: %.c
	gcc -g -o $@ $< -lrt -lreadline -pthread
clean:
	rm -rf *.out
%.py.out: %.py
	cp $< $@
	chmod +x $@
%.pl.out: %.pl
	cp $< $@
	chmod +x $@
