CC = gcc
CFLAGS = -Wall
LDFLAGS = -lglut -lGLU -lGL -lm
OBJFILES = models.o simulation.o
TARGET = Simulation

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~