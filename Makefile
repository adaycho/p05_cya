client_p03_cya: client_p05.cc dfa.cc function.cc state.cc language.cc chain.cc alphabet.cc symbol.cc
	g++ -o client_p05 client_p05.cc dfa.cc function.cc state.cc language.cc chain.cc alphabet.cc symbol.cc

clean:
	rm -r *.txt client_p05
