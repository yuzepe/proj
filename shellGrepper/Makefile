NAMESLINKS := $(NAMES) $(LINKS)
LINKS := links.txt
NAMES := names.txt
# SITENAMES = $(shell cat names.txt)
# SITES = $(addsuffix .html,$(SITENAMES))
# SITES = $(addprefix sites/,$(SITENAMES))
SITES := $(wildcard src/*.html)
MATERIALS := materials.dat

default: help

all: grepMaterials

grepMaterials: $(MATERIALS)

loadSites: $(SITES)

loadList: $(NAMESLINKS)

$(MATERIALS): $(SITES)
	./grepMaterials.sh

$(SITES): $(NAMESLINKS)
	./wgetSites.sh

$(NAMESLINKS):
	./wgetLinks.sh

clean:
	rm -f $(NAMESLINKS) $(SITES)

help:
	@echo all		get all Files.
	@echo grepMaterials	create Materials.dat.
	@echo loadSites		download .html Files.
	@echo loadList		create list of Sites.
