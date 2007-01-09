
doxygen_configfile = Doxyfile
web_path_reference = /home/groups/g/gt/gtkmm/htdocs/gtkmm2DONTUPLOADTHIS/reference

EXTRA_DIST	= README $(doxygen_configfile)


libgdamm-reference: $(doxygen_configfile)
	doxygen $(doxygen_configfile)

libgdamm-reference-html: libgdamm-reference

libgdamm-reference-html.tar.gz: libgdamm-reference-html
	tar -cf - $< | gzip > $@


post-html: libgdamm-reference
	(cd html && tar -cf - *.html *.gif *.css | gzip -3 | \
	 ssh $$SSH_OPT $$USER@gtkmm.sourceforge.net "cd $(web_path_reference)/html ; gunzip | tar -xvf - ; chmod a+r,g+w * ; chgrp gtkmm *")


all-local: libgdamm-reference

clean-local:
	-rm -rf html
	-rm -f libgdamm-reference-html.tar.gz

