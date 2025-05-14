# Target binary
all: $(BINARY)

# Linking objects into final binary
$(BINARY): main.o gpio.o clock.o usart.o startup.o system_stm32f4xx.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ -o $@

# Compile source files into object files
main.o: main.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $<

gpio.o: gpio.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $<

clock.o: clock.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $<

usart.o: usart.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $<

startup.o: ../../startup.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $<

system_stm32f4xx.o: system_stm32f4xx.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $<
