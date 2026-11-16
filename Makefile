# Имя итоговой программы
TARGET = program

# Из каких объектных файлов она состоит
OBJS = main.o array.o bubblesort.o vst.o merge.o

# Правило сборки: make сама скомпилирует .c файлы, нам нужно их только связать (залинковать)
$(TARGET): $(OBJS)
	$(CC)  $(OBJS) -o $(TARGET)

# Очистка проекта
clean:
	rm -f $(OBJS) $(TARGET)
