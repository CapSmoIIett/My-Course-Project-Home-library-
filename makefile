all:
	hpp2plantuml -i act.h -i addbwindow.h -i artbooks.h -i books.h -i excep.h -i filestream.h -i magazines.h -i mwindow.h -i newspapers.h -i reading.h -i scbooks.h -i tempedition.h -i tree.h -i windowab.h -i windowmag.h -i windownews.h -i windowsb.h  -o diagramclass.puml

	hpp2plantuml -i filestream.h  -i tree.h -o diagram1.puml 
	hpp2plantuml -i addbwindow.h -i mwindow.h -i windowab.h -i windowmag.h -i windownews.h -i windowsb.h  -o diagram2.puml
	hpp2plantuml -i artbooks.h -i books.h -i magazines.h -i newspapers.h -i reading.h -i scbooks.h -i tempedition.h -o diagram3.puml
	hpp2plantuml -i excep.h -o diagram4.puml
	hpp2plantuml -i act.h -o diagram5.puml 