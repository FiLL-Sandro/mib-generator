
test-status:
	@echo "Project status checking..."
	@if [ ! -e out ] || [ ! -d out ]; then \
	  echo "cannot handle the 'out' directory -- run 'make prepare'" ; \
	  exit 1 ; \
	fi

prepare:
	cmake -S . -B ./out

build: test-status
	@echo "Building..."
	cd out ; \
	  make

clean: test-status
	@echo "Cleaning..."
	cd out ; \
	  make clean

distclean: clean
	@echo "Distcleaning..."
	rm -frv out
