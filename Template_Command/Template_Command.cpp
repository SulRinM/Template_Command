/*
Задание 1. Паттерн «Команда»
Пишем команды для системы логирования.

В задании нужно реализовать наследников класса:

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};
таким образом, чтобы один наследник печатал сообщение message в консоль, 
а другой умел печатать сообщение в файл, по указанному пути.

Далее нужно реализовать функцию: oid print(LogCommand&);, которая будет выполнять команды
*/

#include <iostream>
#include <fstream>


class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};


class ConsoleLogCommand : public LogCommand {
public:
    void print(const std::string& message) override {
        std::cout << "ConsoleLogger: " << message << std::endl;
    }
};

class FileLogCommand : public LogCommand {
private:
    std::string file_path_;
public:
     FileLogCommand(const std::string& file_path) : file_path_(file_path) {}

     void print(const std::string& message) override {
         std::ofstream file(file_path_, std::ios::app);
         file << message << std::endl;
         file.close();
     }
};


void print(LogCommand& command, const std::string& message) {
    command.print(message);
}



int main() {
    ConsoleLogCommand console_command;
    FileLogCommand file_command("log.txt");

    print(console_command, "This is a console log message!");
    print(file_command, "This is a file log message!");

    return 0;
}




