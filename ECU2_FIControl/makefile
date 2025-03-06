.PHONY: all clean

all:
	$(MAKE) -C ASW
	$(MAKE) -C BSW
	$(MAKE) -C RTE

clean:
	$(MAKE) -C ASW clean
	$(MAKE) -C BSW clean
	$(MAKE) -C RTE clean
	@if exist "obj" rmdir /S /Q "obj"
	@if exist "bin" rmdir /S /Q "bin"
