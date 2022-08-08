LATEXCMD = pdflatex -shell-escape -output-directory build/
export TEXINPUTS=.:content/tex/:
export max_print_line = 1048576

help:
	@echo "This makefile builds the hackpack"
	@echo ""
	@echo "Available commands are:"
	@echo "	make fast		- to build hackpack, quickly (only runs LaTeX once)"
	@echo "	make hackpack		- to build hackpack"
	@echo "	make snippets	- to build VSCode snippets"
	@echo "	make clean		- to clean up the build process"
	@echo "	make veryclean		- to clean up and remove hackpack.pdf"
	@echo "	make test		- to run all the stress tests in stress-tests/"
	@echo "	make test-compiles	- to test compiling all headers"
	@echo "	make help		- to show this information"
	@echo "	make showexcluded	- to show files that are not included in the doc"
	@echo ""
	@echo "For more information see the file 'doc/README'"

fast: | build
	$(LATEXCMD) content/hackpack.tex </dev/null
	cp build/hackpack.pdf hackpack.pdf

hackpack: test-session.pdf | build 
	$(LATEXCMD) content/hackpack.tex && $(LATEXCMD) content/hackpack.tex
	cp build/hackpack.pdf hackpack.pdf

clean:
	cd build && rm -f kactl.aux kactl.log kactl.tmp kactl.toc hackpack.pdf kactl.ptc

veryclean: clean
	rm -f hackpack.pdf test-session.pdf

.PHONY: help fast hackpack clean veryclean format snippets

build:
	mkdir -p build/

test:
	./doc/scripts/run-all.sh .

test-compiles:
	./doc/scripts/compile-all.sh .

test-session.pdf: content/test-session/test-session.tex content/test-session/chapter.tex | build
	$(LATEXCMD) content/test-session/test-session.tex
	cp build/test-session.pdf test-session.pdf

showexcluded: build
	grep -RoPh '^\s*\\kactlimport{\K.*' content/ | sed 's/.$$//' > build/headers_included
	find ./content -name "*.h" -o -name "*.py" -o -name "*.java" | grep -vFf build/headers_included

format:
	bash ./doc/scripts/format-all.sh .

snippets:
	find content/ -type f -name "*.*" ! -name "*.tex" ! -path "*/tex/*" -print0 \
		| xargs -0 -n 1 -I{} sh -c \
			'python3 content/tex/preprocessor.py -s -i {} > /dev/null || exit 0'
	python3 content/tex/snippets.py
