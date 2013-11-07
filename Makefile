install:
	@echo installing...
	@g++ cmain.cpp -I /usr/include/arpa -I /usr/include/netinet -o mac2ip
	@echo Success!
	@echo Type ./mac2ip help for show mac2ip help.
